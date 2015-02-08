import logging
from random import randint


class Individual(object):
    def __init__(self, genes):
        self.genes = genes
        self.fitness = 0

    def __str__(self):
        return "%s:%d" % (repr(self.genes), self.fitness or -1)


class ParentGeneration(object):
    """Immutable version of a generation.
    The individuals are fixed.
    The info stays."""
    def __init__(self, generation):
        self._best = generation._best
        self._population = tuple(generation._population)
        self._size = generation._size
        self.sumFitness = generation.sum_fitness
        self.meanFitness = generation.mean_fitness

    def selectParentGenes(self):
        """Return parent genes from pool. Weighted by fitness"""
        roulette = randint(0, self.sumFitness)
        accum = 0
        for i in self._population:
            newAccum = accum + i.fitness
            if accum <= roulette <= newAccum:
                return i.genes
            accum = newAccum
        return self._population[-1:].genes

class Generation(object):
    def __init__(self, size, gene_builder):
        self._best = None
        self._size = size
        self._population = []
        self._gb = gene_builder

    def from_random(self):
        """Populate the generation randomly"""
        logging.info("Creating random population with size %d", self._size)
        self._population = [Individual(self._gb.randomIndividual()) for i in range(self._size)]
        return self

    def from_previous_generation(self, previous):
        parents = ParentGeneration(previous)
        self._population = [Individual(self._gb.fromParents(parents.selectParentGenes(), parents.selectParentGenes()))
                            for _ in range(self._size)]
        self._best = previous._best
        return self

    def log(self):
        """Log the whole population"""
        [logging.debug(unicode(item)) for item in self._population]

    def test(self, maze):
        """Test all individuals in the generation against the maze"""
        for individual in self._population:
            individual.fitness = maze.testIndividual(individual.genes)
            logging.info("Tested .. Fitness was %d", individual.fitness)
            if self._best is None or (individual.fitness > self._best.fitness):
                self._best = individual

    @property
    def best_individual(self):
        return self._best

    @property
    def best_fitness(self):
        """Get best fitness"""
        return self._best.fitness

    @property
    def sum_fitness(self):
        return sum([i.fitness for i in self._population])

    @property
    def mean_fitness(self):
        """Get the average fitness"""
        return self.sum_fitness/self._size
