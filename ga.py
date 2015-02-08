"""Gamaze simulation"""
import logging
import random
import cProfile

from Generation import Generation
from GeneBuilder import GeneBuilder
from maze import Maze


def crossover_aaaabbbb(parent_a, parent_b):
    return parent_a[0:4] + parent_b[4:8]


def crossover_alternate(parent_a, parent_b):
    """ABABABAB crossover"""
    return [g[i%2] for i, g in enumerate(zip(parent_a, parent_b))]


def crossover_random(parent_a, parent_b):
    """random crossover"""
    return [random.choice(g) for g in zip(parent_a, parent_b)]


def crossover_aabbbbbb(parent_a, parent_b):
    return parent_a[0:2] + parent_b[2:8]


class Simulation(object):
    """The overall simulation."""
    def __init__(self, size = 100):
        logging.info("Creating maze environment")
        self._maze = Maze().withDecisionReward(1)\
            .withGoalReward(20)\
            .withRevisitPenalty(2)\
            .withOutOfBoundsPenalty(2)

        logging.info("Creating gene builder")
        self._gb = GeneBuilder().withGeneset(self._maze.genes).withLength(8)\
            .withMutation(0.03)\
            .withCrossover(crossover_random)

        self._population_size = size
        self._population = None
        self._new_population = Generation(self._population_size, self._gb).from_random()
        self._new_population.log()

        self.generation = 0

    def _make_new_generation(self):
        self._new_population = Generation(self._population_size, self._gb).from_previous_generation(self._population)
        self.generation += 1

    @property
    def best(self):
        return self._population.best_fitness

    @property
    def best_genes(self):
        return self._population.best_individual

    @property
    def mean(self):
        return self._population.mean_fitness

    def step_generation(self):
        self._population = self._new_population
        logging.info("Testing..")
        self._population.test(self._maze)
        logging.info("Breeding...")
        self._make_new_generation()


def main():
    #random.seed(40)
    random.seed()
    logging.basicConfig(level=logging.WARN)
    sim = Simulation(200)
    to_step = 100
    for i in range(to_step):
        sim.step_generation()
        print ("%d-> best: %d, mean: %d" % (sim.generation, sim.best, sim.mean))
    print(str(sim.best_genes))


if "__main__" == __name__:
    cProfile.run("main()")