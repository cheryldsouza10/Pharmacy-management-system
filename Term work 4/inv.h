//header inv.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[30];
    int part_no;
    int stock;
    float price;
}inventory;

typedef struct
{
    int part_no;
    char type;
    int quantity;
}transact;

extern void read_part();
extern void delete_part();
extern void print_part();
extern void query_part();
extern void transaction();
