#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp,*ft;
    int noc =0, not=0,nob=0,nol=1;
    long unsigned int byte;
    char a;
    fp = fopen("source.txt","r");
    ft = fopen("file.txt","w");
    if (fp == NULL)
    {
        printf("File can't open");
        exit(1);
    }
    while (1)
    {
        a = fgetc(fp);
        if(a == EOF)
        {
            break;
        }
        noc++;
        if (a == '\t')
        {
            not++;
        }
        if(a == ' ')
        {
            nob++;
        }
        if (a == '\n')
        {
            nol++;
        }
        fputc(a,ft);

    }
    printf("\nIn the above text..............\n");
    printf("The number of characters is %d\n",noc);
    printf("The number of tabs is %d\n",not);
    printf("The number of spaces is %d\n",nob);
    printf("The number of lines is %d\n",nol);
    fclose(fp);
}