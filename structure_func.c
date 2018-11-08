#include<stdio.h>
void display(struct book *);
struct book 
{
    char name[10];
    int page;
};
int main()
{
    struct names 
    {
        int a;
    }b1;
    b1.a = 10;
    struct book b;
    struct book *ptr;
    char c[10] = "let us c";
    strcpy(b.name,c);
    b.page = 700;
    ptr = &b;
    display(ptr);
    printf("%s %d\n",b.name,b1.a);
    printf("%s %d",ptr->name,ptr->page);
    return 0;

}
void display(struct book *b)
{
    printf("%s %d\n",b->name,b->page);
}