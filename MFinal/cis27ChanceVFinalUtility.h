/*
 * Program Name: cis27ChanceVFinalUtility.h
 * Discussion: Homework Menu with combination of
 *             do-while and switch structures
 *             Reminder!
 *                  Besides the above setup, NO OTHERCOMBINATIONS
 *                  will be allowed to setup a menu as if one is
 *                  needed.
 * Written By: Chance Vodnoy
 * Date: 12/16/21
 */

#ifndef CIS27CHANCEVFINALUTILITY_H
#define CIS27CHANCEVFINALUTILITY_H

#include "cis27ChanceVPoly.h"

#include <stdio.h>

#define DATE "2021/12/16"

#define BUFFER_LEN 20

#ifdef _WIN32
#define scanf scanf_s
#endif

void displayClassInfoChanceV();
void displayMenuChanceV();
void displayInitSubmenuChanceV();
void runMenuChanceV();
void runInitSubmenuChanceV(TPolyPtrChanceV* headCV);
void createChanceV(TPolyPtrChanceV* headCV, int nTerms);
TPolyTermPtrChanceV utilCreatePolyTermNodeChanceV(int nSpaces);
TPolyTermNodePtrChanceV getPolyTermNodeChanceV(TPolyPtrChanceV polyCV, int expo);
TPolyPtrChanceV formPalindromePolynomialChanceV(
    TPolyPtrChanceV poly1CV,
    TPolyPtrChanceV poly2CV);
void pushBackPolyChanceV(TPolyPtrChanceV* tailCV, TPolyPtrChanceV addCV);
void displayPolynomialChanceV(TPolyPtrChanceV polyCV, int polyNum, int nSpaces);
void displayPolynomialsChanceV(TPolyPtrChanceV headCV, int nSpaces);
int isPalindromePolyChanceV(TPolyPtrChanceV headCV, int polyNum);
int checkFractionPalindromeChanceV(TFractionPtrChanceV fractionCV);
int checkPalindromeChanceV(int* digits);
int* getDigitsChanceV(int value);

#endif
