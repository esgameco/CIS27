#include <stdio.h>

#include "cis27ChanceVFractionList.h"

#ifndef HW3_UTILITY
#define HW3_UTILITY

void displayClassInfoChanceV();
void displayMenuChanceV();
void displayCreationSubmenuChanceV();
void displayArithmeticSubmenuChanceV();
void runMenuChanceV();
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