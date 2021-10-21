#include <stdio.h>

#include "cis27ChanceVFractionList.h"

#ifndef HW3_UTILITY
#define HW3_UTILITY

void displayClassInfoChanceV();
void displayMenuChanceV();
void displayCreationSubmenuChanceV();
void displayArithmeticSubmenuChanceV();
void runMenuChanceV();
void runCreationSubmenuChanceV(struct FractionNodeCV** headCV);
void runArithmeticSubmenuChanceV(struct FractionNodeCV** headCV);
void submitResultChanceV(struct FractionNodeCV* headCV, struct FractionCV* fractionCV);
void updateFractionObjectChanceV(int fractionNumberCV, struct FractionNodeCV** headCV);
void createFractionObjectsChanceV(struct FractionNodeCV** headCV);
void getFractionDataChanceV(int* numCV, int* denCV, int);
void getValidIntChanceV(int* valCV, char* prompt, int);
void displayFractionObjectsChanceV(struct FractionNodeCV* headCV);
void displayFractionDataChanceV(struct FractionNodeCV* fractionNodeCV);

#endif