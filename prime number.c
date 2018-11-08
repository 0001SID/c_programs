/*a program to find out the prime number in a given 
range.*/

#include<stdio.h>
int main()
{
    int a,b,c;
    printf("From where? ");
    scanf("%d",&a);
    printf("To where? ");
    scanf("%d",&b);
    printf("The prime number between %d to %d is:\n",a,b);
    for (c = a;c<=b;c++)
    {
        if (c ==1)
        {
            printf("%d  ",c);
            continue;
        }
        /*This three if statement is for 1 to 10 range*/
        else if (c == 3)
        {
            printf("%d  ",c);
            continue;
        }
        else if (c == 5)
        {
            printf("%d  ",c);
            continue;
        }
        else if (c == 7)
        {
            printf("%d  ",c);
            continue;
        }
        
        
            /*In this loop the problem is that in this loop
            the d is not taking 3,5 and 7. but don't know
            why its not taking them*/
        else if (c%2== 0)
        {
            continue;
        }
        /*As the loop not giving 3,5 and 7 as the value 
        d for this I have to check them in different if 
        statement.*/
        else if (c%3==0)
        {
            
            continue;
        }
        else if (c%5==0)
        {
            
            continue;
        }
        else if (c%7==0)
        {
            
            continue;
        }
        else
        {
            printf("%d  ",c);
            continue;
        }
        
    
    }
    return 0;
}
/*Now the question is why the second for loop not taking 
the 3 value(3,5,7) of d?*/