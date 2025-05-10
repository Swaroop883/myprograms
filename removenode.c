#include<stdio.h>
#include<stdlib.h>
struct node{
    int n;
    struct node *p;
};
struct node* create(int val,int i,int sz,struct node* head)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    ptr->n=val;
    if(head == NULL){
        ptr->p = head;
        return ptr;
    }
    head->p = ptr;
    if(i==sz)
    {
        ptr->p = NULL;
    }
    return ptr;
}
int main()
{
    int sz,val,rem;
    struct node *first, *head = NULL, *prev = NULL;

    scanf("%d",&sz);
    if(!(1<=sz&&sz<=30))
        return 0;

    scanf("%d",&rem);
    if(!(1<=rem&&rem<=sz))
        return 0;

    for(int i=1;i<=sz;i++)
    {
        scanf("%d",&val);
        if(!(0<=val&&val<=100)) return 0;

        head = create(val,i,sz,head);
        if(prev != NULL)
            prev->p = head;
        prev = head;

        if(i == 1)
            first = head;
    }

    if(sz==1&&rem==1)
        return 0;

    struct node *p1 = first, *p2 = first;
    int count1 = sz - rem - 1;
    while(count1--)
        p1 = p1->p;

    int count2 = sz - rem;
    while(count2--)
        p2 = p2->p;

    p1->p = p2->p;

    struct node *print = first;
    while(print != NULL)
    {
        printf("%d ", print->n);
        print = print->p;
    }
    return 0;
}
