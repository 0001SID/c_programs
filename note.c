//A program to calculate note numbers
#include<stdio.h>
#include<conio.h>
int main()
{
    int tn,twnt,trty,frty,ffty;
    printf("Enter the amount you have ");
    int amount;
    scanf("%d",&amount);
    int note=0;
    ffty = amount /50;
    note+=ffty;
    ffty = amount %50;
    frty = ffty/40;
    note+=frty;
    frty = ffty %40;
    trty = frty /30;
    note += trty;
    trty = frty %30;
    twnt = trty /20;
    note += twnt;
    twnt = trty %20;
    tn = twnt / 10;
    note +=tn;
    printf("Smallest numbers of note is %d",note);
    return 0;
    
}