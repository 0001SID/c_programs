void clear()
{
    fflush(stdin);
}
int gfloat()
{
    float p;
    int value = 1;
    while (value == 1) //Loop for checking numeric or alphabetic input
    {
        clear();
        scanf("%f", &p);
        if (p)
        {
            return p;
            break;
        }
        else
        {
            printf("Please enter a numeric value\n");
        }
    }
}
void si()
{
    float p, r, t, smi;
    printf("\nEnter the total amount\n");
    p = gfloat();
    printf("Enter the rate of interest\n");
    r = gfloat();
    printf("Enter the total time in year\n");
    t = gfloat();
    smi = (p * r * t) / 100;
    printf("simple interest: %.2f\n", smi);
    printf("Amount with interest: %.2f\n\n", smi + p);
}
void ci()
{
    float cmi, p, r, t, n;
    printf("\nEnter the total amount\n");
    p = gfloat();
    printf("Enter the rate of interest\n");
    r = gfloat();
    printf("Enter the total time in year\n");
    t = gfloat();
    printf("How many times interest compounded per year\n");
    n = gfloat();
    cmi = p * pow((1 + r / (100 * n)), n * t);
    printf("Compounded interest: %.2f\n", cmi - p);
    printf("Amount with interest: %.2f\n\n", cmi);
}