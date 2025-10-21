#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
int main()
{
    string name ="abBAcA";
    stack<char>st;
    for(char ch: name)
    {
        if(!st.empty()&&(st.top()==tolower(ch)||st.top()==toupper(ch)))
        {
            st.pop();
        }
        else{
            st.push(ch);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();    
    }
    return 0;
}
