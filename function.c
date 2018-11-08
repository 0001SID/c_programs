#include<stdio.h>
int factorial(num)
{
    if (num ==1 || num == 0)
    {
        return 1;
    }
    else 
    {
        int c;
        c = num*factorial(num-1);
        return c;
    }
}
int main()
{
    printf("Enter a number to do factorial\n");
    int n;
    scanf("%d",&n);
    int result = factorial(n);
    printf("The factorial of the number is %d\n",result);
    return 0;
}