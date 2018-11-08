#include<stdio.h>
int main()
{
    int a;
    printf("type any number");
    scanf("%c",&a);
    switch(a)
    {
        case 'go':
        printf("you typed go");
        break;
        case 'come':
        printf("you typed come");
        break;
        case '786':
        printf("you typed 785");
        break;
        default:
        printf("You neither type go or come it's default value");
    }
    return(0);
}