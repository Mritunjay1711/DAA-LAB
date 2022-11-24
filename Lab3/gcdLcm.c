#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
    if(b != 0)
        return gcd(b, a % b);
    else    
        return a;
}

int lcm(int a, int b)
{
    static int common = 1;
    if(common % a == 0 && common % b == 0)
        return common;
    common++;
    lcm(a, b);
}

int main()
{
    int gc, lc, n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the numbers: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    gc = arr[0];
    lc = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(gc > arr[i])
            gc = gcd(gc, arr[i]);
        else
            gc = gcd(arr[i], gc);

        lc = lcm(lc, arr[i]);
    }

    printf("GCD= %d\n", gc);
    printf("LCM= %d\n", lc);
    return 0;
}