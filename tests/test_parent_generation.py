"""Tests for the parent generation type"""
import mock
from Generation import ParentGeneration, Individual


def test_it_should_copy_public_fields_from_generation():
    generation = mock.Mock(best='foo', population=[1,3,4,7], size=4, sum_fitness=10, mean_fitness=2.5)
    pg = ParentGeneration(generation)
    assert pg.best == 'foo'
    assert pg.size == 4
    assert pg.sum_fitness == 10
    assert pg.mean_fitness == 2.5
    assert pg.population == (1, 3, 4, 7)


def test_select_parent_gene_should_chose_best_more_often():
    population = [
        Individual('a', 5),
        Individual('b', 1),
        Individual('c', 3),
        Individual('d', 1)
    ]
    best = population[0]
    generation = mock.Mock(best=best, population=population, size=len(population), sum_fitness=10, mean_fitness=2.5)
    pg = ParentGeneration(generation)
    # Test by repetition
    scores = {
        'a': 0,
        'b': 0,
        'c': 0,
        'd': 0
    }
    # in 100 times, the number of 'a' selections should be greater than the others
    for _ in range(100):
        selection = pg.select_parent_genes()
        scores[selection] += 1
    assert scores['a'] > 0
    assert scores['a'] >= scores['c']
    assert scores['a'] >= scores['d']
    assert scores['a'] >= scores['b']
    assert scores['c'] > 0
    assert scores['c'] >= scores['b']
    assert scores['c'] >= scores['d']

