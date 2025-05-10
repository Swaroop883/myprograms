#include<stdio.h>
int leftmax(int arr[],int i)
{
    int max=0;
    for(int j=0;j<=i;j++)
    {
        if(max<=arr[j])
        {
            max=arr[j];
        }
    }
    return max;

}
int rightmax(int arr[],int i,int sz)
{
    int max=-0;
    for(int j=i;j<sz;j++)
    {
        if(max<=arr[j])
        {
            max=arr[j];
        }
    }
    return max;

}
int main()
{
    int sz;
    scanf("%d",&sz);
    int arr[sz];
    for(int i=0;i<sz;i++)
    {
        scanf("%d",&arr[i]);
    }
    int leftmax1,rightmax1;int w=0;
    for(int i=0;i<sz;i++)
    {
        leftmax1 = leftmax(arr,i);
        rightmax1 = rightmax(arr,i,sz);
        if(leftmax1<rightmax1)
        {
            if((leftmax1-arr[i])>=0)
            {
                w+=leftmax1-arr[i];
            };

        }
        else{
            if((rightmax1-arr[i])>=0){
            w+=rightmax1-arr[i];}
        }


    }
    printf("%d",w);
    return 0;
}