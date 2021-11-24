#include <stdlib.h>

#ifndef FRACTION
#define FRACTION

typedef struct FractionChanceV TFractionChanceV;
typedef struct FractionChanceV* TFractionPtrChanceV;

struct FractionChanceV
{
	int numCV;
	int denCV;
};

TFractionPtrChanceV createFractionChanceV(int num, int den);
void deleteFractionChanceV(TFractionPtrChanceV* fraction);
TFractionPtrChanceV addFractionsChanceV(TFractionPtrChanceV fraction1CV, TFractionPtrChanceV fraction2CV);
TFractionPtrChanceV multiplyFractionsChanceV(TFractionPtrChanceV fraction1CV, TFractionPtrChanceV fraction2CV);
int gcdChanceV(int x, int y);

#endif
