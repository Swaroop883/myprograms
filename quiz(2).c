#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char ch[100];int sum1 =0;int k=0;int max=0;int m=0;
    scanf(" %[^\n]",ch);
    
    int i;int d=0;int l = strlen(ch);
    
    for(i=0;i<l;i++)
    {
        if (!((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || ch[i] == ' '))
        {
            return 0;
        }

    }
    for(i=0;i<l;i++)
    {
        if(ch[i]==' ')
        {
            d++;
        }
    }
    int a[d+1];
    for(i=0;i<l;i++)
    {
        ch[i]=toupper(ch[i]);
    }
    for(i=0;i<=l;i++)
    {
        if(ch[i]==' '||ch[i]=='\0')
        {
            a[k] = sum1;
            sum1 =0;
            k++;
        }
        else{
            sum1 +=(int)ch[i]-64;
        }
    }
    int min=a[0];
    for(i=0;i<=d;i++)
    {
        if(a[i]>=max)
        max = a[i];
        if(a[i]<=min)
        min =a[i];
    }
    int r =0;
    r= max - min;
    for(i=1;i<=r;i++)
    {
        if(r%i==0)
        {
            m++;
        }
    }
    if(m==2)
    {
        printf("%d Treasure Found",r);
        return 0;
    }
    else{
        printf("%d No Treasure",r);
        return 0;
    }
    
}