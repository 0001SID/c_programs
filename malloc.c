#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *names[6];
    char *p;
    char n[20];
    int i,len;
    for (i = 0;i<6;i++)
    {
        printf("Enter the name %d: ",i+1);
        scanf("%s",n);
        len = strlen(n);
        p = (char *)malloc(len+1);
        strcpy(p,n);
        names[i] = p;
    }
    printf("The names are:\n");
    for (i = 0 ; i <6; i ++)
    {
        printf("%s\n",names[i]);
    }
    return 0;
}
