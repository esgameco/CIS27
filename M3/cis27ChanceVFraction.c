#include "cis27ChanceVFraction.h"

TFractionPtrChanceV createFractionChanceV(int numCV, int denCV)
{
	TFractionPtrChanceV newFractionChanceV = malloc(sizeof(TFractionChanceV));
	int gcd = gcdChanceV(numCV, denCV);

	if (denCV < 0)
	{
		numCV = -numCV;
		denCV = -denCV;
	}

	if (newFractionChanceV != NULL)
	{
		newFractionChanceV->numCV = numCV / gcd;
		newFractionChanceV->denCV = denCV / gcd;
	}

	return newFractionChanceV;
}

void deleteFractionChanceV(TFractionPtrChanceV* fractionCV)
{
	free(*fractionCV);
	*fractionCV = NULL;
}

TFractionPtrChanceV addFractionsChanceV(TFractionPtrChanceV fraction1CV, TFractionPtrChanceV fraction2CV)
{
	return createFractionChanceV(
		(fraction1CV->numCV * fraction2CV->denCV) +
		(fraction2CV->numCV * fraction1CV->denCV),
		(fraction1CV->denCV * fraction2CV->denCV)
	);
}

TFractionPtrChanceV multiplyFractionsChanceV(TFractionPtrChanceV fraction1CV, TFractionPtrChanceV fraction2CV)
{
	return createFractionChanceV(
		(fraction1CV->numCV * fraction2CV->numCV),
		(fraction1CV->denCV * fraction2CV->denCV)
	);
}

int gcdChanceV(int x, int y)
{
	x = (x > 0) ? x : -x;
	y = (y > 0) ? y : -y;
	int lower = (x < y) ? x : y;
	int gcd = 1;

	for (int i = 1; i < lower; i++)
		if (x % i == 0 && y % i == 0)
			gcd = i;

	return gcd;
}