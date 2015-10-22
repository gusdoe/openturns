//                                               -*- C++ -*-
/**
 *  @brief The test file of class Skellam for standard methods
 *
 *  Copyright 2005-2015 Airbus-EDF-IMACS-Phimeca
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
#include "OT.hxx"
#include "OTtestcode.hxx"

using namespace OT;
using namespace OT::Test;

int main(int argc, char *argv[])
{
  TESTPREAMBLE;
  OStream fullprint(std::cout);
  setRandomGenerator();

  try
  {
    Skellam distribution(10.0, 5.0);
    UnsignedInteger size(10000);
    NumericalSample sample(distribution.getSample(size));
    SkellamFactory factory;
    CovarianceMatrix covariance;
    // Distribution estimatedDistribution(factory.build(sample, covariance));
    Distribution estimatedDistribution(factory.build(sample));
    fullprint << "Distribution          =" << distribution << std::endl;
    fullprint << "Estimated distribution=" << estimatedDistribution << std::endl;
    // fullprint << "Covariance=" << covariance << std::endl;
    estimatedDistribution = factory.build();
    fullprint << "Default distribution=" << estimatedDistribution << std::endl;
    estimatedDistribution = factory.build(distribution.getParameters());
    fullprint << "Distribution from parameters=" << estimatedDistribution << std::endl;
    Skellam estimatedSkellam(factory.buildAsSkellam(sample));
    fullprint << "Skellam          =" << distribution << std::endl;
    fullprint << "Estimated skellam=" << estimatedSkellam << std::endl;
    estimatedSkellam = factory.buildAsSkellam();
    fullprint << "Default skellam=" << estimatedSkellam << std::endl;
    estimatedSkellam = factory.buildAsSkellam(distribution.getParameters());
    fullprint << "Skellam from parameters=" << estimatedSkellam << std::endl;
  }
  catch (TestFailed & ex)
  {
    std::cerr << ex << std::endl;
    return ExitCode::Error;
  }


  return ExitCode::Success;
}
