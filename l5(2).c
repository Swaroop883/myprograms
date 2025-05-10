#include <stdio.h>
#include <string.h>

int main() {
    char ch[100], ch1[100], ch2[100], rev[200],rev1[100], chp[200];
    int e = 0, m=0;


    gets(ch);
    gets(ch1);

    int a = strlen(ch);
    int b = strlen(ch1);
    int f = a+b,n = a+b;

    strcpy(ch2, ch);  
    strcat(ch, ch1);
    
    for (int i = 0; i < (a + b); i++) {
        rev[i] = ch[(a + b) - 1 - i];
    }
    rev[a + b] = '\0';  
    
    if (strcmp(ch, rev) == 0) {
        
        for (int i = 0; i < a + b; i++) {
            if (i % 2 == 0) {
                chp[i] = ch2[i / 2];
            } else {
                chp[i] = ch1[(i - 1) / 2];
            }
        }
        
chp[a+b]='\0';
        
        for (int i = 0; i < a + b; i++) {
            for (int j = i + 1; j < a + b; j++) {
                if (chp[i] == chp[j]) {
                    e++;
                }
            }
            f = f - e;
            e = 0;
        }

        
        printf("%d%s", f, chp);
    }

    else{
        for (int i = 0; i < a ; i++) {
        rev1[i] = ch2[a  - 1 - i];
    }
    strcat(rev1,ch1);
    for (int i = 0; i < a + b; i++) {
            for (int j = i + 1; j < a + b; j++) {
                if (rev1[i] == rev1[j]) {
                    m++;
                }
            }
            n = n - m;
            m = 0;
        }
         printf("%d%s", n, rev1);


    }
    return 0;
}
