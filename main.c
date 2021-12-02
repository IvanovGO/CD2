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


pr_list * pl = find_pr(f_in,pin);

puts("convolutions");
convolutions(pl,pin);

puts("print_hysto(f_in);");
print_hysto(f_in);

puts("pr_list_list(pl);");
pr_list_list(pl);



}


}
