#include<stdio.h>
void fib(int snd,int trd,int count,int se)
{
    int fst;
    if (count >= se)
    {
        printf("\ncomplete");
    }
    else
    {
        fst = snd;
        int snd1 = trd;
        int trd1 = fst+snd1;
        printf("  %d",trd1);
        fib(snd1,trd1,count+1,se);
    }
}
int main()
{
    printf("Enter the first number of series ");
    int a;
    scanf("%d",&a);
    printf("Total number of element in series ");
    int se;
    scanf("%d",&se);
    printf("The fibonacci series is:\n");
    printf("%d",a);
    fib(0,a,1,se);
}