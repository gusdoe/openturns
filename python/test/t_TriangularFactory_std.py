#! /usr/bin/env python

from __future__ import print_function
from openturns import *

TESTPREAMBLE()
RandomGenerator.SetSeed(0)

try:
    distribution = Triangular(1.0, 2.5, 4.0)
    size = 10000
    sample = distribution.getSample(size)
    factory = TriangularFactory()
    estimatedDistribution = factory.build(sample)
    print("distribution=", repr(distribution))
    print("Estimated distribution=", repr(estimatedDistribution))
    estimatedDistribution = factory.build()
    print("Default distribution=", estimatedDistribution)
    estimatedDistribution = factory.build(
        distribution.getParameters())
    print("Distribution from parameters=", estimatedDistribution)
    estimatedTriangular = factory.buildAsTriangular(sample)
    print("Triangular          =", distribution)
    print("Estimated triangular=", estimatedTriangular)
    estimatedTriangular = factory.buildAsTriangular()
    print("Default triangular=", estimatedTriangular)
    estimatedTriangular = factory.buildAsTriangular(
        distribution.getParameters())
    print("Triangular from parameters=", estimatedTriangular)

except:
    import sys
    print("t_TriangularFactory_std.py", sys.exc_info()[0], sys.exc_info()[1])
