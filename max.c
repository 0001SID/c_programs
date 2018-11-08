//Finding the maximum number of the three number
#include <stdio.h>
#include <conio.h>
int main()
{
    int a,b,c;
    printf("Enter three numbers to find out the maximum one \n");
    printf("Enter the first number ");
    scanf("%d",&a);
    printf("Enter the second number ");
    scanf("%d",&b);
    printf("Enter the second number ");
    scanf("%d",&c);
    if (a>b && a>c)
    {
        printf("The maximum number is %d\n",a);
    }
    
    else if (b > a && b>c)
    {
        printf("The maximum numbr is %d\n",b);
    }
    
    else if (c > a && c >a)
    {
        printf("Them maximum number is %d\n",c);
    }
    else if (a == b && b==c)
    {
        printf("they are equal");
    }
    else
    {
        printf("There is no any one maximum number");
    }
    getch();
    return(0);
    
}