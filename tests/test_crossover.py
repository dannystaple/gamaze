"""Tests for the different types of crossover algorithm"""
from ga import crossover_aaaabbbb, crossover_alternate, crossover_aabbbbbb


def test_aaaabbbb():
    parent1 = "a" * 8
    parent2 = "b" * 8
    result = crossover_aaaabbbb(parent1, parent2)
    assert result == "aaaabbbb"


def test_alternate():
    parent1 = "a" * 8
    parent2 = "b" * 8
    result = crossover_alternate(parent1, parent2)
    assert result == ["a", "b"] * 4


def test_aabbbbbb():
    parent1 = "a" * 8
    parent2 = "b" * 8
    result = crossover_aabbbbbb(parent1, parent2)
    assert result == "aabbbbbb"


