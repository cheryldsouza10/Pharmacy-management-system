// cr.c

#include"inv.h"
void read_part()
{
    FILE *outfile;
    inventory input;
    char c='y';
    //open accounts file for writing
    outfile=fopen("part.dat","a+");
    if(outfile==NULL){
    fprintf(stderr,"\nError opening accounts.dat\n");
    exit(1);
    }

    while(c=='y' || c=='Y')
    {
        printf("\nPart Number : ");
        scanf("%d",&input.part_no);
        printf("\nPart Name : ");
        scanf("%s",input.name);
        printf("\nStock : ");
        scanf("%d",&input.stock);
        printf("\nPrice : ");
        scanf("%f",&input.price);
        fwrite(&input,sizeof(input),1,outfile);
        printf("Do you want to continue(y/n) : ");
        getchar();
        scanf("%c",&c);


    }
    fclose(outfile);

}
