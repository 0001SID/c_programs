#include<stdio.h>
int main()
{
    printf("Enter anything ");
    char a;
    scanf("%c",&a);
    if (a>=65 && a <=90)
    printf("This is a upper case character");
    else if (a >= 97 && a<= 122)
    printf("This is a lower case character");
    else if(a>= 48 && a<= 57)
    printf("This is a number");
    else
    printf("This is a symbol");
    return 0;
}