#include<stdio.h>
#include<math.h>
int main()
{
    int a,on,d=0,x,y,rev2 =0;
    
    scanf("%d",&a);
    on =a;
    while(a!=0)
    {
        a  = a/10;
        d++;
    }
  a= on;
  a = a/pow(10,(d-1)/2);
  x=a;
  a = a/10;
  x = x * pow(10,(d-1)/2);
  y =a;
  while(y!=0)
  {
      rev2 = rev2*10 + (y%10);
      y= y/10;
  }
  
  x =x + rev2;
  printf("%d",x);
   return 0;
}