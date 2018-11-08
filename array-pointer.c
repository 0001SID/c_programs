#include<stdio.h>
int main()
{
    int n[] = {1,5,5,46,7};
    int *p;
    p =n;
    int i;
    for (i = 0;i <=5;i++)
    {
        printf("n%d is %d\n",i,*(p+i));
    }
}