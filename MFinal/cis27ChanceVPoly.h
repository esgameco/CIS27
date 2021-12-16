/**
  * Program Name: cis27ChanceVPoly.h
  * Discussion: Multi-File Setup
  *				- Specification File
  *				- struct Poly
  * Written By: Chance Vodnoy
  * Date: 2021/12/16
  */

#ifndef CIS27CHANCEVPOLY_H
#define CIS27CHANCEVPOLY_H

#include <stdlib.h>

#include "cis27ChanceVPolyTerm.h"

typedef struct PolyChanceV TPolyChanceV;
typedef struct PolyChanceV* TPolyPtrChanceV;

struct PolyChanceV
{
	int degreeCV;
	int nTermsCV;
	TPolyTermNodePtrChanceV polyTermNodeCV;
	TPolyPtrChanceV nextCV;
};

TPolyPtrChanceV createPolyChanceV(TPolyTermPtrChanceV);
TPolyPtrChanceV deletePolyChanceV(TPolyPtrChanceV*);
void deleteAllPolysChanceV(TPolyPtrChanceV* polyCV);
void deleteAllPolyTermsChanceV(TPolyTermNodePtrChanceV* polyTermNodeCV);
void insertPolyTermNodeChanceV(TPolyPtrChanceV polyCV, TPolyTermNodePtrChanceV addCV);
TFractionPtrChanceV evaluatePolyChanceV(TPolyPtrChanceV polyCV, TFractionPtrChanceV fracCV);

#endif
