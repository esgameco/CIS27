#include "cis27ChanceVHw2Utility.h"

#define BUFFER_SIZE 20
#define DIGIT_SIZE 10

void displayOddDigitForArrayChanceV(int* intArrCV, int arrSize)
{
    int* oddDigitsCV = malloc(sizeof(int) * BUFFER_SIZE);
    int* occurencesCV = malloc(sizeof(int) * DIGIT_SIZE);
    int numDigitsCV = 0;
    int currentIndexCV = 0;
    int largestOddDigitCV = 0;
    int numUniqueCV;

    printf("  While displayOddDigitForArrayChanceV() is running -\n\n");

    clearArray(occurencesCV, DIGIT_SIZE, 0);
    for (int i = 0; i < arrSize; i++)
        getDigitsChanceV(
            intArrCV[i], oddDigitsCV, &numDigitsCV, &currentIndexCV, 0);
    getOccurrencesChanceV(oddDigitsCV, currentIndexCV, occurencesCV);

    if (currentIndexCV <= 0)
    {
        printf("    There are no odd digits!\n\n");
        return;
    }

    printf("    There is/are %d odd digits of\n", currentIndexCV);
    for (int i = 0; i < currentIndexCV; i++)
        printf("      %d\n", oddDigitsCV[i]);

    for (int i = 9; i > 0; i -= 2)
        if (occurencesCV[i] > 0)
        {
            largestOddDigitCV = i;
            printf("    The largest odd digit is %d, which is seen %d time(s).\n\n",
                largestOddDigitCV, occurencesCV[largestOddDigitCV]);
            break;
        }

    numUniqueCV = getNumDigitsCV(occurencesCV);
    printf("    There is/are %d other unique odd digit(s)%s\n",
        numUniqueCV - 1,
        (numUniqueCV > 1) ? " as follows," : "!");
    for (int i = 1; i < largestOddDigitCV; i += 2)
        if (occurencesCV[i] > 0)
            printf("      Digit %d seen %d time(s)\n",
                i, occurencesCV[i]);
    printf("\n");

    free(oddDigitsCV);
    free(occurencesCV);
}

void getDigitsChanceV(int valueCV, int* arrBufferCV, int* numDigitsCV, int* currentIndexCV, int useEvenCV)
{
    int digitsCV = 0;
    valueCV = (valueCV < 0) ? -valueCV : valueCV;

    while (valueCV)
    {
        if (valueCV % 2 != useEvenCV)
        {
            arrBufferCV[*currentIndexCV + digitsCV] = valueCV % 10;
            digitsCV++;
        }
        valueCV /= 10;
    }

    *numDigitsCV = digitsCV;
    *currentIndexCV += digitsCV;
}

void getOccurrencesChanceV(int* digitsCV, int digitSizeCV, int* occurrencesBufferCV)
{
    for (int i = 0; i < digitSizeCV; i++)
        occurrencesBufferCV[digitsCV[i]]++;
}

void clearArray(int* bufferCV, int sizeCV, int valueCV)
{
    for (int i = 0; i < sizeCV; i++)
        bufferCV[i] = valueCV;
}

int getNumDigitsCV(int* digitsCV)
{
    int numDigitsCV = 0;

    for (int i = 0; i < DIGIT_SIZE; i++)
        if (digitsCV[i] > 0)
            numDigitsCV++;

    return numDigitsCV;
}
