/**
 * Program Name: cis27Fall2021ChanceVHw2.c
 * Discussion:   HW #2 - Menu Application
 * Written By:   Chance Vodnoy
 * Date:         2021/9/14
*/

#define HW_NUM 2
#define DATE "2021/09/23"

#define BUFFER_SIZE 20
#define DIGIT_SIZE 10

#include <stdio.h>

void displayClassInfoChanceV();
void displayMenuChanceV();
void runMenuChanceV();
void displayOddDigitForArrayChanceV(int[], int);
void getDigitsChanceV(int, int[], int*, int*, int);
void getOccurrencesChanceV(int[], int, int[]);
int getNumDigitsCV(int[]);

int main()
{
    displayClassInfoChanceV();
    runMenuChanceV();

    return 0;
}

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
    printf("************************************************\n"
           "*               MENU - Homework 2              *\n"
           "* (1) Calling displayOddDigitForArrayChanceV() *\n"
           "* (2) Quit                                     *\n"
           "************************************************\n");
}

void runMenuChanceV()
{
    int numIntsCV = 0;
    int optionCV = 0;
    int intsCV[BUFFER_SIZE];

    while (optionCV != 2)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf_s("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("How many int's? ");
            scanf_s("%d", &numIntsCV);
            printf("\n");

            for (int i = 0; i < numIntsCV; i++)
            {
                printf("Enter value #%d: ", i+1);
                scanf_s("%d", &intsCV[i]);
            }

            printf("\nCalling displayOddDigitForArrayChanceV()"
                " with an array of size %d --\n\n", numIntsCV);
            displayOddDigitForArrayChanceV(intsCV, numIntsCV);
            break;
        case 2:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

}

void displayOddDigitForArrayChanceV(int intArrCV[], int arrSize)
{
    int oddDigitsCV[BUFFER_SIZE] = { 0 };
    int occurencesCV[DIGIT_SIZE] = { 0 };
    int numDigitsCV = 0;
    int currentIndexCV = 0;
    int largestOddDigitCV = 0;

    for (int i = 0; i < arrSize; i++)
        getDigitsChanceV(
            intArrCV[i], oddDigitsCV, &numDigitsCV, &currentIndexCV, 0);
    getOccurrencesChanceV(oddDigitsCV, currentIndexCV, &occurencesCV);

    printf("  There is/are %d odd digits of\n", currentIndexCV);
    for (int i = 0; i < currentIndexCV; i++)
        printf("    %d\n", oddDigitsCV[i]);

    for (int i = 9; i > 0; i -= 2)
        if (occurencesCV[i] > 0)
        {
            largestOddDigitCV = i;
            printf("  The largest odd digit is %d, which is seen %d time(s).\n\n",
                largestOddDigitCV, occurencesCV[largestOddDigitCV]);
            break;
        }

    printf("  There is/are %d other unique odd digit(s) as follows,\n",
        getNumDigitsCV(occurencesCV)-1);
    for (int i = 1; i < largestOddDigitCV; i += 2)
        if (occurencesCV[i] > 0)
            printf("    Digit %d seen %d time(s)\n",
                i, occurencesCV[i]);
    printf("\n");
}

void getDigitsChanceV(int valueCV, int arrBufferCV[], int* numDigitsCV, int* currentIndexCV, int useEvenCV)
{
    int digitsCV = 0;
    valueCV = (valueCV < 0) ? -valueCV : valueCV;

    while (valueCV)
    {
        if (valueCV % 2 != useEvenCV)
        {
            arrBufferCV[*currentIndexCV+digitsCV] = valueCV % 10;
            digitsCV++;
        }
        valueCV /= 10;
    }

    *numDigitsCV = digitsCV;
    *currentIndexCV += digitsCV;
}

void getOccurrencesChanceV(int digitsCV[], int digitSizeCV, int occurrencesBufferCV[])
{
    for (int i = 0; i < digitSizeCV; i++)
        occurrencesBufferCV[digitsCV[i]]++;
}

int getNumDigitsCV(int digitsCV[])
{
    int numDigitsCV = 0;

    for (int i = 0; i < DIGIT_SIZE; i++)
        if (digitsCV[i] > 0)
            numDigitsCV++;

    return numDigitsCV;
}

/* PROGRAM_OUTPUT:

// OUTPUT - Sample Run

CIS 27-Data Structures
Laney College
Chance Vodnoy

Information --
  Assignment: HW #1
  Implemented by: Chance Vodnoy
  Submitted Date: 2021/09/09
  Current Number of LEB available: 2
  Allowed Number of LEB Used: 0
  Remaining Number of LEB: 2

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 6

Wrong option!

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: -1

Wrong option!

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 1

Enter an integer: -9

Calling displayFunDigitInfoChanceV() with argument of -9 --

  While displayFunDigitInfoChanceV() is running -

  -9 is a negative and odd integer.
  There must be at least ONE odd digit!

  Actually, there is/are 1 odd digit(s) of
    9

  The last odd digit seen from the LSD (toward the MSD) is
    9

   And, there is/are 0 even digit(s).

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 1

Enter an integer: -13054

Calling displayFunDigitInfoChanceV() with argument of -13054 --

  While displayFunDigitInfoChanceV() is running -

  -13054 is a negative and even integer.
  There must be at least ONE even digit!

  Actually, there is/are 2 even digit(s) of
    4
    0

  The last even digit seen from the LSD (toward the MSD) is
    0

   And, there is/are 3 odd digit(s).

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 1

Enter an integer: 3450486

Calling displayFunDigitInfoChanceV() with argument of 3450486 --

  While displayFunDigitInfoChanceV() is running -

  3450486 is a positive and even integer.
  There must be at least ONE even digit!

  Actually, there is/are 5 even digit(s) of
    6
    8
    4
    0
    4

  The last even digit seen from the LSD (toward the MSD) is
    4

   And, there is/are 2 odd digit(s).

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 1

Enter an integer: 80316539

Calling displayFunDigitInfoChanceV() with argument of 80316539 --

  While displayFunDigitInfoChanceV() is running -

  80316539 is a positive and odd integer.
  There must be at least ONE odd digit!

  Actually, there is/are 5 odd digit(s) of
    9
    3
    5
    1
    3

  The last odd digit seen from the LSD (toward the MSD) is
    3

   And, there is/are 3 even digit(s).

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 1

Enter an integer: 0

Calling displayFunDigitInfoChanceV() with argument of 0 --

  While displayFunDigitInfoChanceV() is running -

  ZERO is given!

  How many digit(s)? 1

  Only the martian can claim ZERO is, perhaps, not EVEN!

********************************************
*             MENU - Final Exam            *
* (1) Calling displayFunDigitInfoChanceV() *
* (2) Quit                                 *
********************************************
Enter an integer for option + ENTER: 2

Have fun!

*/

/* LOGIC_CODE_OUTPUT_Issues:

No Comments!

*/