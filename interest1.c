#include<stdio.h>
#include<conio.h>
#include<math.h>
#include"sidh.h"
int main()
{
    system("cls");
    int i;
    i = 1;
    while (i < 2) //To calculate repeatedly
    {
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
        }
    }
    return 0;
}