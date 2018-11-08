#include<stdio.h>
int main()
{
    int sub,i;
    printf("How many subject you have? ");
    scanf("%d",&sub);
    int n[sub];
    int sum;
    sum = 0;
    for (i = 1;i <=sub;i++)
    {

        printf("Enter the number of sub%d ",i);
        scanf("%d",&n[i]);
        sum += n[i];

    }
    int average;
    average = sum / sub;
    printf("The average of the subject is %d \n",average);

}