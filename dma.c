#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, d = 0, f = 0, sum = 0, sum1 = 0;
    int *ptr, *ptr1, *ptr2;
    int m, k;

    // Input total number of expenses
    scanf("%d", &n);

    // Allocate memory for the main list
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read the expenses and count the number of high-value and essential expenses
    for (int i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
        if (*(ptr + i) >= 5000) {
            d++;
        } else {
            f++;
        }
    }

    // Allocate memory for ptr1 and ptr2 after counting
    ptr1 = (int *)malloc(d * sizeof(int));
    ptr2 = (int *)malloc(f * sizeof(int));

    if (ptr1 == NULL || ptr2 == NULL) {
        printf("Memory allocation failed.\n");
        free(ptr);
        return 1;
    }

    // Partition expenses into ptr1 and ptr2
    int *e_ptr = ptr1; // Pointer to traverse high-value expenses
    int *h_ptr = ptr2; // Pointer to traverse essential expenses

    for (int i = 0; i < n; i++) {
        if (*(ptr + i) >= 5000) {
            *e_ptr = *(ptr + i);
            e_ptr++;
        } else {
            *h_ptr = *(ptr + i);
            h_ptr++;
        }
    }

    // Calculate sum of high-value and essential expenses
    e_ptr = ptr1; // Reset pointer to start
    h_ptr = ptr2;

    for (int i = 0; i < d; i++) {
        sum += *e_ptr;
        e_ptr++;
    }

    for (int i = 0; i < f; i++) {
        sum1 += *h_ptr;
        h_ptr++;
    }

    // Store count of expenses for final output
    m = d;
    k = f;

    // Print results
    printf("%d\t%d\n", k, sum1);
    printf("%d\t%d\n", m, sum);

    // Free allocated memory
    free(ptr);
    free(ptr1);
    free(ptr2);

    return 0;
}
