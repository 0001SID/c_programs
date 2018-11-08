#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *source,*target;
    printf("Enter the source file path");
    // char spath[100],tpath[100];
    char c[10];
    // gets(spath);
    // printf("Enter the target file path");
    // gets(tpath);
    source = fopen("file.txt","wb");
    target = fopen("target.txt","wb");
    if (source == NULL || target == NULL )
    {
        printf("Problem in opening file");
        exit(1);
    }
    while (1)
    {
        if (fread(&c,1,1,source) == 0)
        {
            if(ferror(source))
            {
                perror("source");
                break;
            }
            break;
        }
        else
        fwrite(&c,1,1,target);
    }
    fclose (source);
    fclose(target);
    return 0;
}