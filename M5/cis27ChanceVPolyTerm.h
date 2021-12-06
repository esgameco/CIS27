#ifndef POLY_TERM
#define POLY_TERM

#include "cis27ChanceVFraction.h"

typedef struct PolyTermChanceV TPolyTermChanceV;
typedef struct PolyTermChanceV* TPolyTermPtrChanceV;

struct PolyTermChanceV
{
	int expoCV;
	TFractionPtrChanceV fractionCV;
	TPolyTermPtrChanceV nextCV;
};

TPolyTermPtrChanceV createPolyTermChanceV(int, TFractionPtrChanceV);
TPolyTermPtrChanceV deletePolyTermChanceV(TPolyTermPtrChanceV*);

#endif
