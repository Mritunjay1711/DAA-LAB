#include<stdio.h>
#include<stdlib.h>

void table(int a, int b)
{
    if(b == 11)
        return;
    printf("%2d * %2d = %3d\n", a, b, a*b);
    table(a, b+1);
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    table(num, 1);
    return 0;
}