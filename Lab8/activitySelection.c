#include<stdio.h>
#include<stdlib.h>

typedef struct activity{
    int start;
    int finish;
}activity;

void sort(activity *act, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(act[j].finish > act[j+1].finish)
            {
                activity temp = act[j];
                act[j] = act[j+1];
                act[j+1] = temp;
            }
        }
    }
}

int maxActivity(activity *act, int n)
{
    int i = 0, j = 1, count = 0;
    sort(act, n);
    printf("Activity: ");
    while(i < n)
    {
        if(act[i].finish <= act[j].start)
        {
            count++;
            printf("%d ", i);
            i = j;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main()
{
    activity act[] = {{1, 5}, {3, 7}, {3, 6}, {6, 10}, {4, 9}, {8, 12}, {11, 15}, {16, 20}, {14, 21}, {21, 25}};
    int n = sizeof(act)/sizeof(activity);
    printf("Max activity: %d\n", maxActivity(act, n));
    return 0;
}