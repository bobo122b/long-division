#include "division.h"

void takeInputs(double* coefficients, int power)
{
    int i;
    if (power >= 0)
    {
        for (i = 0; i < power; i++)
        {
            if (power - i == 1)
            {
                printf("Enter the coefficient of X : ");
                scanf("%lf", (coefficients + i));
            }
            else
            {
                printf("Enter the coefficient of X^%d : ", power - i);
                scanf("%lf", (coefficients + i));
            }
        }
        printf("Enter the constant term : ");
        scanf("%lf", (coefficients + i));
    }
}
