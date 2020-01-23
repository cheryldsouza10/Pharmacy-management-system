//pr.c

#include"inv.h"
void print_part()
{
    FILE *infile;
    inventory npart;
    infile=fopen("part.dat","r");
    while(fread(&npart,sizeof(npart),1,infile))
    {
        printf("Part No= %d, Name = %s, Stock = %d ,Price= %.2f\n",npart.part_no,npart.name,npart.stock,npart.price);
    }
    fclose(infile);
}