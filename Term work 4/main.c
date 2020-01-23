//main.c

#include "inv.h"

int main(int agrc,char *agrv[])
{
    int opt=0;
    do
    {
        printf("    Menu\n");
        printf("1...Add an item\n");
        printf("2...Delete an item\n");
        printf("3...Display list of all the parts\n");
        printf("4...Query a particular part\n");
        printf("5...Make transactions\n");
        printf("6...Exit\n");
        printf("please Enter your option :");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1 :read_part();break;
            case 2 :delete_part();break;
            case 3 :print_part();break;
            case 4 :query_part();break;
            case 5 :transaction();break;
            case 6 :exit(0);
            default :
                {
                    printf("invalid input\n");
                    printf("press any key to continue\n");
                    fflush(stdin);
                    getc(stdin);
                }
        }
    }while(opt!=6);
    return 0;
}