//qr.c

#include"inv.h"

void query_part()
{
    FILE *infile;
    int n;
    inventory npart;
    infile=fopen("part.dat","r");
    printf("Enter the part number to display : ");
    scanf("%d",&n);
    while(fread(&npart,sizeof(npart),1,infile) && npart.part_no !=n);
    if(feof(infile)) printf("part not found\n");
    else
        printf("Part No= %d, Name = %s, Stock = %d ,Price= %.2f\n",npart.part_no,npart.name,npart.stock,npart.price);
    fclose(infile);
}