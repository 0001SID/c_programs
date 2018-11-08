#include<stdio.h>
#include<stdarg.h>
int max(int total,...)
{
    int num,max;
    va_list ptr;
    va_start(ptr,total);
    max = va_arg(ptr,int);
    for(int i = 1;i<= total;i++)
    {
        num = va_arg(ptr,int);
        if (num > max)
        {
            max = num;
        }
    }
    return max;
}
int main()
{
    int maxi = max(5,1,5,5,6,4);
    printf("%d\n",maxi);
}