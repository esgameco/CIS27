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
           "*                 MENU - HW #2                 *\n"
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
                " with an array of size %d -\n\n", numIntsCV);
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
  Assignment: HW #2
  Implemented by: Chance Vodnoy
  Submitted Date: 2021/09/23
  Current Number of LEB available: 2
  Allowed Number of LEB Used: 0
  Remaining Number of LEB: 2

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 6

Wrong option!

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: -1

Wrong option!

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 1

How many int's? 2

Enter value #1: -9
Enter value #2: 365

Calling displayOddDigitForArrayChanceV() with an array of size 2 -

  There is/are 3 odd digits of
    9
    5
    3
  The largest odd digit is 9, which is seen 1 time(s).

  There is/are 2 other unique odd digit(s) as follows,
    Digit 3 seen 1 time(s)
    Digit 5 seen 1 time(s)

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 1

How many int's? 3

Enter value #1: 365
Enter value #2: -9
Enter value #3: 3635

Calling displayOddDigitForArrayChanceV() with an array of size 3 -

  There is/are 6 odd digits of
    5
    3
    9
    5
    3
    3
  The largest odd digit is 9, which is seen 1 time(s).

  There is/are 2 other unique odd digit(s) as follows,
    Digit 3 seen 3 time(s)
    Digit 5 seen 2 time(s)

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 1

How many int's? 4

Enter value #1: 365
Enter value #2: -9
Enter value #3: 36359
Enter value #4: -45677654

Calling displayOddDigitForArrayChanceV() with an array of size 4 -

  There is/are 11 odd digits of
    5
    3
    9
    9
    5
    3
    3
    5
    7
    7
    5
  The largest odd digit is 9, which is seen 2 time(s).

  There is/are 3 other unique odd digit(s) as follows,
    Digit 3 seen 3 time(s)
    Digit 5 seen 4 time(s)
    Digit 7 seen 2 time(s)

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 2

Have fun!

*/

/* LOGIC_CODE_OUTPUT_Issues:

No Comments!

*/