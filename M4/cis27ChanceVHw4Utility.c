#include "cis27ChanceVHw4Utility.h"

#define HW_NUM 4
#define DATE "2021/11/07"

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
    printf("**********************************\n"
        "*           MENU - HW #4         *\n"
        "* (1) Creating Fraction List     *\n"
        "* (2) Checking for Palindrome    *\n"
        "* (3) Inserting Fraction         *\n"
        "* (4) Removing Fraction          *\n"
        "* (5) Displaying Fraction List   *\n"
        "* (6) Quit                       *\n"
        "**********************************\n");
}

void runMenuChanceV()
{
    int optionCV = 0;
    TFractionNodePtrChanceV headCV = NULL;

    while (optionCV != 6)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("  Creating Fraction List using insertFirstChanceV() -\n\n");
            insertFirstChanceV(&headCV);
            break;
        case 2:
            printf("  Checking for Palindrome -\n\n");
            checkFractionPalindromes(&headCV);
            break;
        case 3:
            printf("  Inserting Fraction List using insertFirstChanceV() -\n\n");
            insertFirstChanceV(&headCV);
            break;
        case 4:
            printf("  Removing a Fraction node using removeFirstChanceV() -\n\n");
            removeFirstChanceV(&headCV);
            break;
        case 5:
            printf("  Displaying Fraction list -\n\n");
            displayFractionObjectsChanceV(headCV);
            break;
        case 6:
            printf("  Deallocating and Removing ALL Fraction's!\n\n");
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

    if (headCV)
        deleteAllNodesChanceV(&headCV);
}

void checkFractionPalindromes(TFractionNodePtrChanceV* headCV)
{
    TFractionNodePtrChanceV iterCV = *headCV;
    int arePalin = 0;

    if (!(*headCV))
    {
        printf("  Not appropriate as there is no list (or empty list)!\n\n");
        return 0;
    }

    while (iterCV)
    {
        if (checkFractionPalindrome(iterCV->fractionCV))
        {
            printf("    A Palindrome Fraction at\n");
            displayFractionDataChanceV(iterCV, 0);
            printf("\n");
            arePalin++;
        }
        iterCV = iterCV->nextCV;
    }

    if (!arePalin)
        printf("     There are no Palindrome Fraction's!\n\n");

    iterCV = NULL;
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

void insertFirstChanceV(TFractionNodePtrChanceV* headCV)
{
    TFractionNodePtrChanceV prevHead = *headCV;
    int num, den = 0;

    printf("    Creating a Fraction --\n");
    getFractionDataChanceV(&num, &den, 6);
    printf("\n    Creating a Fraction node ...\n\n");
    *headCV = createNodeChanceV(createFractionChanceV(num, den));
    printf("    Inserting Fraction node to become first node ...\n\n");
    (*headCV)->nextCV = prevHead;

    prevHead = NULL;
}

void removeFirstChanceV(TFractionNodePtrChanceV* headCV)
{
    printf("    Calling removeFirstChanceV() ...\n\n");
    printf("    Calling free() to deallocate dynamic block ...\n\n");

    *headCV = deleteNodeChanceV(headCV);
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
            printf("        0 is not allowed!\n\n");
    }
}

void displayFractionObjectsChanceV(TFractionNodePtrChanceV headCV)
{
    int curr = 0;

    if (headCV)
    {
        while (headCV)
        {
            printf("    Node #%d:\n", curr + 1);
            displayFractionDataChanceV(headCV, 1);
            printf("\n");
            headCV = headCV->nextCV;
            curr++;
        }
    }
    else
        printf("  Not appropriate as there is no list (or empty list)!\n\n");
}

void displayFractionDataChanceV(TFractionNodePtrChanceV fractionNodeCV, int displayNextCV)
{
    if (fractionNodeCV && fractionNodeCV->fractionCV)
    {
        printf("      Address: %p\n", fractionNodeCV);
        printf("      Fraction:\n");
        printf("        num: %d\n", fractionNodeCV->fractionCV->numCV);
        printf("        denom: %d\n", fractionNodeCV->fractionCV->denCV);
        if (displayNextCV)
        {
            if (fractionNodeCV->nextCV)
                printf("      next: %p\n", fractionNodeCV->nextCV);
            else
                printf("      next: 0\n");
        }
    }
    else
        printf("          Not Existing!\n");
}
