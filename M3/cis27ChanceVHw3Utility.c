#include "cis27ChanceVHw3Utility.h"

#define HW_NUM 3
#define DATE "2021/10/17"

#define BUFFER_LEN 20

#ifdef _WIN32
#define scanf scanf_s
#endif

void displayClassInfoChanceV()
{
    printf("CIS 27-Data Structures\n"
        "Laney College\n"
        "Chance Vodnoy\n\n"
        "Information --\n"
        "  Assignment: HW #%d\n"
        "  Implemented by: Chance Vodnoy\n"
        "  Submitted Date: %s\n"
        "  Current Number of LEB available: 2\n"
        "  Allowed Number of LEB Used: 0\n"
        "  Remaining Number of LEB: 2\n\n", HW_NUM, DATE);
}

void displayMenuChanceV()
{
    printf("**************************************************\n"
        "*                 MENU - HW #3                   *\n"
        "* (1) Creating/Updating 2 Fraction Data Objects  *\n"
        "* (2) Checking for Palindrome                    *\n"
        "* (3) Performing Arithmetic Operations (+, -, *) *\n"
        "* (4) Displaying Selected Fraction Data Object   *\n"
        "* (5) Quit                                       *\n"
        "**************************************************\n");
}

void displayCreationSubmenuChanceV()
{
    printf("    ***************************************\n"
        "    *     Creating/Updating Submenu       *\n"
        "    * (1) Creating 2 Fraction objects     *\n"
        "    * (2) Updating First Fraction object  *\n"
        "    * (3) Updating Second Fraction object *\n"
        "    * (4) Returning                       *\n"
        "    ***************************************\n");
}

void displayArithmeticSubmenuChanceV()
{
    printf("    ***************************************\n"
        "    *     Arithmetic Operations Submenu   *\n"
        "    * (1) Adding                          *\n"
        "    * (2) Multiplying                     *\n"
        "    * (3) Returning                       *\n"
        "    ***************************************\n");
}

void runMenuChanceV()
{
    int optionCV = 0;
    TFractionNodePtrChanceV headCV = NULL;

    while (optionCV != 5)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("  Creating/Updating 2 Fraction Data Objects -\n\n");
            runCreationSubmenuChanceV(&headCV);
            break;
        case 2:
            printf("  Checking for Palindrome -\n\n");
            checkFractionPalindromes(&headCV);
            break;
        case 3:
            runArithmeticSubmenuChanceV(&headCV);
            break;
        case 4:
            displayFractionObjectsChanceV(headCV);
            break;
        case 5:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

    if (headCV)
    {
        deleteAllNodesChanceV(&headCV);
    }
}

void checkFractionPalindromes(TFractionNodePtrChanceV* headCV)
{
    if (!(*headCV))
    {
        printf("  Not appropriate as there are no Fraction objects!\n\n");
        return 0;
    }

    printf("    First Fraction: %s\n",
        (checkFractionPalindrome((*headCV)->fractionCV))
        ? "Yes" : "No");
    printf("    Second Fraction: %s\n\n",
        (checkFractionPalindrome((*headCV)->nextCV->fractionCV))
        ? "Yes" : "No");
}

int checkFractionPalindrome(TFractionPtrChanceV fractionCV)
{
    int* numDigits = getDigits(fractionCV->numCV);
    int* denDigits = getDigits(fractionCV->denCV);
    int isPalindrome = checkPalindrome(numDigits) &&
        checkPalindrome(denDigits);

    free(numDigits);
    free(denDigits);

    return isPalindrome;
}

int checkPalindrome(int* digits)
{
    int length = 0;
    while (digits[length++] != -1);
    length--;

    for (int i = 0; i < length; i++)
    {
        if (digits[i] != digits[length - i - 1])
            return 0;
    }

    return 1;
}

int* getDigits(int value)
{
    int* arr = malloc(BUFFER_LEN * sizeof(int));
    int current = 0;

    value = (value > 0) ? value : -value;

    for (int i = 0; i < BUFFER_LEN; i++)
        arr[i] = -1;

    while (value)
    {
        arr[current] = value % 10;
        value /= 10;
        current++;
    }

    return arr;
}

void runCreationSubmenuChanceV(TFractionNodePtrChanceV* headCV)
{
    int optionCV = 0;

    while (optionCV != 4)
    {
        displayCreationSubmenuChanceV();
        printf("    Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            createFractionObjectsChanceV(headCV);
            break;
        case 2:
            updateFractionObjectChanceV(0, headCV);
            printf("    Returning to previous menu!\n\n");
            return;
        case 3:
            updateFractionObjectChanceV(1, headCV);
            printf("    Returning to previous menu!\n\n");
            return;
        case 4:
            printf("    Returning to previous menu!\n\n");
            break;
        default:
            printf("    Wrong option!\n\n");
        }
    }
}

void runArithmeticSubmenuChanceV(TFractionNodePtrChanceV* headCV)
{
    int optionCV = 0;

    while (optionCV != 3)
    {
        displayArithmeticSubmenuChanceV();
        printf("    Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("      Adding (First + Second --> Result)!\n\n");
            submitResultChanceV(*headCV, addFractionsChanceV(
                (*headCV)->fractionCV,
                (*headCV)->nextCV->fractionCV
            ));
            break;
        case 2:
            printf("      Multiplying (First * Second --> Result)!\n\n");
            submitResultChanceV(*headCV, multiplyFractionsChanceV(
                (*headCV)->fractionCV,
                (*headCV)->nextCV->fractionCV
            ));
            break;
        case 3:
            printf("    Return to Previous Menu\n\n");
            break;
        default:
            printf("    Wrong option!\n\n");
        }
    }
}

void submitResultChanceV(TFractionNodePtrChanceV headCV, TFractionPtrChanceV fractionCV)
{
    if (!headCV->nextCV->nextCV)
        addNodeChanceV(headCV->nextCV, fractionCV);
    else
    {
        deleteFractionChanceV(&headCV->nextCV->nextCV->fractionCV);
        updateNodeChanceV(2, headCV, fractionCV);
    }
}

void updateFractionObjectChanceV(int fractionNumberCV, TFractionNodePtrChanceV* headCV)
{
    int num, den = 0;
    struct Fraction* newFraction;

    printf("      Fraction Objects exist --\n"
        "        Updating Process --\n");

    printf("          %s Object --\n", (fractionNumberCV == 0) ? "First" : "Second");
    getFractionDataChanceV(&num, &den, 12);
    newFraction = createFractionChanceV(num, den);

    updateNodeChanceV(fractionNumberCV, *headCV, newFraction);
    printf("\n");
}

void createFractionObjectsChanceV(TFractionNodePtrChanceV* headCV)
{
    int num, den = 0;
    if (!(*headCV))
    {
        printf("      No Fraction Objects exist --\n"
            "        Creating Process --\n");

        printf("          First Fraction:\n");
        getFractionDataChanceV(&num, &den, 12);
        *headCV = createNodeChanceV(createFractionChanceV(num, den));
        printf("\n");

        printf("          Second Fraction:\n");
        getFractionDataChanceV(&num, &den, 12);
        addNodeChanceV(*headCV, createFractionChanceV(num, den));
    }
    else
    {
        printf("      Fraction Objects exist - Choose Update or Quit!\n");
    }
    printf("\n");
}

void getFractionDataChanceV(int* numCV, int* denCV, int nSpacesCV)
{
    getValidIntChanceV(numCV, "Enter an int for num: ", nSpacesCV);
    getValidIntChanceV(denCV, "Enter an int for denom: ", nSpacesCV);
}

void getValidIntChanceV(int* valCV, char* prompt, int nSpacesCV)
{
    *valCV = 0;
    while (!(*valCV))
    {
        printf("%*c%s", nSpacesCV, ' ', prompt);
        scanf("%d", valCV);
        if (!(*valCV))
            printf("              0 is not allowed!\n\n");
    }
}

void displayFractionObjectsChanceV(TFractionNodePtrChanceV headCV)
{
    if (headCV)
    {
        printf("  Displaying Fraction Objects -\n\n");

        printf("    First Object --\n");
        displayFractionDataChanceV(headCV);

        printf("\n    Second Object --\n");
        displayFractionDataChanceV(headCV->nextCV);

        printf("\n    Resulting Object --\n");
        displayFractionDataChanceV(headCV->nextCV->nextCV);
    }
    else
        printf("Cannot choose this option as there are no Fraction objects!\n");

    printf("\n");
}

void displayFractionDataChanceV(TFractionNodePtrChanceV fractionNodeCV)
{
    if (fractionNodeCV && fractionNodeCV->fractionCV)
    {
        printf("      Address: %p\n", fractionNodeCV->fractionCV);
        printf("      num: %d\n", fractionNodeCV->fractionCV->numCV);
        printf("      denom: %d\n", fractionNodeCV->fractionCV->denCV);
    }
    else
        printf("      Not Existing!\n");
}
