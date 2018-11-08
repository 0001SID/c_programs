#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
float average(int n[],int size)
{
    int i;
    int sum = 0;
    for (i = 1;i <= size; i++)
    {
        sum += n[i];
    }
    float ave;
    ave = sum / (float)size;
    return ave;
}
int main()
{
    system("cls");
    printf("Enter the element no. of the array ");
    int size;
    scanf("%d",&size);
    int n[size];
    int i;
    for (i = 1;i <=size;i++)
    {
        printf("Enter the value of element%d ",i);
        scanf("%d",&n[i]);
    }
    float ave;
    ave = average(n,size);
    printf("The average of the of the array is %.2f",ave);
    getch();
}
