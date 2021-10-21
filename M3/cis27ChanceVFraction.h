#include <stdlib.h>

#ifndef FRACTION
#define FRACTION

struct FractionCV
{
	int numCV;
	int denCV;
};

struct FractionCV* createFractionChanceV(int num, int den);
void deleteFractionChanceV(struct FractionCV** fraction);
struct FractionCV* addFractionsChanceV(struct FractionCV* fraction1CV, struct FractionCV* fraction2CV);
struct FractionCV* multiplyFractionsChanceV(struct FractionCV* fraction1CV, struct FractionCV* fraction2CV);

#endif
