#include<stdio.h>
int main()
{
    FILE *fp,*t;
    fp = fopen("file.txt","w");
    t = fopen("source.txt","w");
    if(t == NULL)
    {
        printf("Can't open tatget file");
    }
    printf("Enter any string\n");
    char str[70];
    if (fp == NULL)
    {
        printf("Can't open file");
    }
    while (strlen(gets(str))>0)
    {
        fputs(str,fp);
        fputs("\n",fp);
    }
    fclose(fp);
    fp = fopen("file.txt","r");
    if(fp == NULL)
    {
        printf("Can't open source file");
    }
    while(fgets(str,4,fp) != NULL)
    {
        fputs(str,t);
    }

    return 0;
}
