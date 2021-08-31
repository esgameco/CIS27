/**
 * Program Name: cis27Fall2021ChanceVHw1.c
 * Discussion:   Final
 * Written By:   Chance Vodnoy
 * Date:         2021/8/26
 

#define HW_NUM 1
#define DATE "2021/09/09"

#define BUFFER_SIZE 20
#define DIGIT_SIZE 10

#include <stdio.h>

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
    printf("********************************************\n"
           "*             MENU - [Assignment]            *\n"
           "* (1) Calling [func]() *\n"
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
            printf("Enter an [var_type]: ");
            scanf_s("%[var_type_]", &inputCV);

            printf("\nCalling [func]() with argument of %[var_type_] --\n\n", inputCV);
            [func](inputCV);
            break;
        case 2:
            printf("Have fun!\n\n");
            break;
        default:
            printf("Wrong option!\n\n");
        }
    }

}

void [func]([var_type] inputCV)
{

}

/* PROGRAM_OUTPUT:

// OUTPUT – Sample Run



*/

/* Logic_Code_Output_Issues:

No Comments!

*/