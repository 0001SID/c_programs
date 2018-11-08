#include<stdio.h>
#include<conio.h>
main()
{
	char gf[20];
	puts( "write the name of your crush, I will say the future?");
	gets(gf);
	printf( "Idiot %s can't be your.\n",gf);/*if we use puts() here it's showing argument error*/
	//system("pause");
	return(0);
}
/*Printf() is more effective than puts().
if I want to output the variable by put I have to write the program like this.

#include<stdio.h>
main()
{
	char gf[20];
	puts( "write the name of your crush, I will say the future?");
	gets(gf);
	puts("Idiot");
	puts(gf);
	puts("can't be your");
}
*/
