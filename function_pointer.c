#include<stdio.h>
void display()
{
    printf("This line are in the display function");

}
int main()
{
    void (*dis)();
    dis = display;
    (*dis)();
    printf("%u",dis);
    return 0;
}  