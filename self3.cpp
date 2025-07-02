#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

int main() {
    vector<int> piles = {25, 10, 23, 4};
    int h = 4;
    int m = 0;
    int sz = piles.size();
    int maxPile = 0;int l;

    for (int i = 0; i < sz; i++) {
        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }

    for (int k = 1; k <= maxPile; k++) {
        for (int i = 0; i < sz; i++) {
            l=piles[i];
           while((l-k)>0)
           {
               m++;
               l=l-k;
           }
           m+=1;
        }
        if (m <= h) {  // Use <= instead of < (edge case fix)
            cout << "Minimum eating speed: " << k << endl;
            return 0;
        }
        m = 0;
    }

    return 0;
}
