#include "cis27ChanceVFraction.h"

TFractionPtrChanceV createFractionChanceV(int numCV, int denCV)
{
	TFractionPtrChanceV newFractionChanceV = malloc(sizeof(TFractionChanceV));
	newFractionChanceV->numCV = numCV;
	newFractionChanceV->denCV = denCV;
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
