#include "prepare.h"

long MemAllocated;


int fsize(char file[40])
{
    FILE * f = fopen(file, "r");
    fseek(f, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(f);
    fclose(f); 
    return len;
}


void Print_Pre(int * p){
int x=0;
for (long i=0;i<MemAllocated;i++) {
printf("%2i ",p[i]);
if (x==0x1f) { printf("\n");x=0;}
x++;
}}

int * Load_File (char fname[80]){
 
 FILE * indata;
 int * outdata = NULL;
 
 indata = fopen(fname,"r");
 
 
 if (indata==NULL) {
 printf ("Can`t open file%s\n",fname);
 return NULL;}

 outdata = (int*)malloc(sizeof(int)*fsize(fname));
 
 char rd[3];
 int rid;
 long int i=0;
 while (fgets(rd,3,indata)!=NULL){
  rid=atoi(rd);
  outdata[i]=rid;
  i++;
 }
MemAllocated=i;

   fclose(indata);

return outdata;
}


