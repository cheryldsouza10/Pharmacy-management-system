#include <stdio.h>
#include <stdlib.h>
float add(float,float);
float sub(float,float);
float mult(float,float);
float divi(float,float);

int main()
{
    float a,b,ca=0,cs=0,cm=0,cd=0;
    int ch=0;
    float (*p)(float,float);
    printf("Enter two numbers:");
    scanf("%f%f",&a,&b);
    for(;;)
    {
        printf("Operations:\n");
        printf("1.Addition\n");
        printf("2.Subtraction\n");
        printf("3.Multiplication\n");
        printf("4.Division\n");
        printf("5.Exit\n");
        printf("Enter the operation number:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: p=add;
                    ca=(*p)(a,b);
                    printf("Sum of %f and %f = %f\n",a,b,ca);
                    break;

            case 2: p=sub;
                    cs=(*p)(a,b);
                    printf("Difference of %f and %f = %f\n",a,b,cs);
                    break;

            case 3: p=mult;
                    cm=(*p)(a,b);
                    printf("Product of %f and %f = %f\n",a,b,cm);
                    break;

            case 4: p=divi;
                    if(b==0)
                        printf("Division is not possible\n");
                    else
                    {
                        cd=(*p)(a,b);
                        printf("Quotient of %f and %f = %f\n",a,b,cd);
                    }
                    break;

            case 5: exit(0);

            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

float add(float a, float b)
{
    return(a+b);
}

float sub(float a,float b)
{
    return(a-b);
}

float mult(float a, float b)
{
    return(a*b);
}

float divi(float a,float b)
{
    return(a/b);
}
