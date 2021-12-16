/**
  * Program Name: cis27ChanceVPolyTerm.h
  * Discussion: Multi-File Setup
  *				- Specification File
  *				- struct PolyTerm
  *				- struct PolyTermNode
  * Written By: Chance Vodnoy
  * Date: 2021/12/16
  */

#ifndef CIS27CHANCEVPOLYTERM_H
#define CIS27CHANCEVPOLYTERM_H

#include "cis27ChanceVFraction.h"

typedef struct PolyTermChanceV TPolyTermChanceV;
typedef struct PolyTermChanceV* TPolyTermPtrChanceV;

typedef struct PolyTermNodeChanceV TPolyTermNodeChanceV;
typedef struct PolyTermNodeChanceV* TPolyTermNodePtrChanceV;

struct PolyTermNodeChanceV
{
	TPolyTermPtrChanceV termCV;
	TPolyTermNodePtrChanceV nextCV;
};

struct PolyTermChanceV
{
	int expoCV;
	TFractionPtrChanceV fractionCV;
};

TPolyTermNodePtrChanceV createPolyTermNodeChanceV(TPolyTermPtrChanceV);
TPolyTermNodePtrChanceV deletePolyTermNodeChanceV(TPolyTermPtrChanceV*);
TPolyTermPtrChanceV createPolyTermChanceV(int, TFractionPtrChanceV);
void deletePolyTermChanceV(TPolyTermPtrChanceV*);

#endif
