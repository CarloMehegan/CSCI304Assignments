#include <stdio.h>

void inputIntegers()
{
    int num1, num2;
    printf("Give two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("You entered %d and %d, their sum is: %d\n", num1, num2, num1 + num2);
}

void inputFloats()
{
    float num1, num2;
    printf("Give two floats: ");
    scanf("%f %f", &num1, &num2);
    printf("You entered %.6f and %.6f, their product is: %.6f\n", num1, num2, num1 * num2);
}

void inputWord()
{
    char word[50];
    printf("Give a word: ");
    scanf("%s", word);
    printf("%s %s\n", word, word);
}

int main()
{
    inputIntegers();
    inputFloats();
    inputWord();

    return 0;
}
