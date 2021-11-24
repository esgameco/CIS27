#ifndef HW3_UTILITY
#define HW3_UTILITY

#include "cis27ChanceVFractionList.h"

#include <stdio.h>

void displayClassInfoChanceV();
void displayMenuChanceV();
void displayCreationSubmenuChanceV();
void displayArithmeticSubmenuChanceV();
void runMenuChanceV();
void checkFractionPalindromes(TFractionNodePtrChanceV* headCV);
int checkFractionPalindrome(TFractionPtrChanceV fractionCV);
int checkPalindrome(int* digits);
int* getDigits(int value);
void runCreationSubmenuChanceV(TFractionNodePtrChanceV* headCV);
void runArithmeticSubmenuChanceV(TFractionNodePtrChanceV* headCV);
void submitResultChanceV(TFractionNodePtrChanceV headCV, TFractionPtrChanceV fractionCV);
void updateFractionObjectChanceV(int fractionNumberCV, TFractionNodePtrChanceV* headCV);
void createFractionObjectsChanceV(TFractionNodePtrChanceV* headCV);
void getFractionDataChanceV(int* numCV, int* denCV, int);
void getValidIntChanceV(int* valCV, char* prompt, int);
void displayFractionObjectsChanceV(TFractionNodePtrChanceV headCV);
void displayFractionDataChanceV(TFractionNodePtrChanceV fractionNodeCV);

#endif
