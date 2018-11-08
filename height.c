#include<stdio.h>
#include<stdlib.h>
main()
{
	char height[20];
	puts("what is your hight in feet?");
	gets(height);
	printf("Your height in centemeter is %5f",atoi(height)*30.48);
	return(0);
}
