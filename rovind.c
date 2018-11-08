#include<stdio.h>
int main()
{
    int ar[2][2],i,j,br[2][1];
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("Enter element A%d%d  : ",i+1,j+1);
            scanf("%d",&ar[i][j]);
            br[i][0] += ar[i][j];
        }
    }
    printf("The resultant matrix is \n");
    for(int i = 0 ; i< 2;i++)
    {
        printf("%d\n",br[i][0]);
    }
    return 0;
}