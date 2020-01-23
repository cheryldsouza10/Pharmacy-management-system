#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
    int nos;
    char meds[4][20];
}Med;

typedef struct
{
    int id;
    char name[20];
    char add[30];
    long int phno;
}user;

typedef struct
{
    char med[20];
    float cost;
    int qty;
}stk;

user users[5]={{0,"Abhishek","RC NAGAR",123456789},{1,"Abhi","Tilakwadi",9837583993}};
Med medi[3]={{0,"Crocin","flexon"},{1,"salibid"}};

stk stock[4]={ {"crocin",2.5,10},
              {"salibid",5,15},
              {"folvite",2,3},
              {"flexon",3,5} };

float bill=0;
int counts;
float cart[4][3]={0};
FILE *fptr;

void search(long int);
int guest();
void billing();
int guest1();
void billing1(int);
void new_acc();
void info();
void update();


int main()
{
    int ch,d,i,fl=0,f=0;
    char neq;
    long int ph;
    char med[10];

                    fptr = fopen("count.txt", "r");
                    if (fptr == NULL)
                    {
                        printf("Cannot open file \n");
                        exit(0);
                    }
                    // Read contents from file

                    fscanf(fptr,"%d", &counts);

                    fclose(fptr);
    printf("\n\t\t\t\t\t\tPHARMACY MANAGEMENT ");
    while(1)
    {

    printf("\n***********************************************************************************************************************");
    printf("\n1.PHONE NUMBER\n2.MEDICINE\n3.GUEST\n4.ACCOUNT CREATION\n5.INFO\n6.UPDATE STOCK\n7.EXIT\n");
    printf("Enter the choice: ");
    scanf("%d", &ch);
    neq=ch+'0';
    if(isdigit(neq)==0)
    {
        printf("Invalid choice!\n");
        break;
    }
    switch(ch)
    {
        case 1: printf("Enter the phone number:");
                scanf("%ld", &ph);
                for(i=0;i<3;i++)
                {
                if(ph==users[i].phno)
                    f=1;
                }
                if(f==1)
                    search(ph);
                else
                    printf("User doesn't exist!!\n");
                break;

        case 2: printf("Enter the medicine: ");
                scanf("%s", med);
                //just checks the medicine in the stock
                for(i=0;i<4;i++)
                {
                    if(strcmp(med,stock[i].med)==0)
                    {
                            printf("%d quantity of %s exists\n",stock[i].qty,stock[i].med);
                            if(stock[i].qty<1)
                                printf("Out of stock");
                            fl=1;
                            break;
                    }
                }

                if(fl==0)
                printf("Invalid medicine name\n");

                break;
        case 3: for(i=0;i<4;i++)
                    {
                        cart[i][0]=i;
                        cart[i][1]=0;
                        cart[i][2]=0;
                    }
                guest();
                break;
        case 4: new_acc();
                break;
        case 5:info();
                break;
        case 6:update();
                break;
        case 7:exit(0);

        default : printf("invalid input\n");

    }
    }
    return 0;
}


void search(long int ph)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        if(ph==users[i].phno)
        {
        printf("Name:%s\n",users[i].name);
        printf("Address:%s\n",users[i].add);
        printf("Phone number:%ld\n",users[i].phno);
        printf("Medicines:\n");
        for(j=0;j<3;j++)
        printf("%s\n",medi[i].meds[j]);
        counts++;
                    fptr = fopen("count.txt", "w");
                    if(fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr,"%d\n", counts);
                    fclose(fptr);
        break;
        }
    }
    guest1();
}


void new_acc()
{
    char st[20],a[20];
    long int ph;
    users[2].id=2;
    printf("Name:");
    scanf("%s",st );
    printf("Address:");
    scanf("%s",a );
    printf("Phone number:");
    scanf("%ld",&ph );
    strcpy(users[2].name,st);
    strcpy(users[2].add,a);
    users[2].phno=ph;
    strcpy(medi[2].meds,"NO MEDICINES YET");
    fptr = fopen("newuser.txt", "a+");
    if(fptr == NULL)
    {
    printf("Error!");
    exit(1);
    }
    fprintf(fptr,"    Name:%s  Address:%s    Phone Number:%ld\n", st,a,ph);
    fclose(fptr);
}

int guest()
{
    long int phno;
    char name[20],m[10];
    int i,q,flag=0,ch;
    float bil;
    FILE *fptr;
    bill=0;
    printf("Enter customer name:");
    scanf("%s",name);
    printf("Enter phone number:");
    scanf("%d",&phno);

    fptr = fopen("program.txt", "a+");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr,"\nName:%s  Phone Number:%d", name,phno);
    fclose(fptr);

    for(;;)
    {
        printf("\n1.Buy \n2.Bill \n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the medicine:");
                    scanf("%s",m);
                    printf("Enter the quantity:");
                    scanf("%d",&q);

                    fptr = fopen("program.txt", "a+");
                    if(fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr,"    Medicine:%s  Quantity:%d\n", m,q);
                    fclose(fptr);

                    for(i=0;i<4;i++)
                    {
                        if(strcmp(m,stock[i].med)==0)
                        {
                            if(q>stock[i].qty)
                                printf("Out of stock\n");
                            else
                                flag=1;
                        }
                        if(flag==1)
                        {
                            cart[i][0]=i;
                            cart[i][1]=q;
                            cart[i][2]=stock[i].cost;
                            stock[i].qty-=q;
                            flag=0;
                            break;
                        }
                    }
                    break;
            case 2: billing();
                    break;
            default:return;
        }
    }

return 1;
}

void billing()
{
    int i,j,x;
    char m[10];
    FILE *fptr;
    bill=0;
    printf("Bill:\n");
    printf("Medicine \t Quantity \n ");
        //x=cart[i][0];
        for(i=0;i<4;i++)
        {
            strcpy(m,stock[i].med);
             bill=bill+cart[i][1] *cart[i][2];
             if(cart[i][1]>0)
                printf("%s \t %f \n",m,cart[i][1]);
        }


    printf("\nBill=%f",bill);

    fptr = fopen("program.txt", "a+");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr,"Bill=%f\n\n", bill);
    fclose(fptr);

}
int guest1()
{
    char m[10];
    int i,q,flag=0,ch;
    float bil;
    int num;

   if ((fptr = fopen("count.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d", &num);


   fclose(fptr);


    bill=0;
    for(;;)
    {
        printf("\n1.Buy \n2.Bill \n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the medicine:");
                    scanf("%s",m);
                    printf("Enter the quantity:");
                    scanf("%d",&q);

                     fptr = fopen("user.txt", "a+");
                    if(fptr == NULL)
                    {
                        printf("Error!");
                        exit(1);
                    }
                    fprintf(fptr,"    Medicine:%s  Quantity:%d\n", m,q);
                    fclose(fptr);

                    for(i=0;i<4;i++)
                    {
                        if(strcmp(m,stock[i].med)==0)
                        {
                            if(q>stock[i].qty)
                                printf("Out of stock\n");
                            else
                                flag=1;
                        }
                        if(flag==1)
                        {
                            cart[i][0]=i;
                            cart[i][1]=q;
                            cart[i][2]=stock[i].cost;
                            stock[i].qty-=q;
                            flag=0;
                            break;
                        }
                    }
                    break;
            case 2: if(num>=30)num=30;
                    billing1(num);
                    break;
            default:return;
        }
    }
    return 1;
}

void billing1(int num)
{
    int i,j,x;
    char m[10];
    float discount=0.0;

    printf("Your number of visits: %d\n",num);
    bill=0.0;

    printf("Bill:\n");
    printf("Medicine \t Quantity \n ");
        //x=cart[i][0];
        for(i=0;i<4;i++)
        {
            strcpy(m,stock[i].med);
             discount=(float)((num*cart[i][1] *cart[i][2])/100);
             bill=bill+cart[i][1] *cart[i][2]- discount;
             if(cart[i][1]>0)
                printf("%s\t\t%f\n",m,cart[i][1]);
        }


    printf("\nBill=%f\n",bill);
    printf("Discount=%f",discount);


}

void info()
{
    int ch,i;
    char c;
    printf("\n1.Display stock\n2.Display users\n3.Display Guest users\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nSTOCK:\n");
                printf("MEDICINE\t\tQUANTITY\n");
                for(i=0;i<4;i++)
                printf("%s\t\t\t%d\n",stock[i].med,stock[i].qty);
                printf("\n");
                break;
        case 2:fptr = fopen("newuser.txt", "r");
                    if (fptr == NULL)
                    {
                        printf("Cannot open file \n");
                        exit(0);
                    }

                    // Read contents from file
                    c = fgetc(fptr);
                    while (c != EOF)
                    {
                        printf ("%c", c);
                        c = fgetc(fptr);
                    }

                    fclose(fptr);
                    break;

        case 3:fptr = fopen("program.txt", "r");
                    if (fptr == NULL)
                    {
                        printf("Cannot open file \n");
                        exit(0);
                    }
                    // Read contents from file
                    c = fgetc(fptr);
                    while (c != EOF)
                    {
                        printf ("%c", c);
                        c = fgetc(fptr);
                    }

                    fclose(fptr);
                    break;
        case 4:break;
        default:printf("Invalid choice");
    }
}


void update()
{
    int i,qu,f=0;
    char s[50];

        printf("\nSTOCK:\n");
        printf("MEDICINE\t\tQUANTITY\n");
        for(i=0;i<4;i++)
        printf("%s\t\t\t%d\n",stock[i].med,stock[i].qty);
        printf("\n");
        printf("Enter the medicine:");
        scanf("%s", s);
        for(i=0;i<4;i++)
        {
         if((strcmp(s,stock[i].med))==0)
        {
            printf("Enter the quantity:");
            scanf("%d",&qu);
            stock[i].qty+=qu;
            f=1;
            break;
        }
        }
        if(f==0)
        {
            printf("Medicine doesn't exist\n");
        }
        else
        {
            printf("Addition successful\n");
        }
        fptr = fopen("stock.txt", "w");
    if(fptr == NULL)
    {
    printf("Error!");
    exit(1);
    }
    for(i=0;i<4;i++)
    fprintf(fptr,"    Medicine:%s   Price:%f  Quantity:%d\n", stock[i].med,stock[i].cost,stock[i].qty);
    fclose(fptr);
}
