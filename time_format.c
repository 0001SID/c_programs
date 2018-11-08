#include<stdio.h>
#include<stdlib.h>
int main()
{
    char tim[10];
    static char temp[2];int t;
    gets(tim);
    for(int i = 0; i<2; i++)
    {
        temp[i] = tim[i];
    }
    t = atoi(temp);
    if(tim[8] == 'P')
    {
        if(t == 12) printf("%02d",t);
        else
        printf("%02d",t+12);
    }
    else
    {
        if(t == 12)printf("00");
        else
        printf("%02d",t);
    }
    for(int i = 2 ; i<8; i++)
    {
        printf("%c",tim[i]);
    }
    return 0;
}