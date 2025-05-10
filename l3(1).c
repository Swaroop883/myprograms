// Online C compiler to run C program online
#include<stdio.h>
int main()
{
    int N,i=1,sum = 0,product =1;
   int ON =0;
    scanf("%d",&N);
    ON = N;
    if(N<0)
    {
        N = 0 - N;
            }
            
    while(N>=10)
    {
        if(i%2==0)
        {
            while(N!=0)
            {
            product = product * (N%10);
            N = N/10;
            }
            N = product;
            product = 1;
        }
        else
        {
            while(N!=0)
            {
                sum = sum + (N%10);
                N = N/10;
                           }
            N = sum;
            sum = 0;
        }
        i++;
    }
    printf("%d",N);
    printf("\n");
    printf("%d",i);
    if(i%2==0)
    {
    N = N + ON;
    printf("%d",N);
    }
    else
    {
    N = N - ON;
    printf("%d",N);
    }
    return 0;
}