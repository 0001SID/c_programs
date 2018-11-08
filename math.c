#include<stdio.h>
#include<stdlib.h>
int main()
{
	int you, father, mother, brother,fdif,mdif,bdif;
	char year[10];
	puts("What is your age?");
	gets(year);
	you = atoi(year);
	puts("What is your father's age?");
	gets(year);
	father = atoi(year);
	puts("What is your mother's age?");
	gets(year);
	mother = atoi(year);
	puts("What is your brother's age?");
	gets(year);
	brother = atoi (year);
	/*fdif = father - you;	//We can use this predetermined int otherwise we can use the direct form.
	mdif = mother - you;
	bdif = you - brother;*/
	printf("Your age is %d.\n",you);
	printf("Your father's age is %d.\n",father);
	printf("Your mother's age is %d.\n",mother);
	printf("Your brother's age is %d.\n",brother);
	printf("your father is %d years older than you.\n",father-you);
	printf("Your mother is %d years older than you.\n",mother-you);
	printf("Your brother is %d years smaller than you.\n",you-brother);
	system("pause");
	return(0);
}
