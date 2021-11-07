#include "cis27ChanceVFraction.h"

#ifndef FRACTION_NODE
#ifdef FRACTION
#define FRACTION_NODE

typedef struct FractionNodeChanceV TFractionNodeChanceV;
typedef struct FractionNodeChanceV* TFractionNodePtrChanceV;

struct FractionNodeChanceV
{
	TFractionPtrChanceV fractionCV;
	TFractionNodePtrChanceV nextCV;
};

TFractionNodePtrChanceV createNodeChanceV(TFractionPtrChanceV fraction);
void deleteNodeChanceV(TFractionNodePtrChanceV* nodeCV);
void deleteAllNodesChanceV(TFractionNodePtrChanceV* nodeCV);
void addNodeChanceV(TFractionNodePtrChanceV nodeCV, TFractionPtrChanceV fractionCV);
void updateNodeChanceV(int nodeNumCV, TFractionNodePtrChanceV nodeCV, TFractionPtrChanceV fractionCV);

#endif
#endif