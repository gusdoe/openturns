//                                               -*- C++ -*-
/**
 *  @brief First order polynomial response surface by Taylor expansion
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
#ifndef OPENTURNS_LINEARTAYLOR_HXX
#define OPENTURNS_LINEARTAYLOR_HXX

#include "openturns/OTprivate.hxx"
#include "openturns/PersistentObject.hxx"
#include "openturns/Point.hxx"
#include "openturns/Matrix.hxx"
#include "openturns/Function.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class LinearTaylor
 *
 * The class describes the concept of linear taylor response surface
 */
class OT_API LinearTaylor
  : public PersistentObject
{
  CLASSNAME
public:



  /** Default constructor */
  LinearTaylor();

  /** Constructor with parameters */
  LinearTaylor(const Point & center,
               const Function & inputFunction);


  /** Virtual constructor */
  virtual LinearTaylor * clone() const;

  /** String converter */
  String __repr__() const;

  /** Response surface computation */
  void run();

  /** Center accessor */
  Point getCenter() const;

  /** Constant accessor */
  Point getConstant() const;

  /** Linear accessor */
  Matrix getLinear() const;

  /** Input function accessor */
  Function getInputFunction() const;

  /** Response surface accessor */
  Function getResponseSurface() const;

protected:

private:

  Point center_;
  Function inputFunction_;
  Function responseSurface_;
  Point constant_;
  Matrix linear_;

}; /* class LinearTaylor */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_LINEARTAYLOR_HXX */
