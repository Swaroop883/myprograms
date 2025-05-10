// Online C compiler to run C program online
#include <stdio.h>

int main() {
   printf("input 10 numbers");
   int n[10];
   int i,j,m = 0,a =0,b;
   for(i=0;i<10;i++)
   {
   scanf("%d",&n[i]);
   }
for(i=0;i<10;i++)
{
    for(j=0;j<10;j++)
    {
        if(n[i] == n[j])
        m++;
    }
    if(m > a)
    {
        a = m;
        b = i;
    }
    m = 0;
}
printf("the most occured number is %d \t and occured %d",n[b],a);

    return 0;
}