#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

void clear()
{
    fflush(stdin);
}
int grange(char a[20],int range)
{
    int b;
    b = strlen(a);
    if(b<=range)
    {
        return atof(a);
    }
    else
    {
        printf("Sorry Out of range...\a\nPlease enter in range\n");
        gets(a);
        grange(a,range);
    }
}
int gfloat(int range)
{
    float p;
    char b[20];
    int value = 1;
    while (value == 1) //Loop for checking numeric or alphabetic input
    {
        clear();
        gets(b);
        p = grange(b,range);
        sprintf(b,"%f",p);
        int len = strlen(b);
        int i,j = 0;
        for (i = 0;i<len;i++)
        {
            printf("%c",b[i]);
            if (b[i] == '.')
            {
                j = 0;
            }
            else if(isdigit(b[i])>0)
            {
                j = 0;
            }
            else
            {
                j = 1;
                break;
            }
        }
        if (j == 0)
        {
            return atof(b);
            break;
        }
        else
        {
            printf("Please enter an appropiate value\n");
        }

    }
}
int si()
{
    float p, r, t;
    long double smi;
    printf("\nEnter the total amount\n");
    p = gfloat(9);
    printf("Enter the rate of interest\n");
    r = gfloat(6);
    printf("Enter the total time in year\n");
    t = gfloat(5);
    smi = (p * r * t) / 100;
    printf("simple interest: %.2Lf\n", smi,p);
    printf("Amount with interest: %.2Lf\n\n", smi + p);
    
}
void ci()
{
    float p, r, t, n;
    long double cmi;
    printf("\nEnter the total amount\n");
    p = gfloat(9);
    printf("Enter the rate of interest\n");
    r = gfloat(2);
    printf("Enter the total time in year\n");
    t = gfloat(2);
    printf("How many times interest compounded per year\n");
    n = gfloat(1);
    cmi = p * pow((1 + r / (100 * n)), n * t);
    printf("Compounded interest: %.2Lf\n", cmi - p);
    printf("Amount with interest: %.2Lf\n\n", cmi);
    
}
int main()
{
    //system("cls");
    int i, j;
    i = 1;
    j = 1;
    while (i < 2) //To calculate repeatedly
    {
        clear();
        printf("Which type of interest you want to calculate?\n");
        printf("Compound(c) / Simple(s) / Exit(e)\n");
        char type;
        clear();
        type = getche();
        if (type == 'c')
        {
            ci();
        }
        else if (type == 's')
        {
            si();
        }
        else if (type == 'e')
        {
            printf("\nGood bye");
            break;
        }
        else
        {
            printf("\nYou have entered a wrong keyword\nPlease type again\n");
            continue;
        }
        printf("Do you want to calcualte again?(y/n) ");
        char l;
        rep:
        clear();
        l = getche();
        if( l == 'y')
        {
            printf("\n");
        }
        else if (l == 'n')
        {
            printf("\nGood bye\n");
            break;
        }
        else
        {
            printf("\nPlease enter appropiate keyword\a\n");
            goto rep;
        }

    }
    return 0;
}