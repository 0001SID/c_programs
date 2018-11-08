#include<stdio.h>
/*int main()
{
    int a;
    int *b = &a;
    a = 4;
    //*b = &a;
    printf("Value of a is %d\n",a);
    printf("value of b is %u\n",b);
    printf("value of *b is %d\n ",*b);
    printf("value of &a is %u\n",&a);
    printf("Value of *&b is %u\n",*&b);
    printf("Value of &b is %d",&b);
    return 0;
}*/
void swap(int *a,int *b)
{
    int t ;
    //int *c,*d;
    t = *a;
    *a = *b;
    *b = t;
    //c =a;
    //d =b;
    printf("This is inside the swap function\n");
    printf("The first number is %d\n",*a);
    printf("The second number is %d\n",*b);
}
int main()
{
    int num1,num2;
    printf("Enter number one ");
    scanf("%d",&num1);
    printf("Enter the second number ");
    scanf("%d",&num2);
    swap(&num1,&num2);
    printf("On the outside of function\n");
    printf("number 1 = %d\n",num1);
    printf("number 2 is %d\n",num2);
    return 0;
}