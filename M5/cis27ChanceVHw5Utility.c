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
    printf("    *********************************\n"
           "    *         init() Submenu        *\n"
           "    * (1) Creating 2 Polynomials    *\n"
           "    * (2) Updating Polynomial 1     *\n"
           "    * (3) Updating Polynomial 2     *\n"
           "    * (4) Displaying 2 Polynomials  *\n"
           "    * (5) Return                    *\n"
           "    *********************************\n");
}

void displayUpdateSubmenuChanceV()
{
    printf("        *************************************\n"
           "        *          update() Submenu         *\n"
           "        * (1) Adding one term               *\n"
           "        * (2) Removing one term             *\n"
           "        * (3) Displaying updated Polynomial *\n"
           "        * (4) Return                        *\n"
           "        *************************************\n");
}

void runMenuChanceV()
{
    int optionCV = 0;
    TPolyPtrChanceV headCV = NULL;
    TPolyPtrChanceV resultCV = NULL;

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
            evaluateChanceV(headCV, &resultCV);
            break;
        case 3:
            printf("  Checking Palindrome -\n\n");
            checkFractionPalindromesChanceV(headCV, 1);
            printf("\n");
            checkFractionPalindromesChanceV(headCV->nextCV, 2);
            printf("\n");
            break;
        case 4:
            printf("  Adding 2 Polynomials -\n\n");
            deletePolyChanceV(&resultCV);
            resultCV = addPolynomialsChanceV(headCV, headCV->nextCV);
            break;
        case 5:
            printf("  Multiplying 2 Polynomials -\n\n");
            deletePolyChanceV(&resultCV);
            resultCV = multiplyPolynomialsChanceV(headCV, headCV->nextCV);
            displayPolynomialChanceV(resultCV, NULL);
            break;
        case 6:
            if (headCV)
                printf("  Displaying 2 Polynomials -\n\n");
            else
                printf("  Not appropriate as there are no Polynomials!\n\n");
            displayPolynomialsChanceV(headCV);
            break;
        case 7:
            printf("  Displaying the resulting Polynomial -\n\n");
            displayPolynomialChanceV(resultCV, NULL);
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
        printf("    Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("    Creating 2 Polynonials -\n\n");
            printf("      Calling create() -\n\n");
            createChanceV(headCV, 2);
            break;
        case 2:
            if (*headCV)
            {
                printf("      Updating Polynomial #1\n\n");
                runUpdateSubmenuChanceV(*headCV, 1);
            }
            else
                printf("    Not appropriate as there are no Polynomials!\n\n");
            break;
        case 3:
            if (*headCV && (*headCV)->nextCV)
            {
                printf("      Updating Polynomial #2\n\n");
                runUpdateSubmenuChanceV((*headCV)->nextCV, 2);
            }
            else
                printf("    Not appropriate as there are no Polynomials!\n\n");
            break;
        case 4:
            if (*headCV)
            {
                printf("      Display Polynomials -\n\n");
                displayPolynomialsChanceV(*headCV);
            }
            else
                printf("    Wrong Option!\n\n");
            break;
        case 5:
            printf("    Return to previous menu!\n\n");
            break;
        default:
            printf("    Wrong option!\n\n");
        }
    }
}

void runUpdateSubmenuChanceV(TPolyPtrChanceV polyCV, int polyNum)
{
    int optionCV = 0;

    while (optionCV != 4)
    {
        displayUpdateSubmenuChanceV();
        printf("        Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("          Adding 1 term -\n");
            insertPolyTermChanceV(polyCV, 
                utilCreatePolyTermChanceV());
            printf("\n");
            break;
        case 2:
            if (!polyCV)
                printf("    Not appropriate as there are no Polynomials!");
            break;
        case 3:
            displayPolynomialChanceV(polyCV, polyNum);
            break;
        case 4:
            printf("        Return to previous menu!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }
}

void createChanceV(TPolyPtrChanceV* headCV, int nTerms)
{
    TPolyPtrChanceV* tailCV = headCV;
    int doNextTerm = 1;
    

    for (int poly = 0; poly < nTerms; poly++)
    {
        printf("          Creating Poly #%d -\n\n", poly+1);

        while (doNextTerm)
        {
            printf("            Is there a term (1 : yes, 0 : no)? ");
            scanf("%d", &doNextTerm);

            if (!doNextTerm)
                break;

            if (!(*tailCV) || !(*tailCV)->polyTermCV)
            {
                pushBackPolyChanceV(tailCV,
                    createPolyChanceV(
                        utilCreatePolyTermChanceV()
                    )
                );
            }
            else
            {
                insertPolyTermChanceV(*tailCV,
                    utilCreatePolyTermChanceV()
                );
            }
            printf("\n");
        }
        printf("\n");
        doNextTerm = 1;

        if (*tailCV)
            tailCV = &((*tailCV)->nextCV);
    }
}

TPolyTermPtrChanceV utilCreatePolyTermChanceV()
{
    int expo, num, denom;

    printf("              Enter expo: ");
    scanf("%d", &expo);

    printf("              Creating coeff Fraction: \n");
    printf("                Enter num: ");
    scanf("%d", &num);
    printf("                Enter denom: ");
    scanf("%d", &denom);
    return createPolyTermChanceV(expo,
        createFractionChanceV(num, denom)
    );
}

void evaluateChanceV(TPolyPtrChanceV headCV)
{
    TFractionPtrChanceV resultCV, xCV = NULL;
    int numCV, denCV;

    printf("    Enter the value (Fraction) to be evaluated with -\n");
    printf("      num: ");
    scanf("%d", &numCV);
    printf("      denom: ");
    scanf("%d", &denCV);
    xCV = createFractionChanceV(numCV, denCV);
    printf("\n");
    
    for (int i = 0; i < 2; i++)
    {
        if (!headCV || !headCV->polyTermCV)
            break;

        resultCV = evaluatePolyChanceV(headCV, xCV);
        printf("    Poly #%d at x = (%d/%d): (%d/%d)\n",
            i+1,
            xCV->numCV, xCV->denCV,
            resultCV->numCV, resultCV->denCV);
        headCV = headCV->nextCV;
        freeFractionChanceV(resultCV);
    }
    printf("\n");

    deleteFractionChanceV(&xCV);
}

TPolyTermPtrChanceV getPolyTermChanceV(TPolyPtrChanceV polyCV, int expo)
{
    TPolyTermPtrChanceV iterCV = polyCV->polyTermCV;

    while (iterCV)
    {
        if (iterCV->expoCV == expo)
            return iterCV;

        iterCV = iterCV->nextCV;
    }

    return NULL;
}

TPolyPtrChanceV addPolynomialsChanceV(
    TPolyPtrChanceV poly1CV, 
    TPolyPtrChanceV poly2CV)
{
    TPolyPtrChanceV resultCV = createPolyChanceV(NULL);
    TPolyTermPtrChanceV iterCV = poly1CV->polyTermCV;
    TPolyTermPtrChanceV otherTermCV;

    while (iterCV)
    {
        otherTermCV = getPolyTermChanceV(poly2CV, iterCV->expoCV);

        if (otherTermCV)
        {
            insertPolyTermChanceV(resultCV,
                createPolyTermChanceV(iterCV->expoCV,
                    addFractionsChanceV(iterCV->fractionCV,
                        otherTermCV->fractionCV
                    )
                )
            );
        }
        else
        {
            insertPolyTermChanceV(resultCV, iterCV);
        }

        iterCV = iterCV->nextCV;
    }

    iterCV = poly2CV->polyTermCV;

    while (iterCV)
    {
        otherTermCV = getPolyTermChanceV(resultCV, iterCV->expoCV);

        if (!otherTermCV)
        {
            insertPolyTermChanceV(resultCV, iterCV);
        }

        iterCV = iterCV->nextCV;
    }

    return resultCV;
}

TPolyPtrChanceV multiplyPolynomialsChanceV(
    TPolyPtrChanceV poly1CV,
    TPolyPtrChanceV poly2CV)
{
    TPolyPtrChanceV resultCV = createPolyChanceV(NULL);
    TPolyTermPtrChanceV iterCV = poly1CV->polyTermCV;
    TPolyTermPtrChanceV otherTermCV;

    while (iterCV)
    {
        otherTermCV = getPolyTermChanceV(poly2CV, iterCV->expoCV);

        if (otherTermCV)
        {
            insertPolyTermChanceV(resultCV,
                createPolyTermChanceV(iterCV->expoCV,
                    multiplyFractionsChanceV(iterCV->fractionCV,
                        otherTermCV->fractionCV
                    )
                )
            );
        }
        else
        {
            insertPolyTermChanceV(resultCV, iterCV);
        }

        iterCV = iterCV->nextCV;
    }

    iterCV = poly2CV->polyTermCV;

    while (iterCV)
    {
        otherTermCV = getPolyTermChanceV(resultCV, iterCV->expoCV);

        if (!otherTermCV)
        {
            insertPolyTermChanceV(resultCV, iterCV);
        }

        iterCV = iterCV->nextCV;
    }

    return resultCV;
}

void pushBackPolyChanceV(TPolyPtrChanceV* tailCV, TPolyPtrChanceV addCV)
{
    if (*tailCV)
        (*tailCV)->nextCV = addCV;
    else
        *tailCV = addCV;
}

void displayPolynomialChanceV(TPolyPtrChanceV polyCV, int polyNum)
{
    TPolyTermPtrChanceV termIterPtr = polyCV->polyTermCV;
    int termNum = 1;

    if (polyNum)
        printf("            Poly #%d -\n\n", polyNum);
    printf("              Address: %p\n", polyCV);
    printf("              Degree: %d\n", polyCV->degreeCV);
    printf("              Number of Terms: %d\n\n", polyCV->nTermsCV);

    while (termIterPtr)
    {
        printf("              Term #%d -\n", termNum);
        printf("                Address: %p\n", termIterPtr);
        printf("                Expo: %d\n", termIterPtr->expoCV);
        printf("                  Coefficient -\n");
        printf("                    Address: %p\n", termIterPtr->fractionCV);
        printf("                    num: %d\n", termIterPtr->fractionCV->numCV);
        printf("                    denom: %d\n", termIterPtr->fractionCV->denCV);
        printf("\n");

        if (termIterPtr->nextCV)
            termIterPtr = termIterPtr->nextCV;
        else
            break;

        termNum++;
    }
    printf("\n");
}

void displayPolynomialsChanceV(TPolyPtrChanceV headCV)
{
    TPolyTermPtrChanceV termIterPtr;
    int termNum;
    int polyNum = 1;

    while (headCV)
    {
        displayPolynomialChanceV(headCV, polyNum);

        if (headCV->nextCV)
            headCV = headCV->nextCV;
        else
            break;

        polyNum++;
    }
}

void checkFractionPalindromesChanceV(TPolyPtrChanceV headCV, int polyNum)
{
    TPolyTermPtrChanceV iterCV = headCV->polyTermCV;
    int arePalin = 1;

    if (!iterCV)
    {
        printf("  Not appropriate as there is no list (or empty list)!\n\n");
        return 0;
    }

    while (iterCV)
    {
        if (!checkFractionPalindromeChanceV(iterCV->fractionCV))
            arePalin = 0;
        iterCV = iterCV->nextCV;
    }

    printf("    Poly #%d is %s \n\n",
        polyNum,
        arePalin ?
        "a Palindrome" : "not a Palindrome");

    iterCV = NULL;
}

int checkFractionPalindromeChanceV(TFractionPtrChanceV fractionCV)
{
    int* numDigits = getDigitsChanceV(fractionCV->numCV);
    int* denDigits = getDigitsChanceV(fractionCV->denCV);
    int isPalindrome = checkPalindromeChanceV(numDigits) &&
        checkPalindromeChanceV(denDigits);

    free(numDigits);
    free(denDigits);

    return isPalindrome;
}

int checkPalindromeChanceV(int* digits)
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

int* getDigitsChanceV(int value)
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

/*


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