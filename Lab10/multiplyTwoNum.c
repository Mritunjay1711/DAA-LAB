#include<stdio.h>
#include<stdlib.h>

int multiply(int a, int b)
{
    if(b == 0)
        return 0;
    return a + multiply(a, b-1);
}
int main()
{
    int num1, num2;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);
    printf("Ans = %d\n", multiply(num1, num2));
    return 0;
}