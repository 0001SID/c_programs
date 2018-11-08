#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
int main()
{
    int a,b;
    gotoxy( 5,10 );
    scanf("%d",&a);
    printf("%d",a);
    gotoxy(50,10);
    scanf("%d",&b);
    printf("%d",b);
    return 0;
}