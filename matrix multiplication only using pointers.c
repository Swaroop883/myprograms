#include<stdio.h>
int main()
{
    int r1,c1,r2,c2;
    scanf("%d%d",&r1,&c1);
    if(!(1<=r1&&r1<=10)||!(1<=c1&&c1<=10))
    {
        return 0;
    }
    int a[r1][c1];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
            if(!(-100<a[i][j]&&a[i][j]<100))
            {
                return 0;
            }
        }
    }
    scanf("%d%d",&r2,&c2);
    if(!(1<=r2&&r2<=10)||!(1<=c2&&c2<=10))
    {
        return 0;
    }
    int b[r2][c2];
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
            if(!(-100<b[i][j]&&b[i][j]<100))
            {
                return 0;
            }
        }
    }
    if(!(c1==r2))
    {
        printf("Invalid dimensions");
        return 0;
    }
    int *ptr;int *ptr1;int n=c2,m=0,sum=0;
    for(int i=0;i<r1;i++)
    {
        while(n!=0)
        {
            ptr = &a[i][0];
            for(int j=0;j<r2;j++)
            {
                ptr1 = &b[j][m];
                sum+=(*ptr)*(*ptr1);
                ptr++;
               
            }
            printf("%d\t",sum);
            sum =0;
            n--;
            m++;
        }
        m=0;
        n=c2;
        printf("\n");
    }
    return 0;
        
}    
