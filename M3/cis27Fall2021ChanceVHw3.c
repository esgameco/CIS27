/**
 * Program Name: cis27Fall2021ChanceVHw3.c
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
  Assignment: HW #3
  Implemented by: Chance Vodnoy
  Submitted Date: 2021/10/17
  Current Number of LEB available: 2
  Allowed Number of LEB Used: 0
  Remaining Number of LEB: 2

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 6

Wrong option!

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 2

  Not appropriate as there are no Fraction objects!

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 4

Cannot choose this option as there are no Fraction objects!

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 1

  Creating/Updating 2 Fraction Data Objects -

    ***************************************
    *     Creating/Updating Submenu       *
    * (1) Creating 2 Fraction objects     *
    * (2) Updating First Fraction object  *
    * (3) Updating Second Fraction object *
    * (4) Returning                       *
    ***************************************
    Enter an integer for option + ENTER: 1

      No Fraction Objects exist --
        Creating Process --
          First Fraction:
            Enter an int for num: 5
            Enter an int for denom: -9

          Second Fraction:
            Enter an int for num: 5
            Enter an int for denom: 0
              0 is not allowed!

            Enter an int for denom: -150

    ***************************************
    *     Creating/Updating Submenu       *
    * (1) Creating 2 Fraction objects     *
    * (2) Updating First Fraction object  *
    * (3) Updating Second Fraction object *
    * (4) Returning                       *
    ***************************************
    Enter an integer for option + ENTER: 4

    Returning to previous menu!

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 4

      Displaying Fraction Objects -

        First Object --
          Address: 01055588
          num: -5
          denom: 9

        Second Object --
          Address: 01055440
          num: -1
          denom: 30

        Resulting Object --
          Not Existing!

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 2

    First Fraction: Yes
    Second Fraction: No

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 3

    ***************************************
    *     Arithmetic Operations Submenu   *
    * (1) Adding                          *
    * (2) Multiplying                     *
    * (3) Returning                       *
    ***************************************
    Enter an integer for option + ENTER: 1

      Adding (First + Second --> Result)!

    ***************************************
    *     Arithmetic Operations Submenu   *
    * (1) Adding                          *
    * (2) Multiplying                     *
    * (3) Returning                       *
    ***************************************
    Enter an integer for option + ENTER: 3

    Return to Previous Menu

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 4

      Displaying Fraction Objects -

        First Object --
          Address: 01055588
          num: -5
          denom: 9

        Second Object --
          Address: 01055440
          num: -1
          denom: 30

        Resulting Object --
          Address: 01059B60
          num: -53
          denom: 90

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 1

  Creating/Updating 2 Fraction Data Objects -

    ***************************************
    *     Creating/Updating Submenu       *
    * (1) Creating 2 Fraction objects     *
    * (2) Updating First Fraction object  *
    * (3) Updating Second Fraction object *
    * (4) Returning                       *
    ***************************************
    Enter an integer for option + ENTER: 1

      Fraction Objects exist - Choose Update or Quit!

    ***************************************
    *     Creating/Updating Submenu       *
    * (1) Creating 2 Fraction objects     *
    * (2) Updating First Fraction object  *
    * (3) Updating Second Fraction object *
    * (4) Returning                       *
    ***************************************
    Enter an integer for option + ENTER: 2

      Fraction Objects exist --
        Updating Process --
          First Object --
            Enter an int for num: 5
            Enter an int for denom: 0
              0 is not allowed!

            Enter an int for denom: -20

    Returning to previous menu!

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 4

      Displaying Fraction Objects -

        First Object --
          Address: 01055700
          num: -1
          denom: 4

        Second Object --
          Address: 01055440
          num: -1
          denom: 30

        Resulting Object --
          Address: 01059B60
          num: -53
          denom: 90

**************************************************
*                 MENU - HW #3                   *
* (1) Creating/Updating 2 Fraction Data Objects  *
* (2) Checking for Palindrome                    *
* (3) Performing Arithmetic Operations (+, -, *) *
* (4) Displaying Selected Fraction Data Object   *
* (5) Quit                                       *
**************************************************
Enter an integer for option + ENTER: 5

Have fun!

*/

/* LOGIC_CODE_OUTPUT_Issues:

No Comments!

*/
