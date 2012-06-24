"""Individual running about in the maze."""
from random import randint, choice
import logging

__author__ = 'danny'

class GeneBuilder(object):
    """Build genes with this:
    >>> genes = ['a', 'b', 'c', 'd']
    >>> def crossover_AAAABBBB(parentA, parentB):
    ...   return [parentA[0:4] + parentB[4:8]]
    ...
    >>> gb = GeneBuilder().withGeneset(genes).withLength(8)\
    ...        .withCrossover(crossover_AAAABBBB)\
    ...        .withMutationOnceIn(10)
    >>> i1 = gb.randomIndividual()
    >>> i2 = gb.randomIndividual()
    >>> i3 = gb.fromParents(i1, i2)
    """

    @staticmethod
    def CrossOver_random(parentA, parentB):
        """Entirely random selection of parents genotypes"""
        combined = zip(parentA, parentB)
        return [item[randint(0, 1)] for item in combined]

    def __init__(self):
        self._geneset = None
        self._length = 0
        self._crossover_fn = GeneBuilder.CrossOver_random
        self._mutationRate = 10

    def withGeneset(self, genes):
        """This geneset will have the current types of genes.
        Any iterable here please"""
        self._geneset = genes
        return self

    def withLength(self, length):
        """This is the length of the individual - the number of genes"""
        self._length = length
        return self

    def _randomGene(self):
        return choice(self._geneset)

    def randomIndividual(self):
        """Build the genes for a random individual.
        Returns a tuple of length with random genes form the geneset"""
        return tuple(self._randomGene() for i in range(self._length))

    def withCrossover(self, fn):
        """Set a crossover function. Must be a function that takes two iterables, and returns
        an iterable."""
        self._crossover_fn = fn
        return self

    def withMutationOnceIn(self, mutation_rate):
        """Set the mutation rate to 1 in mutation_rate"""
        self._mutationRate = mutation_rate
        return self

    def _copyWithMutate(self, toCopy):
        """Copy with potential mutation"""
        newGenes = []
        logging.debug("Copying genes %s", repr(toCopy))
        for gene in toCopy:
            if randint(0, self._mutationRate) is 0:
                logging.info("Mutation!")
                newGenes += self._randomGene()
            else:
                newGenes += gene
        logging.debug("Output was %s", repr(newGenes))
        return newGenes

    def fromParents(self, parentA, parentB):
        """Return a new tuple of genes based on breeding the parents and potential mutation."""
        return tuple(self._copyWithMutate(self._crossover_fn(parentA, parentB)))

