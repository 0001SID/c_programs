#include<stdio.h>
int main()
{
    printf("Enter the first number ");
    int a,b;
    scanf("%d",&a);
    printf("Enter the number of element in the series ");
    scanf("%d",&b);
    int i=1;
    int fst = 0,snd = a,trd;
    printf("The fibonacci series is:\n");
    printf("%d",a);
    for(;i < b;)
    {
        trd = fst +snd;
        fst = snd;
        snd = trd;
        if(trd > b) break;
        printf(" %d",trd);
        i++;

    }
    return 0;
}