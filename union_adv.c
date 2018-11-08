#include<stdio.h>
int main()
{
    struct a{
        int i;
        char c[2];
    };
    struct b{
        int j;
        char d[2];
    };
    union z{
        struct a key;
        struct b data;
        char e[3];
    };
    union z strange;
    strange.key.i = 32960;
    strange.data.d[0] = 10;
    strange.data.d[1] = 32;
    printf("%d\n",strange.key.i);
    printf("%d\n",strange.key.c[0]);
    printf("%d\n",strange.key.c[1]);
    printf("%d\n",strange.data.j);
    printf("%d\n",strange.data.d[0]);
    printf("%d\n",strange.data.d[1]);
    printf("this is the numbers in character\n");
    for(int i = 0;i <= 3;i++)
    {
    printf("%d  ",strange.e[i]);
    }
    printf("sixe %d",sizeof(int));
    return 0;
}