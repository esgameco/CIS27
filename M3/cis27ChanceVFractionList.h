#include "cis27ChanceVFraction.h"

#ifndef FRACTION_NODE
#ifdef FRACTION
#define FRACTION_NODE

struct FractionNodeCV
{
	struct FractionCV* fractionCV;
	struct FractionNodeCV* nextCV;
};

struct FractionNodeCV* createNodeChanceV(struct FractionCV* fraction);
void deleteNodeChanceV(struct FractionNodeCV** nodeCV);
void deleteAllNodesChanceV(struct FractionNodeCV** nodeCV);
void addNodeChanceV(struct FractionNodeCV* nodeCV, struct FractionCV* fractionCV);
void updateNodeChanceV(int nodeNumCV, struct FractionNodeCV* nodeCV, struct FractionCV* fractionCV);

#endif
#endif