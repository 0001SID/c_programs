#include<stdio.h>
int main()
{
    struct book 
    {
        char name[100];
        int page;
    };
    struct booooook{
        char ame[100];
        int page;
    }m[10];
    struct book b[10] = {0};
    int i;
    char c[100];
    for ( i = 0; i <= 10; i++)
    {
        printf("\nEnter the name of the book  ");
        fflush(stdin);
        gets(c);
        strcpy(b[i].name,c);
        printf("\nEnter the page number of %s book  ",c);
        scanf("%d",&b[i].page);
        printf("\nDo you want to save more book?(y/n)");
        if (getche() == 'y')
        {

        }
        else
        {
            break;
        }
    }
    for(int j = 0 ;j <5; j++)
        {
            printf("This is in the for loop:\n%s %d\n",b[j].name,b[j].page);
        }
    FILE *f,*t;
    f = fopen("Book.DAT","w");
    if (f == NULL)
    {
        printf("Can't create file");
    }
    fwrite(&b,sizeof(b),1,f);
    fclose(f);
    t = fopen("Book.DAT","r");
    if (t == NULL)
    {
        printf("Can't open file to read");
    }
    while (fread(&m,sizeof(b),1,t) == 1)
    {
        for(int j = 0 ;j <5; j++)
        {
            printf("This is in the file:\n%s %d\n",m[j].ame,m[j].page);
        }
    }
    fclose(t);
    return 0;


}