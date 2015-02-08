import logging
from random import randint


class Individual(object):
    __slots__ = ['genes', 'fitness']

    def __init__(self, genes, fitness=0):
        self.genes = genes
        self.fitness = fitness

    def __str__(self):
        return "%s:%d" % (repr(self.genes), self.fitness or -1)


class ParentGeneration(object):
    """Immutable version of a generation.
    The individuals are fixed.
    The info stays."""
    def __init__(self, generation):
        self.best = generation.best
        self.population = tuple(generation.population)
        self.size = generation.size
        self.sum_fitness = generation.sum_fitness
        self.mean_fitness = generation.mean_fitness

    def select_parent_genes(self, random_int=randint):
        """Return parent genes from pool. Weighted by fitness"""
        roulette = random_int(0, self.sum_fitness)
        accum = 0
        for i in self.population:
            newAccum = accum + i.fitness
            if accum <= roulette <= newAccum:
                return i.genes
            accum = newAccum
        return self.population[-1:].genes


class Generation(object):
    def __init__(self, size, gene_builder):
        self.best = None
        self.size = size
        self.population = []
        self._gb = gene_builder

    def from_random(self):
        """Populate the generation randomly"""
        logging.info("Creating random population with size %d", self.size)
        self.population = [Individual(self._gb.randomIndividual()) for _ in range(self.size)]
        return self

    def from_previous_generation(self, previous):
        parents = ParentGeneration(previous)
        self.population = [Individual(self._gb.fromParents(parents.select_parent_genes(), parents.select_parent_genes()))
                           for _ in range(self.size)]
        self.best = previous.best_fitness
        return self

    def log(self):
        """Log the whole population"""
        [logging.debug(unicode(item)) for item in self.population]

    def test(self, maze):
        """Test all individuals in the generation against the maze"""
        for individual in self.population:
            individual.fitness = maze.testIndividual(individual.genes)
            logging.info("Tested .. Fitness was %d", individual.fitness)
            if self.best is None or (individual.fitness > self.best.fitness):
                self.best = individual

    @property
    def best_fitness(self):
        """Get best fitness"""
        return self.best.fitness

    @property
    def sum_fitness(self):
        return sum([i.fitness for i in self.population])

    @property
    def mean_fitness(self):
        """Get the average fitness"""
        return self.sum_fitness/self.size
