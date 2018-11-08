#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,height;
    printf("Enter the height\n");
    //height = 5;
    scanf("%d",&height);
    //height = atoi(height);
    //scanf("%d",j);
    //printf("Enter the number of last line star");
    for (i = 1;i <= height;i++)
    {
        for (j =1;j<=height-i;j++)
        {
            printf(" ");
        }
        for (j = 1; j<=(2*i)-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return(0);
}