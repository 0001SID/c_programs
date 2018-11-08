#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char *one [] = {
        " *  ",
        "**  ",
        " *  ",
        " *  ",
        " *  ",
        " *  ",
        " *  ",
        "*** "
    };
        
    char *two []={
        "*****  ",
        "    *  ",
        "    *  ",
        "*****  ",
        "*      ",
        "*      ",
        "*      ",
        "*****  "
    };
    char *three[]= {
        "*****  ",
        "    *  ",
        "    *  ",
        "*****  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "*****  "
    };
    char *four[] = {
        "*      ",
        "*      ",
        "*      ",
        "*  *   ",
        "*****  ",
        "   *   ",
        "   *   ",
        "   *   "
    };
    char *five[] = {
        "*****  ",
        "*      ",
        "*      ",
        "*****  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "*****  "
    };
    char *six[] = {
        "*****  ",
        "*      ",
        "*      ",
        "*      ",
        "*****  ",
        "*   *  ",
        "*   *  ",
        "*****  "
    };
    char *seven[] = {
        "*****  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "    *  "
    };
    char *eight[] = {
        "******  ",
        "*    *  ",
        "*    *  ",
        "******  ",
        "*    *  ",
        "*    *  ",
        "*    *  ",
        "******  "

    };
    char *nine[] = {
        "*****  ",
        "*   *  ",
        "*   *  ",
        "*****  ",
        "    *  ",
        "    *  ",
        "    *  ",
        "*****  "
    };
    char *zero[] = {
        "*****  ",
        "*   *  ",
        "*   *  ",
        "*   *  ",
        "*   *  ",
        "*   *  ",
        "*   *  ",
        "*****  "
    };
    printf("Enter any number: ");
    char num[20];
    gets(num);
    int len;
    len = strlen(num);
    for (int i = 0; i <8;i++)
    {
         int number = atoi(num);

        for(int j = 0; j < len; j++)
        {
            int l,font;
            l = j+1;
            if( len != l)
            {
                font = number/(pow(10,(len-l)));
            }
            else
            {
                font = number;
            }
            if (font == 0)
            {
                printf("%s",zero[i]);
            }
            else if (font ==1)
            {
                printf("%s",one[i]);
            }
            else if ( font == 2)
            {
                printf("%s",two[i]);
            }
            else if (font == 3)
            {
                printf("%s",three[i]);
            }
            else if (font == 4)
            {
                printf("%s",four[i]);
            }
            else if (font == 5)
            {
                printf("%s",five[i]);
            }
            else if (font == 6)
            {
                printf("%s",six[i]);
            }
            else if (font == 7)
            {
                printf("%s",seven[i]);
            }
            else if (font == 8)
            {
                printf("%s",eight[i]);
            }
            else if (font == 9)
            {
                printf("%s",nine[i]);
            }
             if( len != l)
            {
                int div = pow(10,(len-l));
                number = number%div;
            }
            
        }
        printf("\n");
    }
    return 0;
}