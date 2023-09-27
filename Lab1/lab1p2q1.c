#include <stdio.h>

void outputString()
{
    printf("One half is 50%%\n");
}

void outputIntegerDifference(int num1, int num2)
{
    int difference = num1 - num2;
    printf("The difference between %d and %d is %d\n", num1, num2, difference);
}

void outputFloatDivision(float num1, float num2)
{
    float result = num1 / num2;
    printf("%.6f / %.6f is %.6f\n", num1, num2, result);
}

int main()
{
    // call the three functions
    outputString();
    outputIntegerDifference(10, 3);
    outputFloatDivision(1.0, 3.0);

    return 0;
}
