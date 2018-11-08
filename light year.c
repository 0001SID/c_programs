#include<stdio.h>
main()
{
	float earth, speed, time;
	earth = 15E10;
	speed = 3E8;
	time = (earth/speed)/60;
	puts("Light takes time to reach earth is --\n");
	printf("%.2f minutes",time);
	system ("pause");
	return (0);
}
/*We cab use %e placeholder which show the output number in the scientific format.
rather than we can use the %g placeholder which show the output number either normar
or scientific it depends on the output number which is shorter.*/