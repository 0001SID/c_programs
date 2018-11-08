#include<stdio.h>
int main()
{
    int a,b;
    for (a = 1;a<=10;a++)
    {
        printf("This is %d \n ",a);
        if (a ==2)
        {
            printf("Looping again\n");
            continue;
        }
        else if (a ==5)
        {
            printf("Now I am breaking it\n");
            break;
        }
        printf("I am getting %d \n",a);
    }
    return 0;
}