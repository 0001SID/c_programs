#include<stdio.h>
main()
{
	char name[20];
	char colour[10];
	printf("What is your name?\n");
	scanf("%s",name);
	printf("What is your favourite colour?\n");
	scanf("%s", colour);
	printf("%s's favourite colour is %s\n",name,colour);
	system ("pause");
	return(0);
}
