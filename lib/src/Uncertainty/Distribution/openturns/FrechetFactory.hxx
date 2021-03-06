//                                               -*- C++ -*-
/**
 *  @brief Factory for Frechet distribution
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
#ifndef OPENTURNS_FRECHETFACTORY_HXX
#define OPENTURNS_FRECHETFACTORY_HXX

#include "openturns/OTprivate.hxx"
#include "openturns/DistributionFactoryImplementation.hxx"
#include "openturns/Frechet.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class FrechetFactory
 */
class OT_API FrechetFactory
  : public DistributionFactoryImplementation
{
  CLASSNAME
public:

  /** Default constructor */
  FrechetFactory();

  /** Virtual constructor */
  virtual FrechetFactory * clone() const;

  /* Here is the interface that all derived class must implement */
  using DistributionFactoryImplementation::build;

  Implementation build(const Sample & sample) const;
  Implementation build(const Point & parameters) const;
  Implementation build() const;
  Frechet buildAsFrechet(const Sample & sample) const;
  Frechet buildAsFrechet(const Point & parameters) const;
  Frechet buildAsFrechet() const;

  using DistributionFactoryImplementation::buildEstimator;  
  DistributionFactoryResult buildEstimator(const Sample & sample) const;

}; /* class FrechetFactory */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_FRECHETFACTORY_HXX */
