#include "cis27ChanceVFraction.h"

struct FractionCV* createFractionChanceV(int numCV, int denCV)
{
	struct FractionCV* newFractionCV = malloc(sizeof(struct FractionCV));
	newFractionCV->numCV = numCV;
	newFractionCV->denCV = denCV;
	return newFractionCV;
}

void deleteFractionChanceV(struct FractionCV** fractionCV)
{
	free(*fractionCV);
	*fractionCV = NULL;
}

struct FractionCV* addFractionsChanceV(struct FractionCV* fraction1CV, struct FractionCV* fraction2CV)
{
	return createFractionChanceV(
		(fraction1CV->numCV * fraction2CV->denCV) +
		(fraction2CV->numCV * fraction1CV->denCV),
		(fraction1CV->denCV * fraction2CV->denCV)
	);
}

struct FractionCV* multiplyFractionsChanceV(struct FractionCV* fraction1CV, struct FractionCV* fraction2CV)
{
	return createFractionChanceV(
		(fraction1CV->numCV * fraction2CV->numCV),
		(fraction1CV->denCV * fraction2CV->denCV)
	);
}