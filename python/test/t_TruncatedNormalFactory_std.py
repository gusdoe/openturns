#! /usr/bin/env python

from __future__ import print_function
import openturns as ot

ot.TESTPREAMBLE()
ot.RandomGenerator.SetSeed(0)


mu = [0.0] * 4
sigma = [1.0] * 4
a = [-4., -1., 1., 3.]
b = [4., 4., 2., 6.]

ot.PlatformInfo.SetNumericalPrecision(2)
for i in range(4):
    distribution = ot.TruncatedNormal(mu[i], sigma[i], a[i], b[i])
    size = 10000
    sample = distribution.getSample(size)
    factory = ot.TruncatedNormalFactory()
    estimatedDistribution = factory.build(sample)
    print("distribution=", repr(distribution))
    print("Estimated distribution=", repr(estimatedDistribution))
    estimatedDistribution = factory.build()
    print("Default distribution=", estimatedDistribution)
    estimatedDistribution = factory.build(
        distribution.getParameters())
    print("Distribution from parameters=", estimatedDistribution)
    estimatedTruncatedNormal = factory.buildAsTruncatedNormal(sample)
    print("TruncatedNormal          =", distribution)
    print("Estimated TruncatedNormal=", estimatedTruncatedNormal)
    estimatedTruncatedNormal = factory.buildAsTruncatedNormal()
    print("Default TruncatedNormal=", estimatedTruncatedNormal)
    estimatedTruncatedNormal = factory.buildAsTruncatedNormal(
        distribution.getParameters())
    print("TruncatedNormal from parameters=", estimatedTruncatedNormal)
