#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    char res = "true";
    while (res == "true")
    {
        int close,amt;
        printf("What is the closing price of vakrangee today?\n");
        gets(close);
        printf("Enter the amount");
        gets(amt);
        if (close == 'exit')
        {
            break;
        }
        else if(close != 'exit')
        {
            close = (float)close;
            float low = close - (close*4.9)/100;
            float high = close + (close*4.97)/100;
            float change = (close*4.97)/100;
            printf("Tommorrow low will be %.2f\nand high will be %.2f\nand change is %.2f\n\n",low,high,change);
            float bsl =low + 0.1;
            float amount = amt - ((amt/bsl)*change);
            int quantity = (amount/bsl);
            float ssl = (close-0.5);
            printf("Put Buy stop loss at: %.2f",bsl);
            printf("put sell stopp loss at: %.2f",ssl);
            printf("Quantity You can buy: %d",quantity);
            continue;
        }
    }
}