/**
 * Program Name: cis27Fall2021ChanceVHw2.c
 * Discussion:   HW #3 - Fraction Application
 * Written By:   Chance Vodnoy
 * Date:         2021/10/17
*/

#include <stdio.h>
#include "cis27ChanceVHw3Utility.h"

int main()
{
    displayClassInfoChanceV();
    runMenuChanceV();

    return 0;
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
