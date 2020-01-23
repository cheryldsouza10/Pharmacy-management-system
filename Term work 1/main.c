#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char item_id[10];
    float price;
    int qty;
}item;                 //can be used as data type

void add_item(item*, item*);
void delete1(item*, item*);
void display(item*);
void billing(item*);

float bill=0;

int main()
{
    item stock[5]={{"A001",10.25,10},              //each member is a structure
                    {"A002",25.00,5},
                    {"A003",17.75,21},
                    {"A004",15.50,50},
                    {"A005",12.75,5}};

    item cart[5]={{"A001",0.0,0},              //each member is a structure
                    {"A002",0.00,0},
                    {"A003",0.0,0},
                    {"A004",0.0,0},
                    {"A005",0.0,0}};
    int ch;

    printf("Item ID: A001->Books \t A002->Pencils \t A003->Erasers \t A004->Papers \t A005->Crayons \n");

    for(;;)
    {
        printf("\n Menu: \n 1.Add item \t 2.Delete \t 3.Display \t 4.Billing information \t 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: add_item(stock, cart);             //pass by reference
                    break;

            case 2: delete1(stock, cart);
                    break;

            case 3: display(cart);
                    break;

            case 4: billing(cart);
                    break;

            case 5:exit(0);

            default: printf("Invalid choice");
        }
    }
}

void add_item(item *s, item *c)
{
    char id[5];
    int Q,i,iflag=0;
    printf("Enter item ID to be added:");
    scanf("%s",id);
    printf("Enter the quantity:");
    scanf("%d",&Q);

    for(i=0;i<5;i++)
    {
        if(strcmp(id,s[i].item_id)==0)
        {
            if(Q<=s[i].qty)
            {
                iflag=1;
                c[i].qty=c[i].qty+Q;
                s[i].qty=s[i].qty-Q;
                c[i].price=s[i].price;
                printf("Item added to the cart successfully\n");
                bill+=c[i].price*Q;
            }
            else
            {
                printf("Insufficient quantity \n");
                break;
            }
        }
    }
    if(iflag==0)
      printf("Addition unsuccessful \n");
}

void delete1(item *s, item *c)
{
    char id[5];
    int Q,i,iflag=0;
    printf("Enter item ID to be deleted:");
    scanf("%s",id);
    printf("Enter the quantity:");
    scanf("%d",&Q);
     for(i=0;i<5;i++)
    {
        if(strcmpi(id,c[i].item_id)==1)
        {
            if(Q<=c[i].qty)
            {
                iflag=1;
                c[i].qty=c[i].qty-Q;
                s[i].qty=s[i].qty+Q;
                bill-=(s[i].price*Q);
                printf("Item deleted from the cart successfully \n");
            }
        }
    }
    if(iflag==0)
      printf("Deletion unsuccessful\n");
}

void display(item *c)
{
    int i;
    printf("Items in the cart are:\n");
    printf("ID  \t Quantity\n");
    for(i=0;i<5;i++)
    {
        if(c[i].qty>0)
        printf("%s \t %d \n",c[i].item_id,c[i].qty);
    }
}

void billing(item *c)
{
    int i;
    float b[5],total=0;
    printf("Billing information:\n");
    printf("ID \t Quantity \t Price \t Cost \n");
    for(i=0;i<5;i++)
    {
        if(c[i].qty>0)
        {
            b[i]=c[i].price*c[i].qty;
            printf("%s \t %d \t %f \t %f \n",c[i].item_id,c[i].qty,c[i].price,b[i]);
            //total=total+b[i];
        }
    }
    printf("Bill=%f \n",bill);
}
