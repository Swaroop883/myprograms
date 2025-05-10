#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int sum = 0, sum1 = 0;
    scanf("%d", &n);
    int m = 0, d = 0;
    int *ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    int c;

    while (n != 0)
    {
        c = *ptr;
        if (c < 5000)
        {
            m++;
            sum += c;
        }
        else
        {
            d++;
            sum1 += c;
        }
        ptr++;
        n--;
    }
    printf("%d\t%d\n",m,sum);
    printf("%d\t%d",d,sum1);
    return 0;
}