#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
    int i, j, k,m=1, n = 1,speed,distance,max = 100;
    spd:
    printf("Enter the speed (Max 100)\n");
    scanf("%d",&speed);
    if(speed > max)
    {
        printf("Engine overheated can't start Please adjust speed\n");
        goto spd;
    }
    printf("Enter the distance you want to drive (Be sure that your screen has the length)\n");
    scanf("%d",&distance);
    while (m<distance)
    {
        printf("\a");
        usleep(10000-speed*10);
        system("clear");
        for (i = 1; i <= 8; i++)
        {
            for (k = 0; k < n; k++)
            {
                printf(" ");
                if ((i == 8 && k==0))
                {
                    if(n %50 == 0)
                    { n = 1;}
                    n++;
                    m++;
                }

            }
            for (j = 1; j <= 50; j++)
            {
                if (i == 1)
                {
                    if (j > 24 && j <= 33)
                        printf("*");
                    else
                        printf(" ");
                }
                else if (i == 2)
                {
                    if (j == 24 || j == 29 || j == 35)
                        printf("*");
                    else
                        printf(" ");
                }
                else if (i == 3)
                {
                    if (j == 23 || j == 29 || j == 38)
                        printf("*");
                    else
                        printf(" ");
                }
                else if (i == 4)
                {
                    if ((j > 4 && j <= 8) || j == 10 || j == 11 || j == 15 || j == 16 || (j > 20 && j <= 50))
                        printf("*");
                    else
                        printf(" ");
                }
                else if (i == 5)
                {
                    if (j == 3 || j == 13 || j == 18 || j == 20 || j == 50)
                        printf("*");
                    else if (j == 19)
                        printf("-");
                    else
                        printf(" ");
                }
                else if (i == 6)
                {
                    if (j == 2 || j == 19 || j == 21 || j == 28 || j == 29 || j == 42 || j == 43 || j == 50)
                        printf("*");
                    else if (j == 8)
                    {
                        printf("PASSION");
                        j = 15;
                    }
                    else if (j == 20)
                        printf("-");
                    else
                        printf(" ");
                }
                else if (i == 7)
                {
                    if (j == 3 || j == 10 || j == 18 || j == 20 || j == 26 || j == 31 || j == 40 || j == 45 || j == 50)
                        printf("*");
                    else if (j == 19)
                        printf("-");
                    else
                        printf(" ");
                }
                else if (i == 8)
                {
                    if ((j > 3 && j <= 8) || (j > 11 && j <= 14) || j == 16 || j == 17 || (j > 19 && j <= 25) || (j > 31 && j <= 39) || (j > 45 && j <= 50))
                        printf("*");
                    else
                        printf(" ");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}