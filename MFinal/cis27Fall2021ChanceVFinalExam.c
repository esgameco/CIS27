/**
  * Program Name: cis27Fall2021ChanceVFinal.c
  * Discussion: - Final Menu with combination of
  *               do-while and switch structures
  *             - Implement and test Polynomials with terms of
  *               non-negative exponent and Fraction as coefficient
  * Written By: Chance Vodnoy
  * Date: 2021/12/16
*/

#include <stdio.h>
#include "cis27ChanceVFinalUtility.h"

int main()
{
    displayClassInfoChanceV();
    runMenuChanceV();

    return 0;
}

/* PROGRAM_OUTPUT:

// OUTPUT - Sample Run

CIS 27 - Data Structures
Laney College
Chance Vodnoy

Information --
  Assignment:     Final Exam
  Implemented by: Chance Vodnoy
  Submitted Date: 2021/12/16

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 9

Wrong option!

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 2

  Not appropriate as there are no Polynomials!

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 3

  Not appropriate as there are no Polynomials!

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 4

  Not appropriate as there are no Polynomials!

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 5

  There is no Palindrome Polynomial available!

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 1

  Initializing 2 Polynomials -

    Calling initChanceV() -

    *********************************
    *         init() Submenu        *
    * (1) Creating 2 Polynomials    *
    * (2) Updating Polynomial 1     *
    * (3) Updating Polynomial 2     *
    * (4) Displaying 2 Polynomials  *
    * (5) Return                    *
    *********************************
    Enter an integer for option + ENTER: 4

    There are no polynomials available!

    *********************************
    *         init() Submenu        *
    * (1) Creating 2 Polynomials    *
    * (2) Updating Polynomial 1     *
    * (3) Updating Polynomial 2     *
    * (4) Displaying 2 Polynomials  *
    * (5) Return                    *
    *********************************
    Enter an integer for option + ENTER: 2

    There are no polynomials available!

    *********************************
    *         init() Submenu        *
    * (1) Creating 2 Polynomials    *
    * (2) Updating Polynomial 1     *
    * (3) Updating Polynomial 2     *
    * (4) Displaying 2 Polynomials  *
    * (5) Return                    *
    *********************************
    Enter an integer for option + ENTER: 1

    Creating 2 Polynonials -

      Calling create() -

          Creating Poly #1 -

            Is there a term (1 : yes, 0 : no)? 1
              Enter expo: 3
              Creating coeff Fraction:
                Enter num: 1
                Enter denom: 4

            Is there a term (1 : yes, 0 : no)? 1
              Enter expo: 0
              Creating coeff Fraction:
                Enter num: 1
                Enter denom: -2

            Is there a term (1 : yes, 0 : no)? 0

          Creating Poly #2 -

            Is there a term (1 : yes, 0 : no)? 1
              Enter expo: 4
              Creating coeff Fraction:
                Enter num: 1
                Enter denom: 2

            Is there a term (1 : yes, 0 : no)? 1
              Enter expo: 3
              Creating coeff Fraction:
                Enter num: 1
                Enter denom: -3

            Is there a term (1 : yes, 0 : no)? 1
              Enter expo: 0
              Creating coeff Fraction:
                Enter num: 1
                Enter denom: 21

            Is there a term (1 : yes, 0 : no)? 0

    *********************************
    *         init() Submenu        *
    * (1) Creating 2 Polynomials    *
    * (2) Updating Polynomial 1     *
    * (3) Updating Polynomial 2     *
    * (4) Displaying 2 Polynomials  *
    * (5) Return                    *
    *********************************
    Enter an integer for option + ENTER: 4

    Displaying 2 Polynomials -

      Poly #1 -
        Address: 00C055F8
        Degree: 3
        Number of Terms: 2
        Address of first node: 00C055C0

        Node #1 -
          Address of Node 1: 00C055C0
          Address of term: 00C05FB0
          Address of next node: 00C06A70

            Term #1 -
              Address: 00C05FB0
              Expo: 3
              Coefficient -
                Address: 00C05F78
                num: 1
                denom: 4

        Node #2 -
          Address of Node 2: 00C06A70
          Address of term: 00C06A38
          Address of next node: 00000000

            Term #2 -
              Address: 00C06A38
              Expo: 0
              Coefficient -
                Address: 00C06A00
                num: -1
                denom: 2

      Poly #2 -
        Address: 00C004D0
        Degree: 4
        Number of Terms: 3
        Address of first node: 00C08290

        Node #1 -
          Address of Node 1: 00C08290
          Address of term: 00C08258
          Address of next node: 00C0A510

            Term #1 -
              Address: 00C08258
              Expo: 4
              Coefficient -
                Address: 00C06AA8
                num: 1
                denom: 2

        Node #2 -
          Address of Node 2: 00C0A510
          Address of term: 00C0A4D8
          Address of next node: 00C0A548

            Term #2 -
              Address: 00C0A4D8
              Expo: 3
              Coefficient -
                Address: 00C00510
                num: -1
                denom: 3

        Node #3 -
          Address of Node 3: 00C0A548
          Address of term: 00C0A5B8
          Address of next node: 00000000

            Term #3 -
              Address: 00C0A5B8
              Expo: 0
              Coefficient -
                Address: 00C0A3C0
                num: 1
                denom: 21

    *********************************
    *         init() Submenu        *
    * (1) Creating 2 Polynomials    *
    * (2) Updating Polynomial 1     *
    * (3) Updating Polynomial 2     *
    * (4) Displaying 2 Polynomials  *
    * (5) Return                    *
    *********************************
    Enter an integer for option + ENTER: 5

    Return to previous menu!

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 2

  Checking Palindrome -

    Poly #1 is a Palindrome
    Poly #2 is NOT a Palindrome

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 3

  There is/are some Palindrome term(s) int the 2 polynomials.

  Calling formPalindromePolynomial()!

    Creating a new Palindrome polynomial -
      Degree: 4
      Number of Term(s): 3

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 5

  Displaying the resulting Polynomial -

      Address: 00C00548
      Degree: 4
      Number of Terms: 3
      Address of first node: 00C08290

      Node #1 -
        Address of Node 1: 00C08290
        Address of term: 00C08258
        Address of next node: 00C0A5F0

          Term #1 -
            Address: 00C08258
            Expo: 4
            Coefficient -
              Address: 00C06AA8
              num: 1
              denom: 2

      Node #2 -
        Address of Node 2: 00C0A5F0
        Address of term: 00C0A580
        Address of next node: 00C06A70

          Term #2 -
            Address: 00C0A580
            Expo: 3
            Coefficient -
              Address: 00C0A318
              num: -1
              denom: 12

      Node #3 -
        Address of Node 3: 00C06A70
        Address of term: 00C06A38
        Address of next node: 00000000

          Term #3 -
            Address: 00C06A38
            Expo: 0
            Coefficient -
              Address: 00C06A00
              num: -1
              denom: 2

***********************************************
*                MENU - Final                 *
* (1) Creating/Updating 2 Polynomials         *
* (2) Checking for Palindrome Polynomial      *
* (3) Calling formPalindromePolynomial()      *
* (4) Displaying 2 Polynomials                *
* (5) Display resulting Palindrome Polynomial *
* (6) Quit                                    *
***********************************************
Enter an integer for option + ENTER: 6

  Singing the song of whatever!

*/

/* LOGIC_CODE_OUTPUT_Issues:

No Comments!

*/
