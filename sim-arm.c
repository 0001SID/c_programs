#include <stdio.h>

int main()
{
    long int a, b;
    printf("Enter the first number of the range\n");
    scanf("%lu", &a);
    printf("Enter the last number of the range\n");
    scanf("%lu", &b);
    printf("\nThe armostrong numbers in this range is --\n\n");
    long int c, num, sum = 0;
    for (long int i = a; i <= b; i++)
    {
        num = i;
        sum = 0;

        while (1)
        {
            c = num % 10;
            sum += (c * c * c);
            num = num / 10;
            if (num == 0)
            {
                break;
            }
        }
        if (sum == i)
        {
            printf("%lu  ", i);
        }
    }
}
