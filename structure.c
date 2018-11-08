#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int roll;
    char name[20];
    char father[20];
};
void display(struct student s[],int num)
{
  for(int j=0;j <= num-1;j++)
    {
        printf("%d\t\t%s\t%s\n",s[j].roll,s[j].name,s[j].father);
    }
}
int main()
{
    int num;
    printf("Enter the number of student\n");
    scanf("%d",&num);
    struct student st[num];
    char pass[22];
    struct student *ptr;
    ptr = st;
    for (int i = 0;i <= num-1;i++)
    {
        printf("Student %d\n",i+1);
        printf("Enter the roll of the student%d ",i+1);
        scanf("%d",&st[i].roll);
        printf("Enter the name of student%d ",i+1);
        gets(pass);
        gets(st[i].name);
        printf("Enter the father name of student%d ",i+1);
        gets(st[i].father);
    }
    printf("\nRoll no.\tName\t\tFather name\n");
    printf("-------\t\t-----\t\t----------\n");
    /*for(int j=0;j <= num-1;j++)
    {
        printf("%d\t%s\t%s\n",st[j].roll,st[j].name,st[j].father);
    }*/
    display(st,num);
    return 0;
}