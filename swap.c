#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b,c;
    printf("Enter value of a and b");
    scanf("%d%d",&a,&b);
    c =a;
    a =b;
    b =c;
    printf("a = %d and b = %d",a,b);
    getch();
}