#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int r = mat.size();
    int c = mat[0].size();
    vector<int> mn(r * c);
    int m = 0, n = 0;
    int l = 0;
    int j = c - 1;
    int k = 0;
    for (int i = 1; i <= r * c; i++)
    {

        if (n <= j && m == l)
        {
            mn[k] = mat[m][n];
            n++;
            k++;
            continue;
        }
        if (n == j + 1 && m + 1 < r - l)
        {
            mn[k] = mat[++m][n - 1];
            if (m + 1 == r - l)
            {
                n = n - 1;
            }

            k++;
            continue;
        }
        if (m == r - 1 - l && n > l)
        {

            mn[k] = mat[m][--n];
            if (n == l)
            {
                m = m - 1;
            }

            k++;
            continue;
        }
        if (n == l && m > l)
        {
            mn[k] = mat[m][n];
            m = m - 1;

            k++;
            if (m == l)
            {
                l = l + 1;
                j = j - 1;
                m = m + 1;
                n = n + 1;
            }
            continue;
        }
    }
    for (int i = 0; i < r*c; i++)
    {
       cout<<mn[i];
        cout << endl;
        
    }
    return 0;
}
