// SWIG file InverseBoxCoxEvaluationImplementation.i

OTAutodoc(InverseBoxCoxEvaluationImplementation)

%{
#include "InverseBoxCoxEvaluationImplementation.hxx"
%}

%include InverseBoxCoxEvaluationImplementation.hxx
namespace OT { %extend InverseBoxCoxEvaluationImplementation { InverseBoxCoxEvaluationImplementation(const InverseBoxCoxEvaluationImplementation & other) { return new OT::InverseBoxCoxEvaluationImplementation(other); } } }
