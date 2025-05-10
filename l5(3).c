#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char ch[100],ch1[100],ch2[100];
    gets(ch);
    gets(ch1);
    int k=0;
    int a= strlen(ch);
    int b=strlen(ch1);
    if(a<1||b>1000)
    {
        return 0;
    }
    for(int i=0;i<a;i++)
    {
        if(islower(ch[i]))
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    for(int i=0;i<b;i++)
    {
        if(islower(ch1[i]) )
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    strcat(ch,ch1);
    for(char i='a';  i <='z'; i++)
    {
        for(int j=0;j<a+b;j++)
        {
            if(i == ch[j])
            {
                ch2[k] = i;
                k++;
            }
        }
    }
    ch2[a+b] = '\0';
    printf("%s",ch2);
    return 0;


}