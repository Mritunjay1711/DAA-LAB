#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPerfect(int num)
{
    int n = sqrt(num);
    int sum = 1, quot;
    for(int i = 2; i <= n; i++)
    {
        if(num % i == 0)
        {
            quot = num / i;
            sum += i;
            sum += quot;
        }
    }
    // printf("%d %d\n", sum, num);
    if(sum == num)  
        return 1;
    return 0;
}

int main()
{
    int n, count = 0, i = 5;
    printf("How many perfect numbers you want to print?\n");
    scanf("%d", &n);
    while(count != n)
    {
        // printf("Running\n");
        if(isPerfect(i))
        {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    return 0;
}