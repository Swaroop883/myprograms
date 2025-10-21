#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int longest(vector<int>v)
{
    int max;
    sort(v.begin(), v.end(), greater<int>());
    max=v[0];
    for(int i=0;i<v.size();i++)
    {
        v[i]=v[i]*(i+1);
        if(v[i]>max)
        {
            max=v[i];
        }
    }
    return max;
}
int main()
{
    int t;cin>>t;vector<int>ans;int n;int arr[100];int x=0;
    while(t--)
    {
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<int>repeats;
        x=0;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]==arr[j+1])
            {
                x++;
            }
            else
            {
                x=x+1;
                repeats.push_back(x);
                x=0;
            }

        }
        x = x + 1;
        repeats.push_back(x);
        ans.push_back(longest(repeats));


    }
    for(int k:ans)
    {
        cout<<k<<endl;
    }
    return 0;
}