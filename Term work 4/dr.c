//dr.c

#include"inv.h"

void delete_part()
{
    FILE *infile,*tmpfile;
    int n,found=0;
    inventory npart;
    infile=fopen("part.dat","r");
    tmpfile=fopen("parttemp.dat","w");
    printf("Enter the part no to delete : ");
    scanf("%d",&n);
    while(fread(&npart,sizeof(npart),1,infile))
          {
              if(n!=npart.part_no)
                fwrite(&npart,sizeof(npart),1,tmpfile);
              else
                found=1;
          }
     fclose(infile);
     fclose(tmpfile);
     if(found=1)
     {
         remove("part.dat");
         rename("parttemp.dat","part.dat");
         printf("element successfully deleted\n");
     }
     else
     {
        printf("element not found\n");
        remove("parttemp.dat");
     }

}