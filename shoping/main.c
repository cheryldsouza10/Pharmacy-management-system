#include <stdio.h>
#include <stdlib.h>
//program to implement shopping cart
int stock[5][3]={
                 {100,5,20},
                 {101,35,100},
                 {102,5,20},
                 {103,10,20},
                 {104,5,100}
                };
int cart[5][3];

int main()
{
    int choice;
    printf("The available items are:\nProduct_id   product_name\n100   Book\n101   Pencil\n102   Scale\n103  Eraser\n104  pen");
     do
      {
        printf("\n**MENU**\n1-add item to the cart\n2-delete2 item from cart\n3-Display stock\n4-display cart\n5-Bill\n6-Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
         {
           case 1:add();
                  break;
           case 2:delete2();
                  break;
           case 3:display_stock();
                  break;
           case 4:display_cart();
                  break;
           case 5:printf("Total bill=%d",bill());
                  break;
           case 6:exit(0);
           default:printf("INVALID CHOICE!!!!");
         }
      }while(choice!=6);
}
      void add()
      {
        int id,i,qty;
        printf("Enter product id and quantity:");
        scanf("%d%d",&id,&qty);
        i=id-100;
        if(qty<=stock[i][2])
        {
         stock[i][2]=stock[i][2]-qty;
         cart[i][2]=cart[i][1]+qty;
         cart[i][1]+=qty*stock[i][1];
        }
        else
        {
          printf("The addition can not be performed due to insufficient item!!");
        }
      }

     void delete2()
     {
        int id,i,qty;
        printf("Enter product id and quantity:");
        scanf("%d%d",&id,&qty);
        i=id-100;
         if(qty<=cart[i][1])
          {
            stock[i][2]+=qty;
            cart[i][2]-=qty;
            cart[i][1]-=qty*stock[i][1];
          }
        else
         {
           printf("The deletion can not performed bcoz insufficient item!!");
         }
     }

     void display_stock()
     {
       int i,j;
       printf("Id\t cost\t Quantity\n");
       for(i=0;i<5;i++)
       {
         printf("\n");
         {
           for(j=0;j<3;j++)
           {
             printf("%d\t",stock[i][j]);
           }
         }
       }
     }

     void display_cart()
     {
        int i;
        printf("\t Id\t\t cost \t\t quantity \n");
        for(i=0;i<5;i++)
        {
         if(cart[i]!=0)
          {
           printf("\t %d\t\t%d\t\t\t%d\n",stock[i][0],cart[i][1],cart[i][2]);
          }
         }
        }

     int bill()
     {
      int i,bill=0;
      for(i=0;i<=5;i++)
      {
       bill+=cart[i][2];
      }
       return bill;
     }
