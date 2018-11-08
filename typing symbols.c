#include<stdio.h>
main()
{
	printf("'\x9c'");
}
/*Suppose that you want to use the British pound symbol, £,
in your program. That character’s secret code number is 156.
Look it up in Appendix B. You can see that the hexadecimal value is 9C.
(Hex numbers contain letters.) So you specify the
following escape sequence in your program:
			‘\x9C’			*/
