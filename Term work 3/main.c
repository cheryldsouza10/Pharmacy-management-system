#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //definition of boolean variable

typedef struct
{
    int acc_no;
    char name[20];
    float balance;
}account;

account acc[25];

int cur_acc=100;

void newacount();
void deposit();
void withdraw();
void balance_enq();
void display();

int main()
{
    int opt=0;
    do
    {
        printf("\n=============================\n");
        printf("\nMenu:\n");
        printf(" 1.New account\n 2.Deposit\n 3.Withdrawal\n 4.Balance enquiry\n 5.Display\n 6.Quit \n");
        printf("Enter your option:");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1: newaccount();
                    break;
            case 2: deposit();
                    break;
            case 3: withdraw();
                    break;
            case 4: balance_enq();
                    break;
            case 5: display();
                    break;
            case 6: exit (0);

            default: printf("Invalid choice\n");
        }
    }while(opt!=6);
    return 0;
} //end of main

void newaccount()
{
    int i;
    char name[20];
    float amt;

    printf("\n========================================\n");
    printf("Enter account holder name:");
    scanf("%s",name);
    printf("Enter initial amount:");
    scanf("%f",&amt);
    while(amt<500)
    {
        printf("Initial amount is insufficient");
        printf("Re-enter the initial amount");
        scanf("%f",&amt);
    }
    //index of the array where to add record
    i=cur_acc-100;
    //add account details
    acc[i].acc_no=cur_acc;
    strcpy(acc[i].name,name);
    acc[i].balance=amt;

    cur_acc++;  //next account
}  //end of new account


void deposit()
{
    float damt;
    int d,i,j;
    bool found=0;

    printf("\nEnter account number:");
    scanf("%d",&d);
    printf("\nEnter amount to deposit:");
    scanf("%f",&damt);

    //search for account
    i=d-100;

    for(j=0;j<=i;j++)
    {
        if(acc[j].acc_no==d)   //match found
        {
            acc[j].balance+=damt;
            printf("\nAmount is successfully deposited");
            found=1;
            break;
        }   //end if if
    }  //end of for
    if(found==0)   //match not found
        printf("\nAccount is not found");
}  //end of deposit

void withdraw()
{
    int w,i,j;
    float wamt;
    bool found=0;
    printf("\nEnter account number to withdraw from:");
    scanf("%d",&w);
    printf("\nEnter amount to be withdrawn:");
    scanf("%f",&wamt);

    i=w-100;

    //search account
    for(j=0;j<=i;j++)
    {
        if(acc[j].acc_no==w)  //match found
        {
            found=1;//check if withdrawal leaves a minimum balance of 500

            if((acc[j].balance-wamt)>=500)
            {
                acc[j].balance-=wamt;
                break;
            }
            else
            {
                printf("\n Insufficient funds. Cannot withdraw.");
                break;
            }
        }  //end of if
    }   //end of for

    if(found==0)
        printf(" Account not found");
}

void balance_enq()
{
    int bacc,i,j;
    bool found=0;
    printf("Enter account number:");
    scanf("%d",&bacc);

    i=bacc-100;

    for(j=0;j<=i;j++)
    {
        if(acc[j].acc_no==bacc)   //match found
        {
            //check if withdrawal leaves a minimum balance of 500
            found=1;
            printf("\nBalance is:%f",acc[i].balance);
        }  //end of if
    }   //end of for
    if(found==0)
        printf("Account not found");
}  //end of balance enquiry

void display()
{
    int i,j;
    i=cur_acc-100;
    printf("\n========================================\n");
    printf("Account#\t Name\t\t Balance\n");
    printf("\n===========================================================\n");

    for(j=0;j<i;j++)
        printf("%d\t %s\t\t %f\t\n",acc[j].acc_no,acc[j].name,acc[j].balance);
}

