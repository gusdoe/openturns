// SWIG file LinearCombinationEvaluationImplementation.i

OTAutodoc(LinearCombinationEvaluationImplementation)

%{
#include "LinearCombinationEvaluationImplementation.hxx"
%}

%include LinearCombinationEvaluationImplementation.hxx

namespace OT { %extend LinearCombinationEvaluationImplementation { LinearCombinationEvaluationImplementation(const LinearCombinationEvaluationImplementation & other) { return new OT::LinearCombinationEvaluationImplementation(other); } } }
