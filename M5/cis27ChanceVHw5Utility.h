#include <stdio.h>

#include "cis27ChanceVFractionList.h"

#ifndef HW4_UTILITY
#define HW4_UTILITY

void displayClassInfoChanceV();
void displayMenuChanceV();
void runMenuChanceV();
void checkFractionPalindromes(TFractionNodePtrChanceV* headCV);
int checkFractionPalindrome(TFractionPtrChanceV fractionCV);
int checkPalindrome(int* digits);
int* getDigits(int value);
void insertFirstChanceV(TFractionNodePtrChanceV* headCV);
void removeFirstChanceV(TFractionNodePtrChanceV* headCV);
void getFractionDataChanceV(int* numCV, int* denCV, int);
void getValidIntChanceV(int* valCV, char* prompt, int);
void displayFractionObjectsChanceV(TFractionNodePtrChanceV headCV);
void displayFractionDataChanceV(TFractionNodePtrChanceV fractionNodeCV);

#endif
