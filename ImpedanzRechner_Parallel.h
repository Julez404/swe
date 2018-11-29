#pragma once
#include "ImpedanzRechner.h"
#include "liste.h"

class ImpedanzRechner_Parallel :
	public ImpedanzRechner
{
public:
	ImpedanzRechner_Parallel();
	~ImpedanzRechner_Parallel();

	virtual CComplex berechneImpedanz(const CListe& _list, const double _f) const;
};

