#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
    int name;
    printf("Enter your name");
    scanf("%d",&name);
    //scanf("%[^\n]s",name);
    printf("hi %d\n",name);
    char fname[30];
    /*int i;
    for (i = 0; i <= strlen(name)-1;i++)
    {
        printf("%c \n",name[i]);
    }*/
    puts("Enter your full name");
    gets(fname);
    //scanf("%[^\n]s",fname);
    printf("your full name is %s",fname);
}