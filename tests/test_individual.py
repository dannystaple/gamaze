"""Tests for an individual in the simulation"""
from Generation import Individual


def test_it_can_store_genes():
    i = Individual('abcd')
    assert i.genes == 'abcd'


def test_if_can_store_fitness():
    i = Individual('abcd')
    assert i.fitness == 0
    i.fitness = 5
    assert i.fitness == 5
