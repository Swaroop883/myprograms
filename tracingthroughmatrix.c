#include<stdio.h>

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    if((1>m)||(n>100))
    {
        return 0;
    }
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(!(-100<=a[i][j]&&a[i][j]<=100))
            {
                return 0;
            }
        }
    }
    int sum =0;int c[m*n];int k=0,l=0;int d=1;c[0]=a[0][0];
    for(int i=0;i<m*n;i++)
    {
        if(k==m-1&&l==n-1)
        {
            break;
        }
        if(k==m-1)
        {
           
            sum+=a[k][l];
            l=l+1;
            c[d]=a[k][l];
            d++;
            continue;
        }
        if(l==n-1)
        {
           
            sum+=a[k][l];
            k=k+1;
            c[d]=a[k][l];
            d++;
            continue;
        }
        if(a[k][l+1]>=a[k+1][l])
        {
            sum+=a[k][l+1];
            c[d]=a[k][l+1];
            d++;
            l=l+1;
            continue;
        }
        else
        {
            sum+=a[k+1][l];
            c[d]=a[k+1][l];
            d++;
            k=k+1;
            continue;
        }
    }
    sum=0;
   
    
    for(int y=0;y<d;y++)
    {
        sum+=c[y];
    }
    printf("%d\n",sum);
    for(int y=0;y<d;y++)
    {
        printf("%d\t",c[y]);
    }
    return 0;
}