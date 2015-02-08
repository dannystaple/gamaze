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
        self.sumFitness = generation.sumFitness
        self.meanFitness = generation.meanFitness

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
    def __init__(self, size, geneBuilder):
        self._best = None
        self._size = size
        self._population = []
        self._gb = geneBuilder

    def fromRandom(self):
        """Populate the generation randomly"""
        logging.info("Creating random population with size %d", self._size)
        self._population = [Individual(self._gb.randomIndividual()) for i in range(self._size)]
        return self

    def fromPreviousGeneration(self, previous):
        parents = ParentGeneration(previous)
        self._population = [Individual(self._gb.fromParents(parents.selectParentGenes(), parents.selectParentGenes())) for i in range(self._size)]
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
    def best(self):
        return self._best

    @property
    def bestFitness(self):
        """Get best fitness"""
        return self._best.fitness

    @property
    def sumFitness(self):
        return sum([i.fitness for i in self._population])

    @property
    def meanFitness(self):
        """Get the average fitness"""
        return self.sumFitness/self._size