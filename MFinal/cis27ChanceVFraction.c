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

	newFractionChanceV->numCV = numCV / gcd;
	newFractionChanceV->denCV = denCV / gcd;

	return newFractionChanceV;
}

void deleteFractionChanceV(TFractionPtrChanceV* fractionCV)
{
	free(*fractionCV);
	*fractionCV = NULL;
}

void freeFractionChanceV(TFractionPtrChanceV fractionCV)
{
	free(fractionCV);
}

TFractionPtrChanceV addFractionsChanceV(
	TFractionPtrChanceV fraction1CV, 
	TFractionPtrChanceV fraction2CV)
{
	if (!fraction1CV->numCV && !fraction1CV->denCV)
		return createFractionChanceV(
			fraction2CV->numCV,
			fraction2CV->denCV
		);
	return createFractionChanceV(
		(fraction1CV->numCV * fraction2CV->denCV) +
		(fraction2CV->numCV * fraction1CV->denCV),
		(fraction1CV->denCV * fraction2CV->denCV)
	);
}

TFractionPtrChanceV multiplyFractionsChanceV(
	TFractionPtrChanceV fraction1CV, 
	TFractionPtrChanceV fraction2CV)
{
	return createFractionChanceV(
		(fraction1CV->numCV * fraction2CV->numCV),
		(fraction1CV->denCV * fraction2CV->denCV)
	);
}

void setFractionsEqualChanceV(
	TFractionPtrChanceV toSetCV, 
	TFractionPtrChanceV toUseCV)
{
	toSetCV->numCV = toUseCV->numCV;
	toSetCV->denCV = toUseCV->denCV;
}

int powChanceV(int mult, int degree)
{
	if (!degree)
		return 1;
	return mult * powChanceV(mult, degree - 1);
}

TFractionPtrChanceV powFractionsChanceV(TFractionPtrChanceV fracCV, int exp)
{
	return createFractionChanceV(
		powChanceV(fracCV->numCV, exp),
		powChanceV(fracCV->numCV, exp));
}

void evalFracChanceV(TFractionPtrChanceV addToCV, TFractionPtrChanceV coEffCV, TFractionPtrChanceV xCV, int exp)
{
	TFractionPtrChanceV powedCV, multedCV, resultCV;
	int gcd;

	powedCV = powFractionsChanceV(xCV, exp);
	multedCV = multiplyFractionsChanceV(coEffCV, powedCV);
	resultCV = addFractionsChanceV(addToCV, multedCV);
	setFractionsEqualChanceV(addToCV, resultCV);

	useGCDChanceV(addToCV);

	deleteFractionChanceV(&resultCV);
	deleteFractionChanceV(&multedCV);
	deleteFractionChanceV(&powedCV);
}

int gcdChanceV(int x, int y)
{
	x = (x > 0) ? x : -x;
	y = (y > 0) ? y : -y;
	int higher = (x > y) ? x : y;
	int gcd = 1;

	for (int i = 1; i < higher; i++)
		if (x % i == 0 && y % i == 0)
			gcd = i;

	return gcd;
}

void useGCDChanceV(TFractionPtrChanceV fracCV)
{
	int gcd = gcdChanceV(fracCV->numCV, fracCV->denCV);

	fracCV->numCV = fracCV->numCV / gcd;
	fracCV->denCV = fracCV->denCV / gcd;
}