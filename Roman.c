#include<stdio.h>
#include<conio.h>
int main()
{
    printf("Enter any integer value ");
    int a;
    scanf("%d",&a);
    printf("The equivalent roaman number is ");
    int i;
    for (i = 1; i <= a/1000;i++)
    {
        printf("m");
    }
    int b = a%1000;
    for (i = 1; i <= b/500;i++)
    {
        printf("d");
    }
    int c = b%500;
    for (i = 1; i <= c/100;i++)
    {
        printf("c");
    }
    int d = c%100;
    for (i = 1; i <= d/50; i ++)
    {
        printf("l");
    }
    int e = d%50;
    for (i = 1;i <= e/10;i++)
    {
        printf("x");
    }
    int f = e%10;
    for (i = 1; i <= f/5; i++)
    {
        printf("v");
    }
    int g = f %5;
    for (i = 1; i <= g/1;i++)
    {
        printf("i");
    }
    return 0;
}