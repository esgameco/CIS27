#include "cis27ChanceVFinalUtility.h"

void displayClassInfoChanceV()
{
    printf("CIS 27 - Data Structures\n"
        "Laney College\n"
        "Chance Vodnoy\n\n"
        "Information --\n"
        "  Assignment:     Final Exam\n"
        "  Implemented by: Chance Vodnoy\n"
        "  Submitted Date: %s\n\n", DATE);
}

void displayMenuChanceV()
{
    printf("***********************************************\n"
           "*                MENU - Final                 *\n"
           "* (1) Creating/Updating 2 Polynomials         *\n"
           "* (2) Checking for Palindrome Polynomial      *\n"
           "* (3) Calling formPalindromePolynomial()      *\n"
           "* (4) Displaying 2 Polynomials                *\n"
           "* (5) Display resulting Palindrome Polynomial *\n"
           "* (6) Quit                                    *\n"
           "***********************************************\n");
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

    while (optionCV != 6)
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
            if (headCV)
            {
                printf("  Checking Palindrome -\n\n");
                isPalindromePolyChanceV(headCV, 1);
                isPalindromePolyChanceV(headCV->nextCV, 2);
                printf("\n");
            }
            else
                printf("  Not appropriate as there are no Polynomials!\n\n");
            break;
        case 3:
            if (headCV)
            {
                printf("  There is/are some Palindrome term(s) int the 2 polynomials.\n\n");
                printf("  Calling formPalindromePolynomial()!\n\n");
                printf("    Creating a new Palindrome polynomial -\n");
                deletePolyChanceV(&resultCV);
                resultCV = formPalindromePolynomialChanceV(headCV, headCV->nextCV);
                printf("      Degree: %d\n", resultCV->degreeCV);
                printf("      Number of Term(s): %d\n\n", resultCV->nTermsCV);
            }
            else
                printf("  Not appropriate as there are no Polynomials!\n\n");
            break;
        case 4:
            if (headCV)
            {
                printf("  Displaying 2 Polynomials -\n\n");
                displayPolynomialsChanceV(headCV, 4);
            }
            else
                printf("  Not appropriate as there are no Polynomials!\n\n");
            break;
        case 5:
            if (resultCV)
            {
                printf("  Displaying the resulting Polynomial -\n\n");
                displayPolynomialChanceV(resultCV, NULL, 4);
            }
            else
                printf("  There is no Palindrome Polynomial available!\n\n");
            break;
        case 6:
            printf("  Singing the song of whatever!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

    deleteAllPolysChanceV(&headCV);
    deleteAllPolysChanceV(&resultCV);
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
        case 3:
            printf("    There are no Polynomials available!\n\n");
            break;
        case 4:
            if (*headCV)
            {
                printf("    Displaying 2 Polynomials -\n\n");
                displayPolynomialsChanceV(*headCV, 6);
            }
            else
                printf("    There are no polynomials available!\n\n");
            break;
        case 5:
            printf("    Return to previous menu!\n\n");
            break;
        default:
            printf("    Wrong option!\n\n");
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

            if (!(*tailCV) || !(*tailCV)->polyTermNodeCV)
            {
                pushBackPolyChanceV(tailCV,
                    createPolyChanceV(
                        utilCreatePolyTermNodeChanceV(14)
                    )
                );
            }
            else
            {
                insertPolyTermNodeChanceV(*tailCV,
                    utilCreatePolyTermNodeChanceV(14)
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

TPolyTermPtrChanceV utilCreatePolyTermNodeChanceV(int nSpaces)
{
    int expo, num, denom;
    
    printf("%*sEnter expo: ", nSpaces, "");
    scanf("%d", &expo);

    printf("%*sCreating coeff Fraction: \n", nSpaces, "");
    printf("%*s  Enter num: ", nSpaces, "");
    scanf("%d", &num);
    printf("%*s  Enter denom: ", nSpaces, "");
    scanf("%d", &denom);

    return createPolyTermNodeChanceV(
        createPolyTermChanceV(expo,
            createFractionChanceV(num, denom)
        )
    );
}

TPolyTermNodePtrChanceV getPolyTermNodeChanceV(TPolyPtrChanceV polyCV, int expo)
{
    TPolyTermNodePtrChanceV iterCV = polyCV->polyTermNodeCV;

    while (iterCV)
    {
        if (iterCV->termCV->expoCV == expo)
            return iterCV;

        iterCV = iterCV->nextCV;
    }

    return NULL;
}

TPolyPtrChanceV formPalindromePolynomialChanceV(
    TPolyPtrChanceV poly1CV,
    TPolyPtrChanceV poly2CV)
{
    TPolyPtrChanceV resultCV = createPolyChanceV(NULL);
    TPolyTermNodePtrChanceV iterCV = poly1CV->polyTermNodeCV;
    TPolyTermNodePtrChanceV otherTermCV;

    while (iterCV)
    {
        otherTermCV = getPolyTermNodeChanceV(poly2CV, iterCV->termCV->expoCV);

        if (checkFractionPalindromeChanceV(iterCV->termCV->fractionCV))
        {
            if (otherTermCV && checkFractionPalindromeChanceV(otherTermCV->termCV->fractionCV))
            {
                insertPolyTermNodeChanceV(resultCV,
                    createPolyTermNodeChanceV(
                        createPolyTermChanceV(iterCV->termCV->expoCV,
                            addFractionsChanceV(iterCV->termCV->fractionCV,
                                otherTermCV->termCV->fractionCV
                            )
                        )
                    )
                );
            }
            else
            {
                insertPolyTermNodeChanceV(resultCV, iterCV);
            }
        }

        iterCV = iterCV->nextCV;
    }

    iterCV = poly2CV->polyTermNodeCV;

    while (iterCV)
    {
        otherTermCV = getPolyTermNodeChanceV(resultCV, iterCV->termCV->expoCV);

        if (!otherTermCV)
        {
            if (checkFractionPalindromeChanceV(iterCV->termCV->fractionCV))
                insertPolyTermNodeChanceV(resultCV, iterCV);
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

void displayPolynomialChanceV(TPolyPtrChanceV polyCV, int polyNum, int nSpaces)
{
    TPolyTermNodePtrChanceV iterCV = polyCV->polyTermNodeCV;
    int nodeNum = 1;

    if (polyNum)
        printf("%*sPoly #%d -\n", nSpaces, "", polyNum);
    printf("%*s  Address: %p\n", nSpaces, "", polyCV);
    printf("%*s  Degree: %d\n", nSpaces, "", polyCV->degreeCV);
    printf("%*s  Number of Terms: %d\n", nSpaces, "", polyCV->nTermsCV);
    printf("%*s  Address of first node: %p\n\n", nSpaces, "", iterCV);

    while (iterCV)
    {
        printf("%*s  Node #%d -\n", nSpaces, "", nodeNum);
        printf("%*s    Address of Node %d: %p\n", nSpaces, "", nodeNum, iterCV);
        printf("%*s    Address of term: %p\n", nSpaces, "", iterCV->termCV);
        printf("%*s    Address of next node: %p\n\n", nSpaces, "", iterCV->nextCV);

        printf("%*s      Term #%d -\n", nSpaces, "", nodeNum);
        printf("%*s        Address: %p\n", nSpaces, "", iterCV->termCV);
        printf("%*s        Expo: %d\n", nSpaces, "", iterCV->termCV->expoCV);
        printf("%*s        Coefficient -\n", nSpaces, "");
        printf("%*s          Address: %p\n", nSpaces, "", iterCV->termCV->fractionCV);
        printf("%*s          num: %d\n", nSpaces, "", iterCV->termCV->fractionCV->numCV);
        printf("%*s          denom: %d\n", nSpaces, "", iterCV->termCV->fractionCV->denCV);
        printf("\n");

        iterCV = iterCV->nextCV;
        nodeNum++;
    }
}

void displayPolynomialsChanceV(TPolyPtrChanceV headCV, int nSpaces)
{
    int termNum;
    int polyNum = 1;

    while (headCV)
    {
        displayPolynomialChanceV(headCV, polyNum, nSpaces);

        headCV = headCV->nextCV;
        polyNum++;
    }
}

int isPalindromePolyChanceV(TPolyPtrChanceV headCV, int polyNum)
{
    TPolyTermNodePtrChanceV iterCV = headCV->polyTermNodeCV;
    int arePalin = 1;

    if (!iterCV)
    {
        printf("  Not appropriate as there is no list (or empty list)!\n\n");
        return 0;
    }

    while (iterCV)
    {
        if (!checkFractionPalindromeChanceV(iterCV->termCV->fractionCV))
            arePalin = 0;
        iterCV = iterCV->nextCV;
    }

    iterCV = NULL;

    if (polyNum)
        printf("    Poly #%d is %s \n",
            polyNum,
            arePalin ?
            "a Palindrome" : "NOT a Palindrome");
    return arePalin;
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