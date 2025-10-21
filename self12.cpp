#include<iostream>
#include<vector>
#include<climits>
#include <cmath>
using namespace std;
int swapp(int n,int m)
{
    int d=0,g=0;
    while(n!=0)
    {
        if(n%2!=0)
        {
            d++;
        }
        n=n/2;
    }
    while(m!=0)
    {
        if(m%2!=0)
        {
            g++;
        }
        m=m/2;
    }
    if(d==g)
    {
        return 1;
    }
    return 0;
}
int sort(vector<int>vec,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(vec[j]>vec[j+1])
            {
                if(swapp(vec[j],vec[j+1]))
                {
                    continue;
                }
                else{
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    int t;cin>>t;vector<int>f;
    while(t--)
    {
        int n;
        cin>>n;int m=0;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        f.push_back(sort(vec,n));
        
       

    }
    for(int x:f)
    {
        if(x)
        {
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}