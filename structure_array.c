#include<stdio.h>
//void linkfloat();
int main()
{
    struct book
    {
        char name;
        float price;
        int page;
    };
    struct book b[2];
    int i;
    for (i = 0 ; i <= 1;i++)
    {
        printf("Enter the name price and page");
        fflush(stdin);
        scanf("%c %f %d",&b[i].name,&b[i].price,&b[i].page);

    }
    for (i = 0 ; i <= 1 ; i++)
    {
        printf("%c %f %d\n",b[i].name,b[i].price,b[i].page);
    }
    return 0;
}
/*void linkfloat()
{
    float a = 0, *b;
    b = &a;
    a = *b;
}*/