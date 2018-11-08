#include<stdio.h>
int main()
{
    char input[1000];
    gets(input);
    char s[] = "...";
    char o[] = "---";
    for(int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 's')
        {
            printf("%s ",s);
        }
        else
        {
            printf("%s ",o);
        }
    }
    
}
