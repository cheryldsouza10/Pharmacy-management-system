//tra.c

#include "inv.h"

void transaction()
{
    FILE *infile1;
    FILE *infile2;
    long inv_size,trans_size;
    char c;
    inventory npart;
    transact t;
    inv_size=sizeof(npart);
    trans_size=sizeof(t);
    infile1=fopen("Part.dat","r+");
    infile2=fopen("Trans.dat","a");
    printf("Enter the part number of transaction:");
    scanf("%d",&t.part_no);
    printf("Enter s for sale or m for manufacture:");
    fflush(stdin);
    scanf("%c",&t.type);
    c=t.type;
    printf("Enter the quantity of transaction:");
    scanf("%d",&t.quantity);
    while(fread(&npart,inv_size,1,infile1) && npart.part_no !=t.part_no);
    if (feof(infile1))
    {
        printf("Part Not found");
    }
    else
    {
        if (c=='m' || c=='M')
            npart.stock = npart.stock + t.quantity;
        else if (c=='s' || c=='S')
            npart.stock = npart.stock - t.quantity;
        fseek(infile1, -inv_size, SEEK_CUR);
        fwrite (&npart, sizeof(npart), 1, infile1);
        fwrite (&t, trans_size, 1, infile2);
    }
    fclose(infile1);
    fclose(infile2);
}