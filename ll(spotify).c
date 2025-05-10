#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char ch[100];
    struct node *next;
    struct node *prev;
};
int main()
{
    int n;
    scanf("%d",&n);char ch1[100];
    struct node *a[n];
    for(int i=0;i<n;i++)
    {
         a[i]=(struct node*)malloc(sizeof(struct node));
    }
    for(int i=0;i<n;i++)
    {
       
        scanf("%s",ch1);
        strcpy(a[i]->ch,ch1);
        
        if(i==n-1)
        {
            a[i]->next = NULL;
        }
        else
        {
        a[i]->next = a[i+1];
        }
        if(i==0)
        {
            a[i]->prev = NULL;
        }
        else
        {
        a[i]->prev = a[i-1];
        }
    }
    struct node *ptr = a[0];
    int m;
    scanf("%d",&m);
    int b[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        if(!(b[i]==1||b[i]==0||b[i]==-1))
        {
            return 0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(n==1)
        {
            printf("%s\n",ch1);
        }
        else
        {
            
        
        if(b[i]==1)
        {
            if(ptr==a[n-1])
            {
                ptr = a[0];
                printf("%s\n",ptr->ch);
            }
            else
            {
                
            
          ptr = ptr->next;
          printf("%s\n",ptr->ch);
            }
        }
        if(b[i]==-1)
        {
            if(ptr==a[0])
            {
                ptr = a[n-1];
                printf("%s\n",ptr->ch);
            }
            else
            {
                
            
            ptr = ptr->prev;
            printf("%s\n",ptr->ch);
            }
        }
        if(b[i]==0)
        {
            printf("%s\n",ptr->ch);
        }
        }
    }
    return 0;
    
}
    
    
    
