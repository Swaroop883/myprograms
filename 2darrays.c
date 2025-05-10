#include <stdio.h>

int main() {
  int i,j = 2,k,n;
  printf("how many tables do you want to print from 2");
  scanf("%d",&n);
  int a[n][10];
  for(i=0;i<n;i++)
  {
      
      
          for(k=0;k<10;k++)
          {
              a[i][k] = j * (k+1);
          }
          j++;
      
  }
  for(i=0;i<n;i++)
  {
      for(j=0;j<10;j++)
      {
          printf("%d\t",a[i][j]);
      }
      printf("\n");
         
  }
  
    return 0;
}