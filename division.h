#ifndef DIVISION_H
#define DIVISION_H
#include <stdio.h>
#include <stdlib.h>

void takeInputs(double* coefficients, int power);
int isDivisible(int numPower, int denomPower);
void divide(int numPower, double* numCoeff, int denomPower, double* denomCoeff, double* outCoeff);
void PrintPoly(int outPower, double* outCoeff);
int isRemained(int numPower, double* numCoeff);
void PrintRemainder(int numPower, double* numCoeff, int denomPower, double* denomCoeff);

#endif // DIVISION_H
