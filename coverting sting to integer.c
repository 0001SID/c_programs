#include<stdio.h>
#include<stdlib.h>
main()
{
	int me, you;
	char year[20];
	puts("What is your age?");
	gets(year);
	me = atoi(year);
	puts("What is your best friend's age?");
	gets(year);
	you = atoi(year);
	printf("Your age is %d and your friend's age is %d",me,you);
}