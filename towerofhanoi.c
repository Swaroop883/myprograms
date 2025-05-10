#include <stdio.h>

// Function to move disks in Tower of Hanoi
void move(int n, char a, char b, char c) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", a, c); // Move disk 1 directly
        return;
    }
    move(n - 1, a, c, b); // Move n-1 disks from A to B using C
    printf("Move disk %d from %c to %c\n", n, a, c); // Move nth disk from A to C
    move(n - 1, b, a, c); // Move n-1 disks from B to C using A
}

int main() {
    int n;
    char a = 'A', b = 'B', c = 'C';
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move(n, a, b, c);  // The destination is C
    return 0;
}
