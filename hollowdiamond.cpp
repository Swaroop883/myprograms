//hollow diamond pattern
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main()
{
    int i,j,k;
    for(i=1;i<=4;i++)
    {
        for(j=4;j>=1;j--)
        {
            if(j==i)
            cout<<"*";
            else
            cout<<" ";
        }
        for(k = 1;k<i;k++)
        {
            if(k+1 == i)
            
                cout<<"*";
                else
                cout<<" ";
        }
        cout<<"\n";
    }
    for(i=1;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
                if(j == i)
                cout<<"*";
                else
                cout<<" ";
                
            }
           for(k=2;k>=i;k--)
           {
                if(k==i)
                cout<<"*";
                else
                cout<<" ";
           }
        cout<<"\n";

    }
    return 0;
             
       
}