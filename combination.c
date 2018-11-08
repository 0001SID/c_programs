#include<stdio.h>
long int factorial(long int);
int main()
{
    long int n,comb,num[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("Enter the total number in combination\n");
    scanf("%ld",&n);
    comb = factorial(n);
    for (int line = 1; line<= comb; line++)
    {
        for(int one = 0 ; one<10;one++)
        {
            for (int two = 0 ; two )
        }
    }
}
long int factorial(long int a)
{
    long int fact = 1;
    for (int i = 1; i <= a; i++)
    {
        fact *= i;
    }
    return fact;
}