#include <stdio.h>
#include <dirent.h>  // Needed for directory functions

void listFiles(const char *path);

int main() {
    char path[100];
    printf("Enter path to list files: ");
    scanf("%s", path);   // You enter a directory like "/home/user"

    listFiles(path);     // Call the function
    return 0;
}

void listFiles(const char *path) {
    struct dirent *dp;          // This will store each file/folder info
    DIR *dir = opendir(path);   // Open the folder

    if (!dir) return;           // If it failed to open, exit the function

    while ((dp = readdir(dir)) != NULL) {
        // Read each file or folder one by one
        printf("%s\n", dp->d_name);  // Print the name
    }

    closedir(dir);              // Close the folder after done
}
