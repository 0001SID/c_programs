#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
    printf("Enter the Driver name\n");
    char driver[20];
    gets(driver);
    for(int i = 1; i <= 13; i++)
    {
        for(int j = 1; j <= 87;j++)
        {
            if(i == 1)
            {
                if(j <=33 || j >=69)
                {
                    printf(" ");
                }
                else
                printf("_");
            }
            else if( i == 2)
            {
                if(j == 29) printf("/");
                else if(j == 71) printf("\\");
                else if( j == 31 || j == 69) printf(".");
                else if((j >32 && j<=48)||(j>50 && j<=67)) printf("-");
                else printf(" ");
            }
            else if( i == 3)
            {
                if ( j == 27 || j == 29) printf("/");
                else if( j == 70 || j == 72) printf("\\");
                else if(j == 49 || j == 50) printf("|");
                else printf(" ");
            }
            else if(i == 4)
            {
                if ( j == 25 || j == 27) printf("/");
                else if( j == 71 || j == 73) printf("\\");
                else if(j == 49 || j == 50) printf("|");
                else printf(" ");
            }
            else if( i == 5)
            {
                if ( j == 23 || j == 25) printf("/");
                else if( j == 72 || j == 74) printf("\\");
                else if(j == 49 || j == 50) printf("|");
                else printf(" ");
            }
            else if( i == 6)
            {
                if ( j == 21 || j == 23) printf("/");
                else if( j == 73 || j == 75) printf("\\");
                else if(j == 49 || j == 50) printf("|");
                else if( (j >23 && j<=48) || (j >50 && j<=72)) printf("_");
                else printf(" ");
            }
            else if( i == 7)
            {
                if (j >10 && j <=76) printf("*");
                else printf(" ");
            }
            else if( i == 8)
            {
                if(j == 11 || j == 76) printf("*");
                else if( j >11 && j<= 75) printf("-");
                else if ( j == 87) printf("(");
                else printf(" ");
            }
            else if( i == 9)
            {
               if( j == 11 || j == 82) printf("(") ;
               else if( j ==46)
               {
                   printf("HONDA");
                   j = 51;
               }
               else if ( j == 77) printf("|");
               else printf(" ");
            }
            else if ( i == 10)
            {
                if( j == 11) printf("*");
                else if( j ==76) printf("|");
                else if( j >76 && j <= 79) printf("_");
                else if ( j == 80) printf( "(");
                else printf(" ");
            }
            else if( i == 11)
            {
                if( j ==11 || j == 26 || j == 27 || j == 63 || j == 64) printf("*");
                else if( j == 76) printf("|");
                else if(j > 76 && j<= 79) printf("-");
                else if(j == 80) printf("(");
                else printf(" ");
            }
            else if( i == 12)
            {
                if((j > 10 && j<= 20)||(j > 32 && j<= 57)||(j >70 && j <= 76)) printf("*");
                else if(j == 21 || j ==58 || j== 82) printf("(");
                else if( j ==32 || j == 70) printf(")");
                else if( j ==26 || j == 64) printf("0");
                else printf(" ");
            }
            else if ( i == 13)
            {
                if (j == 26 || j == 27 || j == 63 || j == 64) printf("*");
                else if( j == 87) printf("(");
                else printf(" ");
            }

        }
        usleep(50000);
        printf("\n");
    }
    printf("\n\n");
    printf("%73s : %s\n","DRIVER NAME",driver);
    return 0;

}