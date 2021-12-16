#include <stdio.h>

#include "cis27ChanceVPoly.h"

#ifndef HW4_UTILITY
#define HW4_UTILITY

#define HW_NUM 4
#define DATE "2021/11/07"

#define BUFFER_LEN 20

#ifdef _WIN32
#define scanf scanf_s
#endif

void displayClassInfoChanceV();
void displayMenuChanceV();
void displayInitSubmenuChanceV();
void displayUpdateSubmenuChanceV();
void runMenuChanceV();
void runInitSubmenuChanceV(TPolyPtrChanceV* headCV);
void runUpdateSubmenuChanceV(TPolyPtrChanceV polyCV, int polyNum);
void createChanceV(TPolyPtrChanceV* headCV, int nTerms);
TPolyTermPtrChanceV utilCreatePolyTermChanceV();
void evaluateChanceV(TPolyPtrChanceV headCV);
TPolyPtrChanceV addPolynomialsChanceV(
    TPolyPtrChanceV poly1CV,
    TPolyPtrChanceV poly2CV);
TPolyPtrChanceV multiplyPolynomialsChanceV(
    TPolyPtrChanceV poly1CV,
    TPolyPtrChanceV poly2CV);
void pushBackPolyChanceV(TPolyPtrChanceV* tailCV, TPolyPtrChanceV addCV);
void displayPolynomialChanceV(TPolyPtrChanceV polyCV, int polyNum);
void displayPolynomialsChanceV(TPolyPtrChanceV headCV);
void checkFractionPalindromesChanceV(TPolyPtrChanceV headCV, int polyNum);
int checkFractionPalindromeChanceV(TFractionPtrChanceV fractionCV);
int checkPalindromeChanceV(int* digits);
int* getDigitsChanceV(int value);
/*
void insertFirstChanceV(TFractionNodePtrChanceV* headCV);
void removeFirstChanceV(TFractionNodePtrChanceV* headCV);
void getFractionDataChanceV(int* numCV, int* denCV, int);
void getValidIntChanceV(int* valCV, char* prompt, int);
void displayFractionObjectsChanceV(TFractionNodePtrChanceV headCV);
void displayFractionDataChanceV(TFractionNodePtrChanceV fractionNodeCV);
*/

#endif
