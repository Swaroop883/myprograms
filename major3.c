#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char ch1[30];
    struct node*p;
};
int main()
{
    int n;
    scanf("%d",&n);
    if(!(1<=n&&n<=100))
    {
        return 0;
    }
    struct node *b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=(struct node*)malloc(sizeof(struct node));
        if(b[i]==NULL)
        {
            return 0;
        }
    }
    char ch[30];int dis[n];int sum=0;float avg;
    for(int i=0;i<n;i++)
    {
        scanf("%s",ch);
        scanf("%d",&dis[i]);
        if(strlen(ch)>30)
        {
            return 0;
        }
        for(int u=0;u<strlen(ch);u++)
        {
            if(ch[u] == ' ')
            {
                return 0;
            }
        }
        if(dis[i]<0)
        {
            return 0;
        }
        if(i==n-1)
        {
            strcpy(b[i]->ch1,ch);
            b[i]->p = NULL;
        }
         strcpy(b[i]->ch1,ch);
        b[i]->p = b[i+1];
        ch[0]='\0';
    }
    if(dis[0]!=0)
    {
        return 0;
    }
    if(n==1)
    {
        printf("%s %d\n",b[0]->ch1,dis[0]);
        printf("AvgSegment 0.0");
        return 0;
    }
    for(int i=1;i<n;i++)
    {
       dis[i]=dis[i-1]+dis[i];
    }
    int x = n-1;
   
    avg = dis[x]/x;
    struct node *ptr = b[0];
    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",b[i]->ch1,dis[i]);
    }
    printf("AvgSegment %.2f",avg);
    return 0;
}