#include<stdio.h>
int armo(long int);

int main()
{
    long int a,count = 0,b;
    printf("Enter the first number of the range\n");
    scanf("%lu",&a);
    printf("Enter the last number of the range\n");
    scanf("%lu",&b);
    printf("\nThe armostrong numbers in this range is --\n\n");
    for(long int i = a; i<= b; i++)
    {
        count += armo(i);
        
    }
    if(count == 0)
    {
        printf("Sorry I can't find any armostrong number in this range\n");
    }
    

}
int armo(long int a)
{
    long int b,num = a,sum = 0;
    while(1)
    {
        b = num%10;
        sum += (b*b*b);
        num = num/10;
        if(num == 0)
        {
            break;
        }
    }
    if(sum == a)
    {
        printf("%lu  ",a);
        return 1;
    } 
    else 
    return 0;       
}