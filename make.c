#include<stdio.h>
#include<string.h>
int main()
{
    int name;
    printf("What your name\n");
    gets(name);
    switch(name)
    {
        case 'suman':
        printf("your name is suman");
        break;
        case 'suman das':
        printf("Your name is suman das");
        break;
        default:
        printf("You are not suman");
    }
}