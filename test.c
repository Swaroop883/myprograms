#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{

    char **ptr = malloc(sizeof(char *) * 100);
    int count = 0;

    printf("Enter strings (type 'exit' to stop):\n");

    for (int i = 0; i < 100; i++)
    {
        ptr[i] = malloc(sizeof(char) * 100);
        fgets(ptr[i], 100, stdin);

        ptr[i][strcspn(ptr[i], "\n")] = '\0';

        if (strcmp(ptr[i], "exit") == 0)
        {
            free(ptr[i]);
            break;
        }

        count++;
    }
    

    return 0;
}
