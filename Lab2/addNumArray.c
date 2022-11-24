#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void initArray(int *arr, char *num, int len){
    int j, temp;
    for(j = 0; j < len; j++){
        arr[j] = num[len - j - 1] - '0';
    }
}

void addArray(int *arr1, int *arr2, int *ans, int s1, int s2){
    int i = 0, carry = 0, temp;
    while(i < s1 && i < s2)
    {
        temp = arr1[i] + arr2[i] + carry;
        ans[i] = temp %10;
        carry = temp/10;
        i++;
    }

    while(i < s1)
    {
        temp = arr1[i] + carry;
        ans[i] = temp %10;
        carry = temp/10;
        i++;
    }

    while(i < s2)
    {
        temp = arr2[i] + carry;
        ans[i] = temp %10;
        carry = temp/10;
        i++;
    }
    ans[i] = carry;
}

int main()
{
    int n1, n2, n3;
    printf("Enter the lengths of numbers: ");
    scanf("%d %d", &n1, &n2);
    char num1[n1], num2[n2];

    printf("Enter two numbers to add: \n");
    scanf("%s", num1);
    scanf("%s", num2);

    n3 = max(n1, n2) + 1;

    // printf("%d %d %d %d %d\n", num1, num2, n1, n2, n3);

    int arr1[n1], arr2[n2] , *ans;
    ans = (int*)calloc(n3, sizeof(int));

    initArray(arr1, num1, n1);
    initArray(arr2, num2, n2);

    addArray(arr1, arr2, ans, n1, n2);

    printf("Ans = ");
    for(int i = n3-1; i >= 0; i--)
    {
        printf("%d", ans[i]);
    }
    return 0;
}