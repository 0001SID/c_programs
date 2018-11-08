//Triangle
#include <stdio.h>
int main()
{
    int height, i, j, k;
    printf("Enter height\n");
    scanf("%d",&height);
    //Number of lines is equal to height
    for(i=1; i<=height; i++)
    {
        //Number of spaces in each line is
        //equal to height – line number
        for(j=1; j<=height-i;j++)
        {
            printf(" ");
        }
        //number of stars in each line is equal to
        //(2*line number) – 1
        for(j=1; j<=(2*i)-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}