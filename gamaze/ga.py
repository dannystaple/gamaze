"""Gamaze simulation"""
import logging
import random
from gamaze.Generation import Generation

__author__ = 'danny'

from GeneBuilder import GeneBuilder
from maze import Maze

def crossover_AAAABBBB(parentA, parentB):
   return parentA[0:4] + parentB[4:8]

class Simulation(object):
    """The overall simulation."""
    def __init__(self, size = 100):
        logging.info("Creating maze environment")
        self._maze = Maze().withDecisionReward(2)\
            .withGoalReward(8)\
            .withRevisitPenalty(4)\
            .withOutOfBoundsPenalty(2)

        logging.info("Creating gene builder")
        self._gb = GeneBuilder().withGeneset(self._maze.genes).withLength(8)\
            .withMutationOnceIn(50)\
            .withCrossover(crossover_AAAABBBB)

        self._population_size = size
        self._population = None
        self._new_population = Generation(self._population_size, self._gb).fromRandom()
        self._new_population.log()

        self.generation = 0

    def _make_new_generation(self):
        self._new_population = Generation(self._population_size, self._gb).fromPreviousGeneration(self._population)
        self.generation += 1

    @property
    def best(self):
        return self._population.bestFitness

    @property
    def mean(self):
        return self._population.meanFitness

    def stepGeneration(self):
        self._population = self._new_population
        logging.info("Testing..")
        self._population.test(self._maze)
        logging.info("Breeding...")
        self._make_new_generation()

def main():
    random.seed()
    logging.basicConfig(level=logging.ERROR)
    sim = Simulation(100)
    toStep = 20
    for i in range(toStep):
        sim.stepGeneration()
        print ("%d-> best: %d, mean: %d" % (sim.generation, sim.best, sim.mean))

if "__main__" == __name__:
    main()