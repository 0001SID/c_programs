#include<stdio.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#define operator(i) (eq[i] == '+'||eq[i] == '-'||eq[i] == '/'||eq[i] == '*')
void clear()
{
    fflush(stdin);
}
int main()
{
    char res;
    do
    {
        FILE *p,*state;
        char eq[50],dir[100],fdir[100],tdir[00],envio[100],envcmd[100],fcmd[100],compdir[100];
        char frcmd[100],dstate[100];
        char err[30];
        int eq_len,ck_eq = 0,ck_err = 0,arr_err = 0;
        int i = 0,j = 0;
        int l;
        char process,statec;
        _getcwd(tdir,100);
        _getcwd(compdir,100);
        strcpy(dstate,tdir);
        strcat(dstate,"\\state.txt");
        state = fopen(dstate,"r");
        if(state == NULL)
        {
            printf("Can't open file");
        }
        statec = fgetc(state);
        if(statec == 'y')
        {}
        else
        {
            fclose(state);
            state = fopen(dstate,"w");
            fputc('y',state);
            strcpy(envcmd,"setx path ");
            strcpy(envio,tdir);
            strcat(envio,"\\data\"");
            strcat(envcmd,envio);
            if(system(envcmd)== 0)
            {
                for(i = 1;i<= 10;i++)
                {
                    if (i%2 == 0)
                    {
                        process = '\\';
                    }
                    else
                    {
                        process = '/';
                    }
                sleep(100);
                printf("\r%c %s",process,"Setting up environment for first time use...");
                }
                printf("\n>>C environment set successfully\n");
                fclose(state);
            }
            else
            {
                printf("Environment set error");
                exit(1);
            }
        }
        for(i = 0;i<strlen(tdir);i++)
        {
            dir[j] = tdir[i];
            j++;
            if(tdir[i] == '\\')
            {
                dir[j] = '\\';
                j++;
            }
        }
        strcat(fdir,"\\temp.c");
        p = fopen(fdir,"w");
        fputs("#include<stdio.h>\nint main()\n{\nfloat a;\na = ",p);
        printf("\nEnter any arithmatic expression\n>>");
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
                if((operator(i)&&eq[i+1] == ')')||(operator(i)&&operator(i+1))||(eq[i]==')'&&eq[i+1] == '(')||(eq[i]=='('&&eq[i+1] == ')'))
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
                    printf("'%c' ",err[j]);
                }
                printf("\nPleasse enter again\n>>");
            }
            else if(arr_err != 0)
            {
                printf("There is a arrengment error in the equation\nPlease re-enter the equation\n>>");
            }
            else
            {
                break;
            }
        }
        fclose(p);
        p = fopen(fdir,"a");
        fputs(eq,p);
        fputs(";\nprintf(\"%.3f\",a);\nreturn 0;\n}",p);
        fclose(p);
        again:
        strcpy(fcmd,compdir);
        strcat(fcmd,"\\data\\tcc ");
        strcat(fcmd,tdir);
        strcat(fcmd," -o ");
        strcat(fcmd,tdir);
        l = strlen(fcmd);
        fcmd[l-2] = '.';
        fcmd[l-1] = 'e';
        fcmd[l] = 'x';
        fcmd[l+1] = 'e';
        fcmd[l+2] = '\0';
        if(system(fcmd) == 0)
        {
            for(i = 1;i<= 10;i++)
            {
                if (i%2 == 0)
                {
                    process = '\\';
                }
                else
                {
                    process = '/';
                }
            sleep(100);
            printf("\r%c %s",process,"processing...");
            }
            printf("\n\n=");
        }
        else
        {
            printf("processing error\n");
            system("pause");
            exit(2);
        }
        strcat(frcmd,tdir);
        l = strlen(frcmd);
        frcmd[l-2] = '.';
        frcmd[l-1] = 'e';
        frcmd[l] = 'x';
        frcmd[l+1] = 'e';
        frcmd[l+2] = '\0';
        system(frcmd);
        p = fopen(fdir,"w");
        fclose(fdir);
        printf("\n\n");
        printf("Do you want to calculate again?(y/n)");
        resp:
        res = getche();
        printf("\n");
        if (!(res == 'y' || res =='n'))
        {
            printf("\nPlease enter a valid input");
            goto resp;
        }
        memset(eq,0,sizeof(eq));
        memset(dir,0,sizeof(dir));
        memset(fdir,0,sizeof(fdir));
        memset(tdir,0,sizeof(tdir));
        memset(envio,0,sizeof(envio));
        memset(envcmd,0,sizeof(envcmd));
        memset(fcmd,0,sizeof(fcmd));
        memset(frcmd,0,sizeof(frcmd));
    }while(res == 'y');
    return 0;
}