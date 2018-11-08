#include <stdio.h>
int main()
{
    unsigned int date, day, month, year;
    printf("Enter the day\n");
    scanf("%d", &day);
    printf("Enter the month\n");
    scanf("%d", &month);
    printf("Enter the year\n");
    scanf("%d", &year);
    date = 512 * (year - 1980) + 32 * month + day;
    day = (date<<59)>>59;
    month = (date<<55)>>60;
    year = 1980+(date >> 9);
    printf(" date = %u   %u - %u - %u\n",date, day, month, year);
    return 0;
}