#include <stdio.h>
 
int main()
{
    int a, b , res;
    printf("Enter two digits for arithematic operations: ");
    scanf("%d", "%d", &a, &b);
 
    // printing a and b
    printf("a is %d and b is %d\n", a, b);
 
    res = a + b; // addition
    printf("a + b is %d\n", res);
 
    res = a - b; // subtraction
    printf("a - b is %d\n", res);
 
    res = a * b; // multiplication
    printf("a * b is %d\n", res);
 
    res = a / b; // division
    printf("a / b is %d\n", res);
 
    res = a % b; // modulus
    printf("a %% b is %d\n", res);
 
    return 0;
}