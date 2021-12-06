#include "cis27ChanceVHw5Utility.h"

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
    printf("***************************************\n"
           "*           MENU - HW #5              *\n"
           "* (1) Creating/Updating 2 Polynomials *\n"
           "* (2) Evaluating 2 Polynomials        *\n"
           "* (3) Checking for Palindrome         *\n"
           "* (4) Adding 2 Polylynomials          *\n"
           "* (5) Multiplying 2 Polynomials       *\n"
           "* (6) Displaying 2 Polynomials        *\n"
           "* (7) Display Resulting Polynomial    *\n"
           "* (8) Quit                            *\n"
           "***************************************\n");
}

void displayInitSubmenuChanceV()
{
    printf("  *********************************\n"
           "  *         init() Submenu        *\n"
           "  * (1) Creating 2 Polynomials    *\n"
           "  * (2) Updating Polynomial 1     *\n"
           "  * (3) Updating Polynomial 2     *\n"
           "  * (4) Displaying 2 Polynomials  *\n"
           "  * (5) Return                    *\n"
           "  *********************************\n");
}

void displayUpdateSubmenuChanceV()
{
    printf("    *************************************\n"
           "    *          update() Submenu         *\n"
           "    * (1) Adding one term               *\n"
           "    * (2) Removing one term             *\n"
           "    * (3) Displaying updated Polynomial *\n"
           "    * (4) Return                        *\n"
           "    *************************************\n");
}

void runMenuChanceV()
{
    int optionCV = 0;
    TPolyPtrChanceV headCV = NULL;

    while (optionCV != 8)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("  Initializing 2 Polynomials -\n\n");
            printf("    Calling initChanceV() -\n\n");
            runInitSubmenuChanceV(&headCV);
            break;
        case 2:
            printf("  Evaluating Polynomials -\n\n");
            break;
        case 3:
            printf("  Inserting Fraction List using insertFirstChanceV() -\n\n");
            break;
        case 4:
            printf("  Adding 2 Polynomials -\n\n");
            break;
        case 5:
            printf("  Multiplying 2 Polynomials -\n\n");
            break;
        case 6:
            printf("  Displaying the resulting Polynomial -\n\n");
            break;
        case 7:
            printf("  Displaying the resulting Polynomial -\n\n");
            break;
        case 8:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

    // TODO: Change to polynomical nodes
    //if (headCV)
    //    deleteAllNodesChanceV(&headCV);
}

void runInitSubmenuChanceV(TPolyPtrChanceV* headCV)
{
    int optionCV = 0;

    while (optionCV != 5)
    {
        displayInitSubmenuChanceV();
        printf("  Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("      Creating 2 Polynonials -");
            printf("        Calling create() -");
            createChanceV(headCV);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("  Have fun!\n\n");
            break;
        default:
            printf("  Wrong option!\n\n");
        }
    }
}

void runUpdateSubmenuChanceV(TPolyPtrChanceV* headCV)
{
    int optionCV = 0;

    while (optionCV != 4)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }
}

void createChanceV(TPolyPtrChanceV* headCV, int nTerms)
{
    TPolyPtrChanceV tailCV = *headCV;
    int doNextTerm = 1;
    int expo, num, denom;

    for (int poly = 0; poly < nTerms; poly++)
    {
        printf("        Creating Poly #%d -\n\n", poly+1);

        while (doNextTerm)
        {
            printf("          Is there a term (1 : yes, 0 : no)? ");
            scanf("%d", &doNextTerm);

            if (!doNextTerm)
                break;

            printf("            Enter expo: ");
            scanf("%d", &expo);

            printf("            Creating coeff Fraction: ");
            printf("              Enter num: ");
            scanf("%d", &num);
            printf("              Enter denom: ");
            scanf("%d", &denom);

            pushBackPolyChanceV(&tailCV,
                createPolyChanceV(
                    createPolyTermChanceV(expo, 
                        createFractionChanceV(num, denom)
                    )
                )
            );
        }

        doNextTerm = 1;

        tailCV = tailCV->nextCV;
    }
}

void pushBackPolyChanceV(TPolyPtrChanceV* tailCV, TPolyPtrChanceV addCV)
{
    if (*tailCV)
        (*tailCV)->nextCV = addCV;
    else
        *tailCV = addCV;
}

/*
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
*/