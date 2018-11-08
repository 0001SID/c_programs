#include<stdio.h>
int main()
{
    int std,sub;
    printf("Enter the number of student ");
    scanf("%d",&std);
    printf("Enter the number of subject ");
    scanf("%d",&sub);
    int n[std][sub];
    int i,j;
    j =0;
    for (i = 1;i <= std;i++)
    {
        int sum = 0;
        printf("Enter the Roll no. of student\n");
        scanf("%d",&n[i][j]);
        for (j = 1;j<=sub;j++)
        {
            printf("Enter the number in sub%d ",j);
            scanf("%d",&n[i][j]);
            sum += n[i][j];

        }
        int average;
        average = sum /sub;
        printf("The average of Roll no. %d is %d\n",std,average);
    }
}