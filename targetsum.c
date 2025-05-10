#include <stdio.h>

int sum(int arr[], int t, int a, int i, int n, int temp[], int tempIndex) {
    if (a == t) {
        // Print the current subsequence
        printf("{ ");
        for (int k = 0; k < tempIndex; k++) {
            printf("%d ", temp[k]);
        }
        printf("}\n");
        return 1;
    }
    if (i >= n || a > t) {
        return 0;
    }
    
    int count = 0;
    // Include current element
    temp[tempIndex] = arr[i];
    count += sum(arr, t, a + arr[i], i + 1, n, temp, tempIndex + 1);
    
    // Exclude current element
    count += sum(arr, t, a, i + 1, n, temp, tempIndex);
    
    return count;
}

int main() {
    int arr[] = {5, 8, 3, 10, 13};
    int temp[5]; // Temporary array to store current subsequence
    int r = sum(arr, 13, 0, 0, 5, temp, 0);
    printf("Total subsets: %d\n", r);
    return 0;
}
