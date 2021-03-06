//                                               -*- C++ -*-
/**
 *  @brief A class which implements the SpectralGaussianProcess process
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
#ifndef OPENTURNS_SPECTRALGAUSSIANPROCESS_HXX
#define OPENTURNS_SPECTRALGAUSSIANPROCESS_HXX

#include "openturns/ProcessImplementation.hxx"
#include "openturns/SpectralModel.hxx"
#include "openturns/SecondOrderModel.hxx"
#include "openturns/TriangularComplexMatrix.hxx"
#include "openturns/PersistentCollection.hxx"
#include "openturns/FFT.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class SpectralGaussianProcess
 *
 * The implementation of the Gaussian process class
 * in spectral domain
 */
class OT_API SpectralGaussianProcess
  : public ProcessImplementation
{
  CLASSNAME

public:

  /** Some typedefs to ease reading */
  typedef PersistentCollection<TriangularComplexMatrix>    TriangularComplexMatrixPersistentCollection;
  typedef PersistentCollection<Complex>           PersistentComplexCollection;
  typedef Collection<Complex>                     ComplexCollection;

  /** Default constructor */
  SpectralGaussianProcess();

  /** Standard constructor  - The timeGrid imposes the frequencies values*/
  SpectralGaussianProcess(const SecondOrderModel & model,
                          const RegularGrid & grid);

  /** Standard constructor with spectralModel - The timeGrid imposes the frequencies values*/
  SpectralGaussianProcess(const SpectralModel & spectralModel,
                          const RegularGrid & grid);

  /** Specific constructor  - The frequency parameters impose the time grid */
  SpectralGaussianProcess(const SecondOrderModel & model,
                          const Scalar maximalFrequency,
                          const UnsignedInteger nFrequency);

  /** Specific constructor  - The frequency parameters impose the time grid */
  SpectralGaussianProcess(const SpectralModel & spectralModel,
                          const Scalar maximalFrequency,
                          const UnsignedInteger nFrequency);

  /** Virtual constructor */
  virtual SpectralGaussianProcess * clone() const;

  /** String converter */
  String __repr__() const;

  /** String converter  - pretty print */
  String __str__(const String & offset = "") const;

  /** Realization accessor */
  Field getRealization() const;

  /** Frequency grid accessor, covering both the negative and the positive axes */
  RegularGrid getFrequencyGrid() const;

  /** Maximal frequency accessor */
  Scalar getMaximalFrequency() const;

  /** Number of frequency steps accessor */
  UnsignedInteger getNFrequency() const;

  /** Frequency step accessor */
  Scalar getFrequencyStep() const;

  /** Spectral model accessor */
  SpectralModel getSpectralModel() const;

  /** Set TimeGrid */
  void setTimeGrid(const RegularGrid & timeGrid);

  /** FFT algorithm accessors */
  FFT getFFTAlgorithm() const;
  void setFFTAlgorithm(const FFT & fft);

  /** Check if the process is stationary */
  Bool isStationary() const;

  /** Check if the process is Normal */
  Bool isNormal() const;

  /** Adapt a time grid in order to have a power of two time stamps. Both the starting point and the end point are preserved. */
  static RegularGrid AdaptGrid(const RegularGrid & grid);

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

  /** Initialization of the process */
  void initialize() const;

  /** Compute the time grid associated to the frequency grid */
  void computeTimeGrid();

  /** Set the alpha vector */
  void computeAlpha();

  /** Get the Cholesky factor of the kth DSP matrix from cache or computed on the fly */
  TriangularComplexMatrix getCholeskyFactor(const UnsignedInteger k) const;

  /** Compute the Cholesky factor of the kth DSP matrix */
  TriangularComplexMatrix computeCholeskyFactor(const UnsignedInteger k) const;

private:

  /** Spectral model associated to the process */
  SpectralModel spectralModel_;

  /** Maximal frequency */
  Scalar maximalFrequency_;

  /** Number of frequencies on the positive axis */
  UnsignedInteger nFrequency_;

  /** Frequency step */
  Scalar frequencyStep_;

  /** Cholesky factor  */
  mutable TriangularComplexMatrixPersistentCollection choleskyFactorsCache_;

  /** Cache size */
  mutable UnsignedInteger cacheSize_;

  /** alpha vector - scale factor */
  PersistentComplexCollection alpha_;

  /** FFT Algorithm */
  FFT fftAlgorithm_;

}; /* class SpectralGaussianProcess */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_SPECTRALGAUSSIANPROCESS_HXX */
