#include<stdio.h>
int main()
{
    struct name
    {
        int num :3;// use one bit greater than the assigned vlue's bit otherwise it will give a negetive number when it takes the maximym bit of a number.
    }a;
    a.num = 4;
    printf("%d\n",a.num);
    return 0;
}