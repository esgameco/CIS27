#include "cis27ChanceVPoly.h"

int getNTermsChanceV(TPolyTermNodePtrChanceV polyTermNodeCV)
{
	int nTerms = 0;
	
	while (polyTermNodeCV)
	{
		nTerms++;
		
		polyTermNodeCV = polyTermNodeCV->nextCV;
	}

	return nTerms;
}

int getDegreeChanceV(TPolyTermNodePtrChanceV polyTermNodeCV)
{
	int degree = 0;

	while (polyTermNodeCV)
	{
		if (polyTermNodeCV->termCV->expoCV > degree)
			degree = polyTermNodeCV->termCV->expoCV;

		polyTermNodeCV = polyTermNodeCV->nextCV;
	}

	return degree;
}

TPolyPtrChanceV createPolyChanceV(TPolyTermNodePtrChanceV polyTermNodeCV)
{
	TPolyPtrChanceV newPoly = malloc(sizeof(TPolyChanceV));
	
	if (polyTermNodeCV)
	{
		newPoly->degreeCV = getDegreeChanceV(polyTermNodeCV);
		newPoly->nTermsCV = getNTermsChanceV(polyTermNodeCV);
		newPoly->polyTermNodeCV = polyTermNodeCV;
	}
	else
	{
		newPoly->degreeCV = 0;
		newPoly->nTermsCV = 0;
		newPoly->polyTermNodeCV = NULL;
	}
	newPoly->nextCV = NULL;

	return newPoly;
}

TPolyPtrChanceV deletePolyChanceV(TPolyPtrChanceV* polyCV)
{
	if (!(*polyCV))
		return; 

	TPolyPtrChanceV nextCV = (*polyCV)->nextCV;

	deleteAllPolyTermsChanceV(&((*polyCV)->polyTermNodeCV));
	free(*polyCV);
	(*polyCV) = NULL;

	return nextCV;
}

void deleteAllPolyTermsChanceV(TPolyTermNodePtrChanceV* polyTermNodeCV)
{
	TPolyTermNodePtrChanceV nextCV;

	while (*polyTermNodeCV)
	{
		nextCV = deletePolyTermNodeChanceV(polyTermNodeCV);
		polyTermNodeCV = &nextCV;
	}
}

void deleteAllPolysChanceV(TPolyPtrChanceV* polyCV)
{
	TPolyPtrChanceV nextCV;

	while (*polyCV)
	{
		nextCV = deletePolyChanceV(polyCV);
		polyCV = &nextCV;
	}
}

void insertPolyTermNodeChanceV(TPolyPtrChanceV polyCV, TPolyTermNodePtrChanceV addCV)
{
	TPolyTermNodePtrChanceV* replaceCV = &(polyCV->polyTermNodeCV);
	TPolyTermNodePtrChanceV currTermCV = polyCV->polyTermNodeCV;
	TPolyTermNodePtrChanceV prevTermCV = NULL;

	if (!currTermCV)
	{
		polyCV->polyTermNodeCV = addCV;
		return;
	}

	while (currTermCV)
	{
		if (addCV->termCV->expoCV > currTermCV->termCV->expoCV)
		{
			if (prevTermCV)
				prevTermCV->nextCV = addCV;
			addCV->nextCV = currTermCV;
			*replaceCV = addCV;

			polyCV->degreeCV = getDegreeChanceV(polyCV->polyTermNodeCV);
			polyCV->nTermsCV = getNTermsChanceV(polyCV->polyTermNodeCV);
			return;
		}

		replaceCV = &((*replaceCV)->nextCV);
		prevTermCV = currTermCV;
		currTermCV = currTermCV->nextCV;
	}

	if (prevTermCV)
		prevTermCV->nextCV = addCV;

	polyCV->degreeCV = getDegreeChanceV(polyCV->polyTermNodeCV);
	polyCV->nTermsCV = getNTermsChanceV(polyCV->polyTermNodeCV);
}

TFractionPtrChanceV evaluatePolyChanceV(TPolyPtrChanceV polyCV, TFractionPtrChanceV fracCV)
{
	if (!polyCV)
		return NULL;

	TPolyTermNodePtrChanceV currTermCV = polyCV->polyTermNodeCV;
	TFractionPtrChanceV result = createFractionChanceV(0, 0);

	while (currTermCV)
	{
		evalFracChanceV(result, currTermCV->termCV->fractionCV, fracCV, currTermCV->termCV->expoCV);

		currTermCV = currTermCV->nextCV;
	}

	return result;
}