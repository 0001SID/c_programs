#include<stdio.h>
main()
{
	char r;
	puts("type any key");
	r = getchar();
	printf("You type '%c'",r);
	printf("The ASCII value of this key id %d",r);
}
