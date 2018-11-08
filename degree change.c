//Convert Degree centigrate to degree farenhite(F)//

#include<stdio.h>
main()
{
	float c,f;
	printf("Enter the temperature in centigrate\n");
	scanf("%f",&c);
	f = (1.8*c)+32;
	printf("The temperature in farenhite is %f \n",f);
	system ("pause");
	return(0);
}
