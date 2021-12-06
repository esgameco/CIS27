#include "cis27ChanceVPoly.h"

TPolyPtrChanceV createPolyChanceV(TPolyTermPtrChanceV polyTermCV)
{
	TPolyPtrChanceV newPoly = malloc(sizeof(TPolyChanceV));

	newPoly->polyTermCV = polyTermCV;
	newPoly->nextCV = NULL;

	return newPoly;
}

TPolyPtrChanceV deletePolyChanceV(TPolyPtrChanceV* polyCV)
{
	TPolyPtrChanceV nextCV = (*polyCV)->nextCV;

	// Delete all poly terms (use a while loop)
	deletePolyTermChanceV(&((*polyCV)->polyTermCV));
	free(*polyCV);
	(*polyCV) = NULL;

	return nextCV;
}