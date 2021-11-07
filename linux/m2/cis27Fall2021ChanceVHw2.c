/**
 * Program Name: cis27Fall2021ChanceVHw2.c
 * Discussion:   HW #2 - Menu Application
 * Written By:   Chance Vodnoy
 * Date:         2021/10/4
*/

#define HW_NUM 2
#define DATE "2021/10/04"

#define BUFFER_SIZE 20
#define DIGIT_SIZE 10

#include <stdio.h>
#include "cis27ChanceVHw2Utility.h"

void displayClassInfoChanceV();
void displayMenuChanceV();
void runMenuChanceV();

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
    int* intsCV;

    while (optionCV != 2)
    {
        displayMenuChanceV();
        printf("Enter an integer for option + ENTER: ");
        scanf("%d", &optionCV);
        printf("\n");

        switch (optionCV)
        {
        case 1:
            while (numIntsCV <= 0)
            {
                printf("How many int's (> 0)? ");
                scanf("%d", &numIntsCV);
            }
            printf("\n");

            intsCV = malloc(sizeof(int) * numIntsCV);

            for (int i = 0; i < numIntsCV; i++)
            {
                printf("Enter value #%d: ", i + 1);
                scanf("%d", &intsCV[i]);
            }

            printf("\nCalling displayOddDigitForArrayChanceV()"
                " with an array of size %d -\n\n", numIntsCV);
            displayOddDigitForArrayChanceV(intsCV, numIntsCV);

            free(intsCV);
            numIntsCV = -1;

            break;
        case 2:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

}

/* PROGRAM_OUTPUT:

// OUTPUT - Sample Run

CIS 27-Data Structures
Laney College
Chance Vodnoy

Information --
  Assignment: HW #2
  Implemented by: Chance Vodnoy
  Submitted Date: 2021/10/04
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

How many int's (> 0)? 0
How many int's (> 0)? -2
How many int's (> 0)? 2

Enter value #1: -8
Enter value #2: 24

Calling displayOddDigitForArrayChanceV() with an array of size 2 -

  While displayOddDigitForArrayChanceV() is running -

    There are no odd digits!

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 1

How many int's (> 0)? 0
How many int's (> 0)? -2
How many int's (> 0)? 2

Enter value #1: -18
Enter value #2: 24

Calling displayOddDigitForArrayChanceV() with an array of size 2 -

  While displayOddDigitForArrayChanceV() is running -

    There is/are 1 odd digits of
      1
    The largest odd digit is 1, which is seen 1 time(s).

    There is/are 0 other unique odd digit(s)!

************************************************
*                 MENU - HW #2                 *
* (1) Calling displayOddDigitForArrayChanceV() *
* (2) Quit                                     *
************************************************
Enter an integer for option + ENTER: 1

How many int's (> 0)? 0
How many int's (> 0)? -2
How many int's (> 0)? 2

Enter value #1: -9
Enter value #2: 365

Calling displayOddDigitForArrayChanceV() with an array of size 2 -

  While displayOddDigitForArrayChanceV() is running -

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

How many int's (> 0)? 3

Enter value #1: 365
Enter value #2: -9
Enter value #3: 3635

Calling displayOddDigitForArrayChanceV() with an array of size 3 -

  While displayOddDigitForArrayChanceV() is running -

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

How many int's (> 0)? -4
How many int's (> 0)? 4

Enter value #1: 365
Enter value #2: -9
Enter value #3: 36359
Enter value #4: -45677654

Calling displayOddDigitForArrayChanceV() with an array of size 4 -

  While displayOddDigitForArrayChanceV() is running -

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
