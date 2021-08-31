/**
 * Program Name: cis27Fall2021ChanceVHw1.c
 * Discussion:   Final
 * Written By:   Chance Vodnoy
 * Date:         2021/8/26
*/

#define HW_NUM 1
#define DATE "2021/09/09"

#define BUFFER_SIZE 20
#define DIGIT_SIZE 10

#include <stdio.h>

void displayClassInfoChanceV();
void displayMenuChanceV();
void runMenuChanceV();
void displayFunDigitInfoChanceV(int);
void getDigitsChanceV(int, int[], int*, int*, int);

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
    printf("********************************************\n"
        "*             MENU - Final Exam            *\n"
        "* (1) Calling displayFunDigitInfoChanceV() *\n"
        "* (2) Quit                                 *\n"
        "********************************************\n");
}

void runMenuChanceV()
{
    int inputCV = 0;
    int optionCV = 0;

    while (optionCV != 2)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf_s("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            printf("Enter an integer: ");
            scanf_s("%d", &inputCV);

            printf("\nCalling displayFunDigitInfoChanceV() with argument of %d --\n\n", inputCV);
            displayFunDigitInfoChanceV(inputCV);
            break;
        case 2:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

}

void displayFunDigitInfoChanceV(int inputCV)
{
    int digitsCV[BUFFER_SIZE] = { 0 };
    int numDigitsCV = 0;
    int totalDigitsCV = 0;
    int isEvenCV = (inputCV % 2) ? 0 : 1;

    printf("  While displayFunDigitInfoChanceV() is running -\n\n");

    getDigitsChanceV(inputCV, digitsCV, &numDigitsCV, &totalDigitsCV, isEvenCV);

    if (inputCV)
        printf("  %d is a %s and %s integer.\n", inputCV,
            (inputCV > 0) ? "positive" : "negative",
            (isEvenCV) ? "even" : "odd");
    else
    {
        printf("  ZERO is given!\n\n"
            "  How many digit(s)? 1\n\n"
            "  Only the martian can claim ZERO is, perhaps, not EVEN!\n\n");
        return;
    }
    printf("  There must be at least ONE %s digit!\n\n", (isEvenCV) ? "even" : "odd");

    printf("  Actually, there is/are %d %s digit(s) of\n", numDigitsCV, (isEvenCV) ? "even" : "odd");
    for (int i = 0; i < numDigitsCV; i++)
        printf("    %d\n", digitsCV[i]);
    printf("\n");

    if (!numDigitsCV)
        return;

    printf("  The last %s digit seen from the LSD (toward the MSD) is\n", (isEvenCV) ? "even" : "odd");
    printf("    %d\n", digitsCV[numDigitsCV - 1]);
    printf("\n");

    printf("   And, there is/are %d %s digit(s).\n", totalDigitsCV - numDigitsCV, (isEvenCV) ? "odd" : "even");
    printf("\n");
}

void getDigitsChanceV(int valueCV, int arrBufferCV[], int* numDigitsCV, int* totalDigitsCV, int useEvenCV)
{
    int countCV = 0;
    int digitsCV = 0;
    valueCV = (valueCV < 0) ? -valueCV : valueCV;

    while (valueCV)
    {
        if (valueCV % 2 != useEvenCV)
        {
            arrBufferCV[digitsCV] = valueCV % 10;
            digitsCV++;
        }
        valueCV /= 10;
        countCV++;
        (*totalDigitsCV)++;
    }

    *numDigitsCV = digitsCV;
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

/* Logic_Code_Output_Issues:

No Comments!

*/