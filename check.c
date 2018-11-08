//Checking the input alphabet or digit
#include <stdio.h>
#include <conio.h>
int main()
{
    char a;
    printf("Enter any number or digit");
    scanf("%c",&a);
    if (a>=48 && a<=57)
    {
        printf("This is a digit");
    }
    else if ((a>=65 && a<=90)||(a >= 97 && a<=122))
    {
        printf("This is a character and \n");
        if(a == 'a'||a == 'e'|| a == 'i'|| a == 'o' || a == 'u')
        {
            printf("This is vowel");
        }
        else
        {
            printf("This is a consonent");
        }
    }
    else
    {
        printf("this is not a digit nor a character");
    }
    getch();
    return(0);
}