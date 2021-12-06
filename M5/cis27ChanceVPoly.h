#ifndef POLY
#define POLY

#include <stdlib.h>

#include "cis27ChanceVPolyTerm.h"

typedef struct PolyChanceV TPolyChanceV;
typedef struct PolyChanceV* TPolyPtrChanceV;

struct PolyChanceV
{
	TPolyTermPtrChanceV polyTermCV;
	TPolyPtrChanceV nextCV;
};

TPolyPtrChanceV createPolyChanceV(TPolyTermPtrChanceV);
TPolyPtrChanceV deletePolyChanceV(TPolyPtrChanceV*);

#endif
