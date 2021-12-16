#include "cis27ChanceVPolyTerm.h"

TPolyTermNodePtrChanceV createPolyTermNodeChanceV(TPolyTermPtrChanceV polyTermCV)
{
	TPolyTermNodePtrChanceV newPolyTermNode = malloc(sizeof(TPolyTermNodeChanceV));

	newPolyTermNode->termCV = polyTermCV;
	newPolyTermNode->nextCV = NULL;

	return newPolyTermNode;
}

TPolyTermNodePtrChanceV deletePolyTermNodeChanceV(TPolyTermNodePtrChanceV* polyTermNodeCV)
{
	TPolyTermNodePtrChanceV nextCV = (*polyTermNodeCV)->nextCV;

	deletePolyTermChanceV(&((*polyTermNodeCV)->termCV));
	free(*polyTermNodeCV);
	(*polyTermNodeCV) = NULL;

	return nextCV;
}

TPolyTermPtrChanceV createPolyTermChanceV(int expoCV, TFractionPtrChanceV fractionCV)
{
	TPolyTermPtrChanceV newPolyTerm = malloc(sizeof(TPolyTermChanceV));

	newPolyTerm->expoCV = expoCV;
	newPolyTerm->fractionCV = fractionCV;

	return newPolyTerm;
}

void deletePolyTermChanceV(TPolyTermPtrChanceV* polyTermCV)
{
	deleteFractionChanceV(&((*polyTermCV)->fractionCV));
	free(*polyTermCV);
	(*polyTermCV) = NULL;
}
