#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int count_digit(int num)
{
    int count = 0;
    while(num)
    {
        num /= 10;
        count++;
    }
    return count;
}
int isArmstrong(int num)
{
    double sum = 0;
    int n = num;
    if(num < 10)
        return 0;
    int power = count_digit(num);
    while(num)
    {
        int temp = num % 10;
        num /= 10;
        sum += pow(temp, power);
        // printf("%lf ", sum);
    }
    if(sum == n)
        return 1;
    return 0;
}

int main()
{
    int i = 1, count = 0, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    while(count != n)
    {
        if(isArmstrong(i))
        {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    return 0;
}