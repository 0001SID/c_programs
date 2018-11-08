#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define operator (eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*'||eq[i] == '^')
#define nonoperator (eq[i] != '+'||eq[i] != '-'||eq[i] != '/'||eq[i] != '*'||eq[i] != '^')
#define braces (eq[i] == '('||eq[i] == ')')
int bcalculate(float *a, char b)
{
    switch(b)
    {
        case '+':
            return (*a + *(a+1));
            break;
        case '-':
            return (*a - *(a+1));
            break;
        case '*':
            return (*a * *(a+1));
            break;
        case '/':
            return (*a / *(a+1));
            break;
    }
}

int calculate(float *a,char *b,int j)
{
    int plus =0,minus =0 ,dv =0 ,mult =0;
    float num[20];
    int l = j,i;
    for(i = 0;i<j-1;i++)
    {
        if(*(b+i) == '/')
        {
            dv++;
        }
        else if(*(b+i) == '+')
        plus++;
        else if (*(b+i) == '-')
        minus++;
        else if (*(b+i) == '*')
        mult++;
        else
        printf("invalid operator");
    }
    for (int k = 0; k <j-1;k++)
    {
    if(dv)
    {
        for(i = 0;i<j-1;)
        {
            *(a+i) = *(a+i)/(*(a+i+1));
            dv--;
            for(int k = i+1;k < l-1;k++)
            {
                *(a+k) = *(a+k+1);
                *(b+k) = *(b+k+1);
            }
            l--;
            if(mult == 0)
            {
                break;
            }
            i = 0;
            
        }
    }
    else if(mult)
    {
        for(i = 0;i<j-1;)
        {
            *(a+i) = *(a+i)*(*(a+i+1));
            mult--;
            for(int k = i+1;k < l-1;k++)
            {
                *(a+k) = *(a+k+1);
                *(b+k) = *(b+k+1);
            }
            l--;
            if(mult == 0)
            {
                break;
            }
            i = 0;
        }
        
    }
    else if(plus)
    {
        for(i = 0;i<j-1;)
        {
            *(a+i) = *(a+i)+(*(a+i+1));
            plus--;
            for(int k = i+1;k < l-1;k++)
            {
                *(a+k) = *(a+k+1);
                *(b+k) = *(b+k+1);
            }
            l--;
            if(plus == 0)
            {
                break;
            }
            i = 0;

        
        }
    }
    else if(minus)
    {
        for(i = 0;i<j-1;i++)
        {
            *(a+i) = *(a+i)-(*(a+i+1));
            minus--;
            for(int k = i+1;k < l-1;k++)
            {
                *(a+k) = *(a+k+1);
                *(b+k) = *(b+k+1);
            }
            l--;
            if(minus == 0)
            {
                break;
            }
            i = 0;
        }
    }
    }
    return (*a);
}
void clear()
{
    fflush(stdin);
}
int main()
{
    char eq[100],err[30];
    int eq_len,ck_eq = 0,brace = 0,ck_err = 0,arr_err = 0;
    int i = 0,j = 0;
    printf("Enter any equation\n");
    while(1)
    {
        clear();
        memset(err,0,sizeof(err));
        j = 0,ck_err = 0,arr_err =0;
        gets(eq);
        eq_len = strlen(eq);
        for(i = 0; i<eq_len;i++)
        {
            if(eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*'||eq[i] == '^'||eq[i] == '.')
            {
                ck_eq = 0;
            }
            else if(eq[i] == '('||eq[i] == ')')
            {
                ck_eq = 0;
                brace++;
            }
            else if(isdigit(eq[i])>0)
            {
                ck_eq = 0;

            }
            else
            {
                j++;
                err[j] = eq[i];
                ck_err++;
            }
            if((i >1 && isdigit(eq[i-1])>0 && (eq[i] == '(' || eq[i] == ')'))||((eq[i-1] == '(' || eq[i-1] == ')')&&(eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*'||eq[i] == '^'))||eq[0] == ')' || (eq[0] == '+'||eq[0] == '-'||eq[0] == '/'||eq[0] == '*'||eq[0] == '^'))
            {
                arr_err++;
            }
        }
        if(ck_err  != 0)
        {
            printf("Error in equation\n");
            printf("You can't use ");
            for(j = 1; j<= ck_err;j++)
            {
                printf("%c ",err[j]);
            }
            printf("\n");
        }
        else if(arr_err != 0)
        {
            printf("There is a arrengment error in the equation\nPlease re-enter the equation");
        }
        else
        {
            break;
        }
    }
    char temp[20],obraceopr[20];
    float num[20],fnum[40],obracenum[20],cbracenum[20],result;;
    char charopr[20],fopr[20],cbraceopr[20],btempnum[5];
    int k = 0,fn = 0,fo =0,bopen = 0,bclose = 0,lcheck = 0;
    j = 0;
    for(i = 0;i<eq_len;i++)
    {
        if(operator || eq[i] == ')')
        {
            if (operator)
            {
                charopr[j] = eq[i];
            }
            num[j] = atof(temp);
            memset(temp,0,sizeof(temp));
            k =0;
            j++;

        }
        if(bopen == 0 && (operator && (eq[i+1] == '(')))
        {
            fnum[fn] = calculate(num,charopr,j);
            fopr[fo] = eq[i];
            memset(num,0,sizeof(num));
            memset(charopr,0,sizeof(charopr));
            fn++;
            fo++;
            j =0;
            continue;

        }
        if(operator && (eq[i-1] == ')'))
        {
            lcheck++;
        }
        if(eq[i] == '(' && lcheck ==1)
        {
            bopen++;
            fnum[fn] = calculate(num,charopr,j);
            fopr[fo] = eq[i];
            memset(num,0,sizeof(num));
            memset(charopr,0,sizeof(charopr));
            j =0;
            fn++;
            fo++;
            continue;
        }
        if(bopen != 0 && operator && (eq[i+1] == '('))
        {
            
            obracenum[bopen] = calculate(num,charopr,j);
            obraceopr[bopen] = eq[i];
            memset(num,0,sizeof(num));
            memset(charopr,0,sizeof(charopr));
            j =0;
            continue;
        }
        if(bopen != 0 && eq[i] == ')')
        {
            if(num[0])
            {
                cbracenum[bopen] = calculate(num,charopr,j);
                j =0;
                memset(num,0,sizeof(num));
                memset(charopr,0,sizeof(charopr));
            }
            else
            {
                if(cbracenum[bopen+1])
                {
                    btempnum[0] = obracenum[bopen];
                    btempnum[1] = cbracenum[bopen+1];
                    cbracenum[bopen] = bcalculate(btempnum,obraceopr[bopen]);
                    memset(btempnum,0,sizeof(btempnum));
                }
            }
            if(eq[i+1] && (eq[i+1] == '+'||eq[i+1] == '-'||eq[i+1] == '/'||eq[i+1] == '*'))
            {
                cbraceopr[bopen-1] = eq[i+1];
            }
            if(cbracenum[bopen+1] && cbracenum[bopen])
            {
                btempnum[0] = cbracenum[bopen+1];
                btempnum[1] = cbracenum[bopen];
                cbracenum[bopen] = bcalculate(btempnum,cbraceopr[bopen]);
                memset(btempnum,0,sizeof(btempnum));
                if(obracenum[bopen])
                {
                    btempnum[0] = obracenum[bopen];
                    btempnum[1] = cbracenum[bopen];
                    cbracenum[bopen] = bcalculate(btempnum,cbraceopr[bopen]);
                    memset(btempnum,0,sizeof(btempnum));
                }


            }
            memset(num,0,sizeof(num));
            memset(charopr,0,sizeof(charopr));
            bopen--;
            if(bopen == 0)
            {
                fnum[fn] = cbracenum[1];
                fn++;
                memset(cbraceopr,0,sizeof(cbraceopr));
                memset(cbracenum,0,sizeof(cbracenum));
                memset(obracenum,0,sizeof(obracenum));
                memset(obraceopr,0,sizeof(obraceopr));

            }
            continue;
        }
        if(!operator && !braces)
        {
            temp[k] = eq[i];
            k++;
        }
    }
    result = calculate(fnum,fopr,(fo+1));
    printf("%f %s %s",fnum[1],fopr,fo);
      
}