/**
 * Program Name: cis27Fall2021ChanceVHw5.c
 * Discussion:   HW #5 - Fraction Application
 * Written By:   Chance Vodnoy
 * Date:         2021/11/11
*/

#include <stdio.h>
#include "cis27ChanceVHw5Utility.h"

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
  Assignment: HW #4
  Implemented by: Chance Vodnoy
  Submitted Date: 2021/11/07
  Current Number of LEB available: 2
  Allowed Number of LEB Used: 0
  Remaining Number of LEB: 2

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 7

Wrong option!

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 2

  Checking for Palindrome -

  Not appropriate as there is no list (or empty list)!

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 1

  Creating Fraction List using insertFirstChanceV() -

    Creating a Fraction --
      Enter an int for num: 5
      Enter an int for denom: 0
        0 is not allowed!

      Enter an int for denom: -9

    Creating a Fraction node ...

    Inserting Fraction node to become first node ...

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 5

  Displaying Fraction list -

    Node #1:
      Address: 015C5528
      Fraction:
        num: -5
        denom: 9
      next: 0

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 2

  Checking for Palindrome -

    A Palindrome Fraction at
      Address: 015C5528
      Fraction:
        num: -5
        denom: 9

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 3

  Inserting Fraction List using insertFirstChanceV() -

    Creating a Fraction --
      Enter an int for num: 1
      Enter an int for denom: 0
        0 is not allowed!

      Enter an int for denom: -202

    Creating a Fraction node ...

    Inserting Fraction node to become first node ...

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 5

  Displaying Fraction list -

    Node #1:
      Address: 015C53A8
      Fraction:
        num: -1
        denom: 202
      next: 015C5528

    Node #2:
      Address: 015C5528
      Fraction:
        num: -5
        denom: 9
      next: 0

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 2

  Checking for Palindrome -

    A Palindrome Fraction at
      Address: 015C53A8
      Fraction:
        num: -1
        denom: 202

    A Palindrome Fraction at
      Address: 015C5528
      Fraction:
        num: -5
        denom: 9

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 4

  Removing a Fraction node using removeFirstChanceV() -

    Calling removeFirstChanceV() ...

    Calling free() to deallocate dynamic block ...

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 5

  Displaying Fraction list -

    Node #1:
      Address: 015C5528
      Fraction:
        num: -5
        denom: 9
      next: 0

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 4

  Removing a Fraction node using removeFirstChanceV() -

    Calling removeFirstChanceV() ...

    Calling free() to deallocate dynamic block ...

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 2

  Checking for Palindrome -

  Not appropriate as there is no list (or empty list)!

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 5

  Displaying Fraction list -

  Not appropriate as there is no list (or empty list)!

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 1

  Creating Fraction List using insertFirstChanceV() -

    Creating a Fraction --
      Enter an int for num: 5
      Enter an int for denom: 0
        0 is not allowed!

      Enter an int for denom: -18

    Creating a Fraction node ...

    Inserting Fraction node to become first node ...

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 5

  Displaying Fraction list -

    Node #1:
      Address: 015C54F0
      Fraction:
        num: -5
        denom: 18
      next: 0

**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 2

  Checking for Palindrome -

     There are no Palindrome Fraction's!
     
**********************************
*           MENU - HW #4         *
* (1) Creating Fraction List     *
* (2) Checking for Palindrome    *
* (3) Inserting Fraction         *
* (4) Removing Fraction          *
* (5) Displaying Fraction List   *
* (6) Quit                       *
**********************************
Enter an integer for option + ENTER: 6

  Deallocating and Removing ALL Fraction's!

Have fun!

*/

/* LOGIC_CODE_OUTPUT_Issues:

No Comments!

*/
