// SWIG file NoNumericalMathEvaluationImplementation.i

OTAutodoc(NoNumericalMathEvaluationImplementation)

%{
#include "NoNumericalMathEvaluationImplementation.hxx"
%}

%include NoNumericalMathEvaluationImplementation.hxx
namespace OT { %extend NoNumericalMathEvaluationImplementation { NoNumericalMathEvaluationImplementation(const NoNumericalMathEvaluationImplementation & other) { return new OT::NoNumericalMathEvaluationImplementation(other); } } }
