import logging
from random import randint

__author__ = 'danny'

class Individual(object):
    def __init__(self, genes):
        self.genes = genes
        self.fitness = None

    def __unicode__(self):
        return "%s:%d" % (repr(self.genes), self.fitness or -1)

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

    def _selectMate(self):
        roulette = randint(0, self.sumFitness)
        accum = 0
        for i in self._population:
            if accum <= roulette <= i.fitness + accum:
                return i
            accum += i.fitness
        return self._population[-1:]

    def fromPreviousGeneration(self, previous):
        self._population = [Individual(self._gb.fromParents(previous._selectMate().genes, previous._selectMate().genes)) for i in range(self._size)]
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
            if not self._best or (individual.fitness > self._best.fitness):
                self._best = individual

    @property
    def bestFitness(self):
        """Get best fitness"""
        return self._best.fitness

    @property
    def sumFitness(self):
        return sum([i.fitness or 0 for i in self._population])

    @property
    def meanFitness(self):
        """Get the average fitness"""
        return self.sumFitness/self._size