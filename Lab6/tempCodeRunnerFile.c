nt i = 1, count = 0, n;
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