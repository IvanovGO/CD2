#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
//#include <stdbool.h>

/*
typedef struct pr_node {
struct pr_node * prev;
struct pr_list * list;
int num;
unsigned long count;
struct pr_node * next; } pr_node;   
	        

typedef struct pr_list {
struct pr_node * head;
struct pr_node * tail;
long count;          } pr_list;
*/

/*---------------------in CD2------------------------*/

pr_list * pr_list_init(){//создание двусвязанного списка
pr_list * p = (pr_list *)malloc(sizeof(pr_list)); 
if (!p) return NULL;
p->count=0;
p->head=NULL;
p->tail=NULL;
return p;
}


bool pr_list_is_empty(pr_list * list){
if (!list->head&&!list->tail) return true;
return false;
}

bool pr_list_is_trivial(pr_list * list){
if (list->head==list->tail) return true;
return false;
}



int pr_list_add(pr_list*list,pr_node * node){//добавление узла в конец
//puts("pr_list add");
if (pr_list_is_empty(list)){//puts("empty");
list->head=node;
list->tail=node;
//puts("-----------add in empty---------");
}  else 
{
node->prev=list->head;
node->prev->next=node;
list->head=node;
//puts("add in not empty");
}
list->count++;
node->list=list;
return list->count;
}

int pr_list_ins(pr_list * list, pr_node * node){ //вставка узла в начало
if (pr_list_is_empty(list)){//puts("empty");
list->head=node;
list->tail=node;
} else {node->next=list->tail;
node->next->prev=node;
list->tail=node;}
list->count++;
node->list=list;
return list->count;
}


unsigned long pr_list_list(pr_list * list){//вывод узлов
if (!list->tail) return -1;
unsigned long c=0;
pr_node * p = list->tail;
while(p) {c++;
	pr_node_print(p);
	p=p->next;}
return c;}


/* pr_node ---  PRINT----*/

int pr_node_print(pr_node * node){


printf("n1-%i n2-%i start-%li end-%li\n", node->n1,node->n2,node->start,node->end);

return 0;
}



pr_node * pr_list_remove(pr_node * node){
if (!node) return NULL;
//puts("pr_list_remove");
pr_list * list = node->list;
//printf("list->count=%li >>",list->count);
if (!list->count) return NULL;
list->count--;
//if (!list) puts("list NULL");
//printf("list->count=%li \n",list->count);

if (!list->count){
list->tail=NULL;
list->head=NULL;
node->list=NULL;
return node;
}
if (node==node->list->head) {
node->prev->next=NULL;
node->list->head=node->prev;
node->list=NULL;
return node;
}

if (node==node->list->tail) {
node->next->prev=NULL;
node->list->tail=node->next;
node->list=NULL;
return node;
}

node->next->prev=node->prev;
node->prev->next=node->next;


node->list=NULL;
node->next=NULL;
node->prev=NULL;
return node;
}


pr_node * pr_list_find(pr_list * list,int n1,int n2){
if(!list->tail) return NULL;
pr_node * p = list->tail;
while (p){if ((p->n1==n1)&&(p->n1==n1)) return p;
p=p->next;}
return NULL;
}


pr_node * pr_node_add(int n1,int n2,unsigned long start,unsigned long end){
pr_node * p = (pr_node*)malloc(sizeof(pr_node));
if (!p) return NULL;
/*----*/
p->n1=n1;
p->n2=n2;
p->start=start;
p->end=end;
/**-----*/
p->prev=NULL;
p->next=NULL;
p->list=NULL;
return p;}




pr_list * pair(dlist * hysto, int * d_in ){ 

pr_list * p = pr_list_init();

return p;}


