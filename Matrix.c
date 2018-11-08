#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void operation(int operator)
{
    int row[2], coloumn[2];
    for (int i = 0; i < 2; i++)
    {
        printf("Enter the number of row of matrix %d\n", i + 1);
        scanf("%d", &row[i]);
        printf("Enter the number of coloumn of matrix %d\n", i + 1);
        scanf("%d", &coloumn[i]);
    }
    if (operator== 1 || operator== 2)
    {
        if (coloumn[0] != coloumn[1] && row[0] != row[1])
        {
            if (operator== 1)
            {
                printf("Summation is not possible in this order\n");
            }
            else
            {
                printf("Subtraction is not possible in this order\n");
            }
            exit(0);
        }
    }
    else
    {
        if (coloumn[0] != row[1])
        {
            printf("Multiplication is not possible in this order\n");
            exit(0);
        }
    }
    float a[row[0]][coloumn[0]], b[row[0]][coloumn[1]], result[row[0]][coloumn[1]],temp;
    printf("\nTaking data for matrix 1 (A)\n\n");
    for (int i = 0; i < row[0]; i++)
    {
        for (int j = 0; j < coloumn[0]; j++)
        {
            printf("Enter the value of A%d%d element : ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nTaking data for matrix 2 (B)\n\n");
    for (int i = 0; i < row[1]; i++)
    {
        for (int j = 0; j < coloumn[1]; j++)
        {
            printf("Enter the value of B%d%d element : ", i + 1, j + 1);
            scanf("%f", &b[i][j]);
        }
    }
    if (operator== 1)
        printf("The resultant summation is :\n\n");
    else if (operator == 2)
        printf("The resultant subtraction is :\n\n");
    else
        printf("The resultant multiplication is :\n\n");
    if (operator== 2 || operator== 1)
    {
        for (int i = 0; i < row[0]; i++)
        {
            for (int j = 0; j < coloumn[0]; j++)
            {
                if (operator== 1)
                {
                    result[i][j] = a[i][j] + b[i][j];
                    printf("%.2f\t", result[i][j]);
                }
                else
                {
                    result[i][j] = a[i][j] - b[i][j];
                    printf("%.2f\t", result[i][j]);
                }
            }
            printf("\n\n");
        }
    }
    else
    {
        for (int i = 0; i < row[0]; i++)
        {
            for (int j = 0; j < coloumn[1]; j++)
            {
                temp = 0;
                for (int k = 0; k < coloumn[1]; k++)
                {
                    temp += a[i][k] * b[k][j];
                }
                result[i][j] = temp;
                printf("%.2f\t", result[i][j]);
            }
            printf("\n\n");
        }
    }
}

int main()
{
    printf("\t\t\tMATRIX CALCULATOR");
    while (1)
    {
        printf("\n\nWhat you want to do\n");
        printf("1.Summation\n2.Subtraction\n3.Multiplication\n");
        printf("\nEnter your choice : ");
        int res;
        scanf("%d", &res);
        if (res == 1)
        {
            operation(1);
        }
        else if (res == 2)
        {
            operation(2);
        }
        else if (res == 3)
        {
            operation(3);
        }
        else
        {
            printf("You have entered a wrong keyword Please enter the correct one\n");
            continue;
        }
        char again, clr;
    rep:
        scanf("%c", &clr);
        printf("Do you want to calculate again?(y/n)\n");
        scanf("%c", &again);
        if (again == 'y')
        {
            continue;
        }
        if (again == 'n')
        {
            break;
        }
        else
        {
            printf("You have entered a wrong keyword Please type again\n");
            goto rep;
        }
    }
    return 0;
}