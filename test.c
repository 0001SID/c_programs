#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp; char c;
    fp = fopen("file.txt","w");
    fprintf(fp,"This is the new content");
    fclose(fp);
    fp = fopen("file.txt","r");
    while (1)
    {
        c = fgetc(fp);
        if(c == EOF)
        {
            break;
        }
        printf("%c",c);
    }
    fclose(fp);
    return 0;
}