#include<stdio.h>
void hello()
{
    printf("Hello");
    hello();
}
int main()
{
    hello();
    return 0;
}