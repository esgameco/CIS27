#ifndef POLY
#define POLY

#include <stdlib.h>

#include "cis27ChanceVPolyTerm.h"

typedef struct PolyChanceV TPolyChanceV;
typedef struct PolyChanceV* TPolyPtrChanceV;

struct PolyChanceV
{
	int degreeCV;
	int nTermsCV;
	TPolyTermPtrChanceV polyTermCV;
	TPolyPtrChanceV nextCV;
};

TPolyPtrChanceV createPolyChanceV(TPolyTermPtrChanceV);
TPolyPtrChanceV deletePolyChanceV(TPolyPtrChanceV*);
void insertPolyTermChanceV(TPolyPtrChanceV polyCV, TPolyTermPtrChanceV addCV);
TFractionPtrChanceV evaluatePolyChanceV(TPolyPtrChanceV polyCV, TFractionPtrChanceV fracCV);

#endif
