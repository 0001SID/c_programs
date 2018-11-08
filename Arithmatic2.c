#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define turbo 0
#define operator(i) (eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*')
void clear();
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
        #if turbo == 1
        cprintf("Sorry Out of range...\a");
        printf("\n");
        cprintf("Please enter in range");
        printf("\n");
        #else
        printf("Sorry Out of range...\a");
        printf("\n");
        printf("Please enter in range");
        printf("\n");
        #endif
        gets(a);
        grange(a,range);
    }
}
int gfloat(float *result,int range)
{

    char b[20],*c,d[20],e;
    int value = 1,i,j = 0,k;
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
	    *result = atof(d);
	    break;
	}
	else
	{
        #if turbo == 1
	    cprintf("Please enter an appropiate value");
		printf("\n");
        #else
	    printf("Please enter an appropiate value");
		printf("\n");
        #endif
	}
    }
}
int calculate(float *a,char *b,int j)
{
    int plus =0,minus =0 ,dv =0 ,mult =0,k;
    float num[20];
    int l = j,i;
    for(i = 0;i<j-1;i++)
    {
        if(*(b+i) == '/')   //Calculate the number of division operator
        {
            dv++;
        }
        else if(*(b+i) == '+')
        plus++;     //Calculate the number of summasion operator
        else if (*(b+i) == '-')
        minus++;        //Calculate the number of minus operator.
        else if (*(b+i) == '*')
        mult++;     //Calculate the number of multiplication operator.
        else
        printf("invalid operator");
    }
    for (k = 0; k <j-1;k++)     //For doing next operator's calculation this loop is here.
    {
        if(dv)  //Checking if there any division in the equation.
        {
            for(i = 0;i<j-1;)   //check all the operators
            {
                 if(*(b+i) == '/')
                {
                    *(a+i) = *(a+i)/(*(a+i+1)); //if there is any division then do it.
                    dv--;
                    for( k = i+1;k < l-1;k++)
                    {
                        *(a+k) = *(a+k+1);  //Now rearrenge the array of numbers
                        *(b+i) = *(b+i+1);  //Rearrenge the array of operators
                    }
                    l--;    //After every calculation there must be decrement in element for this l-- is here.
                    i = 0;//if calculation done then we have to check again the operator array that what is the new position of the operator.For this we have to restart the loop.
                    if(dv == 0)
                    {
                        break;  //If there is no any division operator left then break the loop
                    }
                    continue;   //if calculation done then restart the for loop frm 0.
                }
                i++;    //If the current character is not a devision operator then check the next.

            }
        }
        if(mult)
        {
            for(i = 0;i<j-1;)
            {
                if(*(b+i) == '*')
                {
                    *(a+i) = *(a+i)*(*(a+i+1));
                    mult--;
                    for(k = i+1;k < l-1;k++)
                    {
                        *(a+k) = *(a+k+1);
                        *(b+i) = *(b+i+1);
                    }
                    l--;
                    i =0;
                    if(mult == 0)
                    {
                        break;
                    }
                    continue;
                }

                i++;
            }

        }
        if(plus)
        {
            for(i = 0;i<j-1;)
            {
                 if(*(b+i) == '+')
                {
                    *(a+i) = *(a+i)+(*(a+i+1));
                    plus--;
                    for(k = i+1;k < l-1;k++)
                    {
                        *(a+k) = *(a+k+1);
                        *(b+i) = *(b+i+1);
                    }
                    l--;
                    i = 0;
                    if(plus == 0)
                    {
                        break;
                    }
                    continue;
                }
                i++;
            }
        }
        if(minus)
        {
            for(i = 0;i<j-1;i++)
            {
                if(*(b+i) == '-')
                {
                    *(a+i) = *(a+i)-(*(a+i+1));
                    minus--;
                    for(k = i+1;k < l-1;k++)
                    {
                        *(a+k) = *(a+k+1);
                        *(b+i) = *(b+i+1);
                    }
                    l--;
                    i = 0;
                    if(minus == 0)
                    {
                        break;
                    }
                    continue;
                }
                i++;
            }
        }
    }
}
void clear()
{
    fflush(stdin);
}
int equation()
{
    char eq[100],err[30];
    int eq_len,ck_eq = 0,ck_err = 0,arr_err = 0;
    int i = 0,j = 0,totalop =0;
    printf("Enter any equation\n");
    while(1)
    {
        clear();
        memset(err,0,sizeof(err));
        j = 0,ck_err = 0,arr_err =0;
        gets(eq);
        eq_len = strlen(eq);
        for(i = 0; i<eq_len;i++)    //This loop is for checking if there is any error in the equation.
        {
            if(eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*')  //Checks if the character is operator or not.
            {
                ck_eq = 0;
                totalop++;
            }
            else if (eq[i] == '.')      //Checks if there is any float number.
            {
                ck_eq = 0;
            }
            else if(isdigit(eq[i])>0)   //checks if the character is number or not.
            {
                ck_eq = 0;

            }
            else
            {
                j++;
                err[j] = eq[i];     //Collects the errors in the equation.
                ck_err++;
            }
            if(operator(0)||(operator(i)&&operator(i+1)))
            {
                arr_err++;  //checks if there is any arrangement error or not.
            }
        }
        if(ck_err  != 0)    //if there is any font error then these message are shown..
        {
            #if turbo == 1
            textcolor(RED+BLINK);
            cprintf("Error in equation");
            printf("\n")
            cprintf("You can't use ");
            #else
            printf("Error in equation\n");
            printf("You can't use ");
            #endif
            for(j = 1; j<= ck_err;j++)
            {
                #if turbo == 1
                cprintf("'%c' ",err[j]);
                #else
                printf("'%c' ",err[j]);
                #endif
            }
            #if turbo ==1
            printf("\n");
            cprintf("Please enter valid equation");
            printf("\n");
            #else
            printf("\nPlease enter valid equation\n");
            #endif
        }
        else if(arr_err != 0)       //If there is any arrangement error then this message is shown.
        {
            #if turbo == 1
            cprintf("There is a arrengment error in the equation\nPlease re-enter the equation");
            printf("\n");
            #else
            printf("There is a arrengment error in the equation\nPlease re-enter the equation\n");
            #endif
        }
        else
        {
            break;  //If there is no error then break the loop.
        }
    }
    float num[20];
    char charopr[20],temp[20];
    int k = 0;
    j = 0;
    for(i = 0;i<eq_len;i++)
    {
        if(operator(i))     //The block of codes separate the numbers from the whole string.
        {
            charopr[j] = eq[i];     //Collect the operators and save them in a array.
            num[j] = atof(temp);    //Collects the numbers and save them in a array..
            memset(temp,0,sizeof(temp));    //Once the data is collected form temp array then its clear the temp array.
            k =0;  //reset the float number of the temp array.
            j++;    //collects the number of operators.
        }
        if(!operator(i))    //Check the character is operator or not.
        {
            temp[k] = eq[i];    //If the character is not a operator then it's save in a temporary array to collect them later at once.thats how we are getting the full number.
            k++;    //jump to the next element in temp array.
        }
        if (j == totalop && i == eq_len-1)  //This conditon is to store the last number in num array.Because the first condition is not able to take the last number in the equation.
        {
            num[j] = atof(temp); //heres the last number is save to the num array.
        }
    }
    calculate(num,charopr,j+1); //At last when the all number and operators are collected seperately then we pass them is the calculate function to calculate them correctly.
    printf("%.3f",*num);    //In the calculate function the first element of the num array is changed in the calculated ans in the function.
                            //and here we are printing the result as our output.we can get the ans directly by putting *num because we passes the reference of the num array to the function.
}
int main()
{
    char r,res;
    float a,b;
    while (1)
    {
        system("cls");
        printf("\nWhat you want to do?\n");
        printf("sum(s),mult(m),division(d),subtraction(u),equation(e),Exit(E)\n");
        while(1)
        {
            clear();
            r = getche();
            if ( r == 's' || r == 'm' || r == 'd' || r == 'e' ||r == 'u' || r == 'E')
            {
                break;
            }
            else
            {
                #if turbo == 1
                textcolor(RED+BLINK);
                printf("\n");
                cprintf("You have entered a wrong keyword please re-enter");
                printf("\n");
                #else
                printf("\nYou have entered a wrong keyword please re-enter\n");
                #endif
            }
        }
        clear();
        if(r=='e')
        {
            printf("\n");
            equation();
        }
        else if(r == 'E')
        {
            printf("\nGood Bye");
            break;
        }
        else
        {
            printf("\nEnter the first number\n");
            gfloat(&a,12);
            printf("Enter the second number\n");
            gfloat(&b,12);

            switch(r)
            {
                case 's':
                    printf("The sum of %.3f and %.3f is %.3f",a,b,a+b);
                    break;
                case 'm':
                    printf("The multiply of %.3f and %.3f is %.3f",a,b,a*b);
                    break;
                case 'u':
                    printf("The subtraction of %.3f and %.3f is %.3f",a,b,a-b);
                    break;
                case 'd':
                    printf("The division of %.3f and %.3f is %.3f",a,b,a/b);
                    break;
            }
        }
        printf("\nDo you want to calculate again(y/n)\n");
        rep:
        res = getche();
        if(res == 'y')
        {
            continue;
        }
        else if (res == 'n')
        {
            break;
        }
        else
        #if turbo == 1
        printf("\n");
        cprintf("You have entered a wrong keyword");
        printf("\n");
        cprintf("Please try again");
        printf("\n");
        #else
        printf("\nYou have entered a wrong keyword\nPlease try again\n");
        #endif
        goto rep;
    }

}
