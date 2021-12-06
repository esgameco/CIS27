#include "cis27ChanceVPolyTerm.h"

TPolyTermPtrChanceV createPolyTermChanceV(int expoCV, TFractionPtrChanceV fractionCV)
{
	TPolyTermPtrChanceV newPolyTerm = malloc(sizeof(TPolyTermChanceV));

	newPolyTerm->expoCV = expoCV;
	newPolyTerm->fractionCV = fractionCV;
	newPolyTerm->nextCV = NULL;

	return newPolyTerm;
}

TPolyTermPtrChanceV deletePolyTermChanceV(TPolyTermPtrChanceV* polyTermCV)
{
	TPolyTermPtrChanceV nextCV = (*polyTermCV)->nextCV;

	deleteFractionChanceV(&((*polyTermCV)->fractionCV));
	free(*polyTermCV);
	(*polyTermCV) = NULL;

	return nextCV;
}