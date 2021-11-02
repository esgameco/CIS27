#include "cis27ChanceVFractionList.h"

TFractionNodePtrChanceV createNodeChanceV(TFractionPtrChanceV fraction)
{
	TFractionNodePtrChanceV newNodeCV = malloc(sizeof(TFractionNodeChanceV));
	newNodeCV->fractionCV = fraction;
	newNodeCV->nextCV = NULL;
	return newNodeCV;
}

void deleteNodeChanceV(TFractionNodePtrChanceV* nodeCV)
{
	deleteFractionChanceV(&((*nodeCV)->fractionCV));
	(*nodeCV)->nextCV = NULL;
	free(*nodeCV);
	(*nodeCV) = NULL;
}

void deleteAllNodesChanceV(TFractionNodePtrChanceV* nodeCV)
{
	if (!(*nodeCV))
		return;
	if (!(*nodeCV)->fractionCV)
		return;

	if ((*nodeCV)->nextCV)
		deleteAllNodesChanceV(&(*nodeCV)->nextCV);
	
	deleteNodeChanceV(nodeCV);
}

void addNodeChanceV(TFractionNodePtrChanceV nodeCV, TFractionPtrChanceV fractionCV)
{
	nodeCV->nextCV = createNodeChanceV(fractionCV);
}

void updateNodeChanceV(int nodeNumCV, TFractionNodePtrChanceV nodeCV, TFractionPtrChanceV fractionCV)
{
	if (nodeNumCV > 0)
	{
		updateNodeChanceV(nodeNumCV - 1, nodeCV->nextCV, fractionCV);
		return;
	}
	deleteFractionChanceV(&nodeCV->fractionCV);
	nodeCV->fractionCV = fractionCV;
}
