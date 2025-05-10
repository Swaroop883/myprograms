/*this program to print a number without rounding off like
input : 4.36
output: 4.3*/
#include<stdio.h>
int main()
{
    printf("enter a number");
    float a,c ;int b;
    scanf("%f",&a);
    b = ((((int)(a*100))%100)%10);
    b = 10 -b;
    c = b* 0.01;
    a = a+ c;
    printf("%.1f",a - 0.1);
    return 0;
}
