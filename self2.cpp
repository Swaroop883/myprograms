#include <iostream>
#include <vector>
using namespace std;

void reverse1(vector<int> *abc)
{
    int n = abc->size();  // access vector's size through pointer

    for (int i = 0; i < n / 2; i++)
    {
        // access elements using pointer with -> and []
        int temp = (*abc)[i];
        (*abc)[i] = (*abc)[n - 1 - i];
        (*abc)[n - 1 - i] = temp;
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "Original vector:\n";
    for (int i : vec)
    {
        cout << i << endl;
    }

    reverse1(&vec); // pass address of vector

    cout << "Reversed vector:\n";
    for (int i : vec)
    {
        cout << i << endl;
    }

    return 0;
}
