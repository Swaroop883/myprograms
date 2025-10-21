#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;vector<int>vec1;
    while(t--)
    {
        int n,k;cin>>n;cin>>k;
        int mex=-1;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int w;
        for(int i=0;i<n-1;i++)
        {
            w=vec[i+1]-vec[i];
            if(w>1)
            {
                mex=vec[i]+1;
                break;
            }
        }
        if(mex==-1&&vec[0]==0)
        {
            mex=vec[n-1]+1;
        }
        if(mex==-1&&vec[0]>0)
        {
            mex=0;
        }
        if(mex==k)
        {
            vec1.push_back(0);
        }
        else{
            int l=0;
            for(int i=0;i<n;i++)
            {
                if(vec[i]==k)
                {
                    l++;
                }

            }
            int missing = 0;
            for (int i = 0; i < k; i++)
            {
            if (!binary_search(vec.begin(), vec.end(), i))
            missing++;
            }
            vec1.push_back(max(missing,l));
        }
    }
    for(int x:vec1)
    {
        cout<<x<<endl;
    }
    return 0;
}