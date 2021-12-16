#include "cis27ChanceVPoly.h"

int getNTermsChanceV(TPolyTermPtrChanceV polyTermCV)
{
	int nTerms = 0;
	
	while (polyTermCV)
	{
		nTerms++;
		if (polyTermCV->nextCV)
		{
			polyTermCV = polyTermCV->nextCV;
		}
		else
			break;
	}

	return nTerms;
}

int getDegreeChanceV(TPolyTermPtrChanceV polyTermCV)
{
	int degree = 0;

	while (polyTermCV)
	{
		if (polyTermCV->expoCV > degree)
			degree = polyTermCV->expoCV;

		if (polyTermCV->nextCV)
			polyTermCV = polyTermCV->nextCV;
		else
			break;
	}

	return degree;
}

TPolyPtrChanceV createPolyChanceV(TPolyTermPtrChanceV polyTermCV)
{
	TPolyPtrChanceV newPoly = malloc(sizeof(TPolyChanceV));
	
	if (polyTermCV)
	{
		newPoly->degreeCV = getDegreeChanceV(polyTermCV);
		newPoly->nTermsCV = getNTermsChanceV(polyTermCV);
		newPoly->polyTermCV = polyTermCV;
	}
	else
	{
		newPoly->degreeCV = 0;
		newPoly->nTermsCV = 0;
		newPoly->polyTermCV = NULL;
	}
	newPoly->nextCV = NULL;

	return newPoly;
}

TPolyPtrChanceV deletePolyChanceV(TPolyPtrChanceV* polyCV)
{
	if (!(*polyCV))
		return; 

	TPolyPtrChanceV nextCV = (*polyCV)->nextCV;

	// Delete all poly terms (use a while loop)
	deletePolyTermChanceV(&((*polyCV)->polyTermCV));
	free(*polyCV);
	(*polyCV) = NULL;

	return nextCV;
}

void insertPolyTermChanceV(TPolyPtrChanceV polyCV, TPolyTermPtrChanceV addCV)
{
	TPolyTermPtrChanceV* replaceCV = &(polyCV->polyTermCV);
	TPolyTermPtrChanceV currTermCV = polyCV->polyTermCV;
	TPolyTermPtrChanceV prevTermCV = NULL;

	if (!currTermCV)
	{
		polyCV->polyTermCV = addCV;
		return;
	}

	while (currTermCV)
	{
		if (addCV->expoCV > currTermCV->expoCV)
		{
			if (prevTermCV)
				prevTermCV->nextCV = addCV;
			addCV->nextCV = currTermCV;
			*replaceCV = addCV;

			polyCV->degreeCV = getDegreeChanceV(polyCV->polyTermCV);
			polyCV->nTermsCV = getNTermsChanceV(polyCV->polyTermCV);
			return;
		}

		replaceCV = &((*replaceCV)->nextCV);
		prevTermCV = currTermCV;
		currTermCV = currTermCV->nextCV;
	}

	if (prevTermCV)
		prevTermCV->nextCV = addCV;

	polyCV->degreeCV = getDegreeChanceV(polyCV->polyTermCV);
	polyCV->nTermsCV = getNTermsChanceV(polyCV->polyTermCV);
}

TFractionPtrChanceV evaluatePolyChanceV(TPolyPtrChanceV polyCV, TFractionPtrChanceV fracCV)
{
	if (!polyCV)
		return NULL;

	TPolyTermPtrChanceV currTermCV = polyCV->polyTermCV;
	TFractionPtrChanceV result = createFractionChanceV(0, 0);

	while (currTermCV)
	{
		evalFracChanceV(result, currTermCV->fractionCV, fracCV, currTermCV->expoCV);

		currTermCV = currTermCV->nextCV;
	}

	return result;
}