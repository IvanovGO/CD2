#include "prepare.h"
#include "conv.h"


//struct hysto {int num; long count; char * next; };


bool is_there(int n){

struct hysto * tp=NULL;

while (tp->next!=NULL){
if (tp->num==n) return true;
tp=tp->next;
}
return false;
}

struct hysto * alter_hysto(int * p){

struct hysto * tp=NULL;

for (long i=0;i<MemAllocated;i++){

if (!is_there(p[i])) {}

}



return NULL;
}

int * conv(int * p){


return NULL;
}



