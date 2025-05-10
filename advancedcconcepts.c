
#include <stdio.h>

int main(void) {
    int c;
    FILE *fp = fopen(__FILE__, "r"); // Open the current file

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c); // Print each character from the file
    }

    fclose(fp);
    return 0;
}
