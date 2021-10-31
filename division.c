#include "division.h"
#include <stdio.h>
#include <stdlib.h>

int isDivisible(int numPower, int denomPower)
{
    // a function that returns 1 if we can divide the numerator by the denominator, 0 if not divisible (numerator power is les than denominator's power)
    if (numPower >= denomPower) return 1;
    else return 0;
}

void divide(int numPower, double* numCoeff, int denomPower, double* denomCoeff, double* outCoeff)
{
    int i, j;
    double* subtractCoeff;
    subtractCoeff = (double*)malloc((denomPower+1) * sizeof(double));

    for (i = 0; i < numPower; i++)
    {
        if (isDivisible(numPower - i, denomPower))
        {
            outCoeff[i] = numCoeff[i] / denomCoeff[0];
            for (j = 0; j <= denomPower; j++)
                subtractCoeff[j] = outCoeff[i] * denomCoeff[j];

            for (j = 0; j <= denomPower; j++)
                numCoeff[j + i] = numCoeff[j + i] - subtractCoeff[j];
        }
        else
            break;
    }

    free(subtractCoeff);
}
