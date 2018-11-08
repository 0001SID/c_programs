#include <stdio.h>
#include <conio.h>
#include <math.h>
#define turbo 0

void clear()
{
    fflush(stdin);
}
int grange(char a[20],int range)
{
    int b;
	#if turbo == 1
    textcolor(RED+BLINK);
	#endif
    b = strlen(a);
    if(b<=range)
    {
	return (a);
    }
    else
    {
	cprintf("Sorry Out of range...\a");
	printf("\n");
	cprintf("Please enter in range");
	printf("\n");
	gets(a);
	grange(a,range);
    }
}
int gfloat(int range)
{

    char b[20],*c,d[20];
    int value = 1,i,j = 0,k,e;
	#if turbo == 1
    textcolor(RED+BLINK);
	#endif
    while (value == 1) //Loop for checking numeric or alphabetic input
    {
	clear();
	gets(b);
	c = grange(b,range);
	for (i = 0;i <= 20;i++)
	{
		d[i] = *(c+i);
	}
	i = strlen(d);
	for(k = 0;k<i;k++)
	{
		e = isdigit(d[k]);
		clear();
		if(d[k] == '.')
		{
			j = 0;
			
		}
		else if(e>0)
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
	    return atof(d);
	    break;
	}
	else
	{
	    cprintf("Please enter an appropiate value");
		printf("\n");
	}
    }
}
void si()
{
    float p, r, t;
    long double smi;
    printf("\nEnter the total amount\n");
    p = gfloat(6);
    printf("Enter the rate of interest\n");
    r = gfloat(3);
    printf("Enter the total time in year\n");
    t = gfloat(3);
    smi = (p * r * t) / 100;
	#if turbo == 1
    textcolor(GREEN);
	#endif
    cprintf("simple interest: %.2Lf", smi);
    printf("\n");
    cprintf("Amount with interest: %.2Lf", smi + p);
    printf("\n\n");

}
void ci()
{
    float p, r, t, n;
    long double cmi;
    printf("\nEnter the total amount\n");
    p = gfloat(6);
    printf("Enter the rate of interest\n");
    r = gfloat(2);
    printf("Enter the total time in year\n");
    t = gfloat(2);
    printf("How many times interest compounded per year\n");
    n = gfloat(1);
    cmi = p * pow((1 + r / (100 * n)), n * t);
	#if turbo == 1
    textcolor(GREEN);
	#endif
    cprintf("Compounded interest: %.2Lf", cmi - p);
    printf("\n");
    cprintf("Amount with interest: %.2Lf", cmi);
    printf("\n\n");

}
int main()
{
    int i;
    char type,l;
    system("cls");
    i = 1;
    while (i < 2) //To calculate repeatedly
    {
		clear();
		printf("Which type of interest you want to calculate?\n");
		printf("Compound(c) / Simple(s) / Exit(e)\n");
		clear();
		#if turbo == 1
		textcolor(WHITE);
		#endif
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
			#if turbo == 1
			textcolor(RED+BLINK);
			#endif
			printf("\n");
			cprintf("You have entered a wrong keyword");
			printf("\n");
			cprintf("Please type again");
			printf("\n");
			continue;
		}
		#if turbo == 1
		textcolor(WHITE);
		#endif
		printf("Do you want to calcualte again?(y/n) ");
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
			#if turbo == 1
			textcolor(RED+BLINK);
			#endif
			printf("\n");
			cprintf("Please enter appropiate keyword\a");
			printf("\n");
			goto rep;
		}
	}
    return 0;
}