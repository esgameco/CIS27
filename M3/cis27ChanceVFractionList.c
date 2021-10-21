#include "cis27ChanceVFractionList.h"

struct FractionNodeCV* createNodeChanceV(struct FractionCV* fraction)
{
	struct FractionNodeCV* newNodeCV = malloc(sizeof(struct FractionNodeCV));
	newNodeCV->fractionCV = fraction;
	newNodeCV->nextCV = NULL;
	return newNodeCV;
}

void deleteNodeChanceV(struct FractionNodeCV** nodeCV)
{
	deleteFractionChanceV(&((*nodeCV)->fractionCV));
	(*nodeCV)->nextCV = NULL;
	free(*nodeCV);
	(*nodeCV) = NULL;
}

void deleteAllNodesChanceV(struct FractionNodeCV** nodeCV)
{
	if (!(*nodeCV))
		return;
	if (!(*nodeCV)->fractionCV)
		return;

	if ((*nodeCV)->nextCV)
		deleteAllNodesChanceV(&(*nodeCV)->nextCV);
	
	deleteNodeChanceV(nodeCV);
}

void addNodeChanceV(struct FractionNodeCV* nodeCV, struct FractionCV* fractionCV)
{
	nodeCV->nextCV = createNodeChanceV(fractionCV);
}

void updateNodeChanceV(int nodeNumCV, struct FractionNodeCV* nodeCV, struct FractionCV* fractionCV)
{
	if (nodeNumCV > 0)
	{
		updateNodeChanceV(nodeNumCV - 1, nodeCV->nextCV, fractionCV);
		return;
	}
	deleteFractionChanceV(&nodeCV->fractionCV);
	nodeCV->fractionCV = fractionCV;
}
