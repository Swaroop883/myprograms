#include<stdio.h>
void mergesort(int a[], int le, int ri);
void merge(int a[], int le, int mid, int ri);

int main() {
    int arr[] = {1, 3, 4, 9, 5, 56, 7, 6, 2, 10, 90};
    mergesort(arr, 0, 10);

    printf("\nSorted array: ");
    for (int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergesort(int a[], int le, int ri) {
    int mid;
    if (le < ri) {  // Corrected the condition
        mid = (le + ri) / 2;
        mergesort(a, le, mid);
        mergesort(a, mid + 1, ri);
        merge(a, le, mid, ri);
    }
}

void merge(int a[], int le, int mid, int ri) {
    int temp[11];
    int i = 0;
    int lef = le, rig = mid + 1;

    while (lef <= mid && rig <= ri) {
        if (a[lef] <= a[rig]) {
            temp[i] = a[lef];
            lef++;
        } else {
            temp[i] = a[rig];
            rig++;
        }
        i++;
    }
    while (lef <= mid) {
        temp[i] = a[lef];
        lef++;
        i++;
    }
    while (rig <= ri) {
        temp[i] = a[rig];
        rig++;
        i++;
    }

    for (int j = 0; j < i; j++) {  // Copy temp back to a[]
        a[le + j] = temp[j];
    }
}
