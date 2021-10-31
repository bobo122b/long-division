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
void PrintPoly(int outPower, double* outCoeff)
{
    //this function prints the output of the division without the remainder
    int i;
    char sign;
    printf("The output is : ");
    for (i = 0; i < outPower; i++)
    {
        if (outCoeff[i] < 0)
        {
            outCoeff[i] = -outCoeff[i];
            sign = -1;
        }
        else if (outCoeff[i] > 0)
            sign = 1;
        else
            continue;

        if (outCoeff[i] == 1)
        {
            if (outPower - i == 1)
            {
                if (i == 0)
                    printf("X ");
                else
                    printf("+ X ");
            }
            else
            {
                if (i == 0)
                    printf("X^%d ", outPower - i);
                else
                    printf("+ X^%d ", outPower - i);
            }
        }
        else if (outCoeff[i] == -1)
        {
            if (outPower - i == 1)
            {
                printf("- X ");
            }
            else
            {
                printf("- X^%d ", outPower - i);
            }
        }
        else
        {
            if (outPower - i == 1)
            {
                if (i == 0)
                    printf("%gX ", sign * outCoeff[i]);
                else if (sign == 1)
                    printf("+ %gX ", outCoeff[i]);
                else if (sign == -1)
                    printf("- %gX ", outCoeff[i]);
            }
            else
            {
                if (i == 0)
                    printf("%gX^%d ", sign * outCoeff[i], outPower);
                else if (sign == 1)
                    printf("+ %gX^%d ", outCoeff[i], outPower - i);
                else if (sign == -1)
                    printf("- %gX^%d ", outCoeff[i], outPower - i);
            }
        }

    }
    if (!outPower)
        printf("%g ", outCoeff[i]);
    else if (outCoeff[i] > 0)
        printf("+ %g ", outCoeff[i]);
    else if (outCoeff[i] < 0)
        printf("- %g ", -outCoeff[i]);
}

int isRemained(int numPower, double* numCoeff)
{ // returns 1 if there's a remainder
    int i;
    for (i = 0; i <= numPower; i++)
        if (numCoeff[i])
            return 1;
    return 0;
}

void PrintRemainder(int numPower, double* numCoeff, int denomPower, double* denomCoeff)
{ // a function to print the remainder
    //all of what is going through this function is just to print the remainder if it exists
    int i;
    char sign;
    for (i = 0; i <= numPower; i++)
    {
        if (numCoeff[i])
        {
            if (numCoeff[i] > 0)
                sign = 1;
            else
            {
                sign = -1;
                numCoeff[i] = -numCoeff[i];
            }

            if (i != 0 && !numCoeff[i - 1])
            {
                printf("+ (");
                if (numPower - i == 0)
                {
                    if (sign == 1)
                        printf(" %g ", numCoeff[i]);
                    else if (sign == -1)
                        printf("- %g ", numCoeff[i]);
                }
                else if (numPower - i == 1)
                {
                    if (numCoeff[i] == 1)
                    {
                        if (sign == 1)
                            printf(" X ");
                        else if (sign == -1)
                            printf("- X ");
                    }
                    else
                    {
                        if (sign == 1)
                            printf(" %gX ", numCoeff[i]);
                        else if (sign == -1)
                            printf("- %gX ", numCoeff[i]);
                    }
                }
                else if (numPower - i > 1)
                {
                    if (sign == 1)
                        printf(" %gX^%d ", numCoeff[i], numPower - i);
                    else if (sign == -1)
                        printf("- %gX^%d ", numCoeff[i], numPower - i);
                }
            }
            else if (i == 0)
            {
                printf("(");
                if (numPower - i == 0)
                {
                    if (sign == 1)
                        printf(" %g ", numCoeff[i]);
                    else if (sign == -1)
                        printf("- %g ", numCoeff[i]);
                }
                else if (numPower - i == 1)
                {
                    if (numCoeff[i] == 1)
                    {
                        if (sign == 1)
                            printf(" X ");
                        else if (sign == -1)
                            printf("- X ");
                    }
                    else
                    {
                        if (sign == 1)
                            printf(" %gX ", numCoeff[i]);
                        else if (sign == -1)
                            printf("- %gX ", numCoeff[i]);
                    }
                }
                else if (numPower - i > 1)
                {
                    if (sign == 1)
                        printf(" %gX^%d ", numCoeff[i], numPower - i);
                    else if (sign == -1)
                        printf("- %gX^%d ", numCoeff[i], numPower - i);
                }
            }
            else
            {
                if (numPower - i == 0)
                {
                    if (sign == 1)
                        printf("+ %g ", numCoeff[i]);
                    else if (sign == -1)
                        printf("- %g ", numCoeff[i]);
                }
                else if (numPower - i == 1)
                {
                    if (numCoeff[i] == 1)
                    {
                        if (sign == 1)
                            printf("+ X ");
                        else if (sign == -1)
                            printf("- X ");
                    }
                    else
                    {
                        if (sign == 1)
                            printf("+ %gX ", numCoeff[i]);
                        else if (sign == -1)
                            printf("- %gX ", numCoeff[i]);
                    }
                }
                else if (numPower - i > 1)
                {
                    if (sign == 1)
                        printf("+ %gX^%d ", numCoeff[i], numPower - i);
                    else if (sign == -1)
                        printf("- %gX^%d ", numCoeff[i], numPower - i);
                }
            }
        }
    }
    printf(") / (");
    for (i = 0; i < denomPower; i++)
    {
        if (denomCoeff[i] < 0)
        {
            denomCoeff[i] = -denomCoeff[i];
            sign = -1;
        }
        else if (denomCoeff[i] > 0)
            sign = 1;
        else
            continue;

        if (denomCoeff[i] == 1)
        {
            if (denomPower - i == 1)
            {
                if (i == 0)
                    printf("X ");
                else
                    printf("+ X ");
            }
            else
            {
                if (i == 0)
                    printf("X^%d ", denomPower - i);
                else
                    printf("+ X^%d ", denomPower - i);
            }
        }
        else if (denomCoeff[i] == -1)
        {
            if (denomPower - i == 1)
            {
                printf("- X ");
            }
            else
            {
                printf("- X^%d ", denomPower - i);
            }
        }
        else
        {
            if (denomPower - i == 1)
            {
                if (i == 0)
                    printf("%gX ", sign * denomCoeff[i]);
                else if (sign == 1)
                    printf("+ %gX ", denomCoeff[i]);
                else if (sign == -1)
                    printf("- %gX ", denomCoeff[i]);
            }
            else
            {
                if (i == 0)
                    printf("%gX^%d ", sign * denomCoeff[i], denomPower);
                else if (sign == 1)
                    printf("+ %gX^%d ", denomCoeff[i], denomPower - i);
                else if (sign == -1)
                    printf("- %gX^%d ", denomCoeff[i], denomPower - i);
            }
        }

    }
    if (denomCoeff[i] > 0)
        printf("+ %g ", denomCoeff[i]);
    else if (denomCoeff[i] < 0)
        printf("- %g ", -denomCoeff[i]);
    printf(")");
}
