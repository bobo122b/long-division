#include "division.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double* numCoeff;
    double* denomCoeff;
    double* outCoeff;
    int numPower, denomPower, outPower;
    do
    {
        printf("Enter the degree of the numerator (has to be an integer): ");
        scanf("%d", &numPower);
        if (numPower < 0)
            printf("The degree of numerator can't be less than zero !\n");
    } while (numPower < 0);
    numCoeff = (double*)malloc((numPower + 1) * sizeof(double));
    takeInputs(numCoeff, numPower);
    do
    {
        printf("Enter the degree of the denominator (has to be an integer): ");
        scanf("%d", &denomPower);
        if (denomPower < 0)
            printf("The degree of numerator can't be less than zero !\n");
    } while (denomPower < 0);
    denomCoeff = (double*)malloc((denomPower + 1) * sizeof(double));
    takeInputs(denomCoeff, denomPower);

    if (isDivisible(numPower, denomPower))
    {
        outPower = numPower - denomPower;
        outCoeff = (double*)malloc((outPower + 1) * sizeof(double));
        divide(numPower, numCoeff, denomPower, denomCoeff, outCoeff);
        PrintPoly(outPower, outCoeff);
        if (isRemained(numPower, numCoeff))
            PrintRemainder(numPower, numCoeff, denomPower, denomCoeff);
    }
    else
        PrintRemainder(numPower, numCoeff, denomPower, denomCoeff);

    free(numCoeff);
    free(denomCoeff);
}
