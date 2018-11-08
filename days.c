//Finding the number of days of a given month
#include<stdio.h>
#include<conio.h>
int main()
{
    char month[100];
    printf ("Enter the name of the month");
    scanf("%c",&month);
    if (month == 'january'|| month == 'march'||month == 'may'||month =='july'||month == 'august'||month == 'octobor'||month =='december')
    {
        printf("This month have 31 days");
    }
    else if (month == 'february')
    {
        printf("This month have 28 days");
    }
    else if (month == 'april'||month=='june'||month=='september'||month=='november')
    {
        printf("This month have 30 days");
    }
    else
    {
        printf("This is not a month name please enter a month's name");
    }
    return(0);
}