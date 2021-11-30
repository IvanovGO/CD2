#include "prepare.h"
#include "pair.h"

#include <stdio.h>
#include <time.h>


int main(int argc, char * argv[]){

switch (argc){
	case 1: return -1;
	case 4:
	printf("Arg 3 received %s\n",argv[3]);
	case 3:
	printf("Arg 2 received %s\n",argv[2]);
	case 2: 
	printf("Arg 1 received %s\n",argv[1]);
	break;
	default:
	printf("Too many arguments\n");
}


if (argc==2){
int * pin = Load_File (argv[1]);
//Print_Pre(pin);puts("");

dlist * f_in = alter_hysto(pin);
print_hysto(f_in);

pr_list * pl = pair(f_in,pin);

pr_list_list(pl);

}

/*


 srand(time(NULL));
 
 FILE * rdata;
 
 long flen=500*1024*1024/2;
 int rd;
 rdata = fopen(argv[1],"w");
 if (rdata==NULL) {
 printf ("Can`t create file%s\n",argv[1]);
 return -2;}
 
 while (flen){
  
  if (rand()%5==1) {rd=rand()%100;} else {rd=rand()%2;}
  fprintf(rdata,"%2i\n",rd);

  flen--;
   
 // if (flen%0x1fffffff) printf("%i bytes left\n",flen) ;
  }
  fclose(rdata);
 }//create 
 
 if (argc==3){
 
 
 
 }//conv

	if (argc==4){
	
	 FILE * indata;
	 FILE * outdata;
	 
	 outdata = fopen(argv[2],"w");
         indata = fopen(argv[1],"r");
         
	 if (indata==NULL) {
 	 printf ("Can`t open file%s\n",argv[1]);
	 return -3;}
	 
	 char rd[3];
         unsigned int rid;
         int byisiz=sizeof(rid)*8;
         int i=0;
         
  while (fgets(rd,3,indata)!=NULL){
        rid=atoi(rd);
	if (rid<100) {fprintf(outdata,"%i\n",rid);}else{
	while (i<byisiz)
	{
	if ((rid & (1<<i))==0) {fprintf(outdata," 1\n");} else
				{fprintf(outdata," 0\n");}
	i++;
	}
	
	i=0;}	
	
	}}//deconv

*/
}
