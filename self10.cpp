#include <iostream>
#include <vector>

using namespace std;
vector<int> generator(int m)
{
    vector<int> vec;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            vec.push_back(j);
        }
    }
    return vec;
}
int checker(vector<int> &vec, vector<int> &fav, int n)
{
    int b = n - 1;
    int a = 0;
    int sz = vec.size() - 1;
    int k = 0;
    int d = 0;
    int m;
    while (b != sz)
    {
        for (int i = a; i <= b; i++)
        {
            if (vec[i] == fav[k])
            {
                d++;
            }
            k++;
        }
        a=a+1;b=b+1;
        k = 0;
        if (d == n)
        {
            m++;
        }
    }
    return m;
}
int main()
{
    int o;
    cin >> o;
    int m, n;
    int c = 0;vector<int>vec1;
    for (int i = 0; i < o; i++)
    {
        cin >> m;
        cin >> n;
        vector<int> vec(m, 0);
        vector<int> fav(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> fav[j];
        }
        vec = generator(m);
        c = checker(vec, fav, m);
        vec1.push_back(c);
        c=0;
       
    }int x;
    for(x=0;x<vec1.size();x++)
    {
        cout<<vec1[x];
        cout<<"\n";
    }
    return 0;
}