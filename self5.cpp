#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<int>st;int sum=0;int r;vector<string>t={"4","13","5","/","+"};
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=="+"||t[i]=="-"||t[i]=="*"||t[i]=="/")
            {
               if(t[i]=="+")
               {
                    r=0;
                    while(!st.empty())
                    {
                        r+=st.top();
                        st.pop();
                    }
                    sum+=r;
               }
                if(t[i]=="-")
               {
                    r=0;
                    while(!st.empty())
                    {
                        r-=st.top();
                        st.pop();
                    }
                    sum+=r;
               }
                if(t[i]=="*")
               {
                    r=1;
                    while(!st.empty())
                    {
                        r*=st.top();
                        st.pop();
                    }
                    sum*=r;
               }
                if(t[i]=="/")
               {
                    r=1;
                    while(!st.empty())
                    {
                        r/=st.top();
                        st.pop();
                    }
                    sum/=r;
               }
               
            }
            else
            {
                st.push(stoi(t[i]));
            }
            
        }
        cout<<sum<<endl;
        return 0;
}