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
void freeFractionChanceV(TFractionPtrChanceV fractionCV);
TFractionPtrChanceV addFractionsChanceV(
	TFractionPtrChanceV fraction1CV, 
	TFractionPtrChanceV fraction2CV);
TFractionPtrChanceV multiplyFractionsChanceV(
	TFractionPtrChanceV fraction1CV, 
	TFractionPtrChanceV fraction2CV);
void setFractionsEqualChanceV(
	TFractionPtrChanceV toSetCV,
	TFractionPtrChanceV toUseCV);
TFractionPtrChanceV powFractionsChanceV(
	TFractionPtrChanceV fracCV, int exp);
void evalFracChanceV(
	TFractionPtrChanceV addToCV, 
	TFractionPtrChanceV coEffCV, 
	TFractionPtrChanceV xCV, int exp);
int gcdChanceV(int x, int y);
void useGCDChanceV(TFractionPtrChanceV fracCV);

#endif
