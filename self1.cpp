#include <iostream>
#include <vector>
using namespace std;
void reverse1(vector<int> &abc)
{
    int i = abc.size();int m=i;
    i = i / 2;int temp,k=0;
    for (int j = 0; j < i; j++)
    {
        temp=abc[k];
        abc[k]=abc[m-1-k];
        abc[m-1-k]=temp;

    }
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int i : vec)
    {
        cout << i << endl;
    }
    reverse1(vec);
    for (int i : vec)
    {
        cout << i<< endl;
    }
    return 0;
}
