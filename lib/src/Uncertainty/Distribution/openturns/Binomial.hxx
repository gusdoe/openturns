//                                               -*- C++ -*-
/**
 *  @brief The Binomial distribution
 *
 *  Copyright 2005-2018 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_BINOMIAL_HXX
#define OPENTURNS_BINOMIAL_HXX

#include "openturns/OTprivate.hxx"
#include "openturns/DiscreteDistribution.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class Binomial
 *
 * The Binomial distribution.
 */
class OT_API Binomial
  : public DiscreteDistribution
{
  CLASSNAME
public:

  /** Default constructor */
  Binomial();

  /** Parameters constructor */
  Binomial(const UnsignedInteger n,
           const Scalar p);

  /** Comparison operator */
  Bool operator ==(const Binomial & other) const;
protected:
  Bool equals(const DistributionImplementation & other) const;
public:

  /** String converter */
  String __repr__() const;
  String __str__(const String & offset = "") const;

  /* Interface inherited from Distribution */

  /** Virtual constructor */
  virtual Binomial * clone() const;

  /** Get one realization of the distribution */
  Point getRealization() const;

  /** Get the PDF of the distribution */
  using DiscreteDistribution::computePDF;
  Scalar computePDF(const Point & point) const;

  /** Get the CDF of the distribution */
  using DiscreteDistribution::computeCDF;
  Scalar computeCDF(const Point & point) const;
  using DiscreteDistribution::computeComplementaryCDF;
  Scalar computeComplementaryCDF(const Point & point) const;

  /** Get the PDFGradient of the distribution */
  using DiscreteDistribution::computePDFGradient;
  Point computePDFGradient(const Point & point) const;

  /** Get the CDFGradient of the distribution */
  using DiscreteDistribution::computeCDFGradient;
  Point computeCDFGradient(const Point & point) const;

  /** Compute the characteristic function, i.e. phi(u) = E(exp(I*u*X)) */
  Complex computeCharacteristicFunction(const Scalar x) const;
  Complex computeLogCharacteristicFunction(const Scalar x) const;

  /** Compute the generating function, i.e. psi(z) = E(z^X) */
  Complex computeGeneratingFunction(const Complex & z) const;
  Complex computeLogGeneratingFunction(const Complex & z) const;

  /** Get the support of a discrete distribution that intersect a given interval */
  using DistributionImplementation::getSupport;
  Sample getSupport(const Interval & interval) const;

  /** Get the standard deviation of the distribution */
  Point getStandardDeviation() const;

  /** Get the skewness of the distribution */
  Point getSkewness() const;

  /** Get the kurtosis of the distribution */
  Point getKurtosis() const;

  /** Parameters value accessors */
  void setParameter(const Point & parameter);
  Point getParameter() const;

  /** Parameters description accessor */
  Description getParameterDescription() const;

  /** Check if the distribution is elliptical */
  Bool isElliptical() const;

  /* Interface specific to Binomial */

  /** P accessor */
  void setP(const Scalar p);
  Scalar getP() const;

  /** N accessor */
  void setN(const UnsignedInteger n);
  UnsignedInteger getN() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

private:

  /** Compute the mean of the distribution */
  void computeMean() const;

  /** Compute the covariance of the distribution */
  void computeCovariance() const;

  /** Get the quantile of the distribution */
  Scalar computeScalarQuantile(const Scalar prob,
                               const Bool tail = false) const;

  /** Compute the numerical range of the distribution given the parameters values */
  void computeRange();

  /** The maximum value of the Binomial distribution */
  UnsignedInteger n_;

  /** The probability parameter of the Binomial distribution */
  Scalar p_;

}; /* class Binomial */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_BINOMIAL_HXX */
