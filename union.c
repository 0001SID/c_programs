#include<stdio.h>
int main()
{
    union sid
    {
        int i;
        char c[1];

    }number;
    number.i = 512;
    printf("%d\n",number.i);
    printf("%d\n",number.c[0]);
    printf("%d\n",number.c[1]);
    number.c[0] = 50;
    printf("after assign\n%d\n",number.i);
    printf("%d\n",number.c[0]);
    printf("%d\n",number.c[1]);
    return 0;
}
