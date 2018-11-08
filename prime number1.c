#include <stdio.h> 
#include<stdlib.h>
int main()
{
    int start,end,check,i,j;
    printf("From where?");
    scanf("%d",&start);
    printf("To where?");
    scanf("%d",&end);
    printf("Prime numbers between %d and %d is :\n",start,end);
    for (i = start;i <=end;i++)
    {
        check = 1;
        for (j = 2;j <= i-1;j++)
        {
            if(i%j == 0)
            {
                check =0;
                break;
            }
        }
        if(check ==1)
        {
            printf("%d,  ",i);
        }
        
    }
    system ("pause");
    return 0;
}