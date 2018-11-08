#include<stdio.h>
#include<conio.h>
int main()
{
    int l =1;
    while(l<2)
    {
        //system("cls");
        char res;
        int range,max,i,j;
        printf("How many numbers you want to compare\n");
        scanf("%d",&range);
        int num[range];
        for (i = 1;i <= range;++i)
        {
            printf("Enter num%d ",i);
            scanf("%d",&num[i]);

        }
        max = num[1];
        for (j = 1;j <=range;++j)
        {
            if (num[j]>max)
            {
                max = num[j];
            }
        }
        printf("The maximum number is %d\n",max);
        printf("Do you want to calculate again?(y/n)");
        fflush(stdin);
        res = getche();
        if(res =='y')
        {
            printf("\n");
            continue;
        }
        else
        {
            break;
        }
    }
}