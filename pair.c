#include "pr_list.h"
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

//printf("prev-%p next-%i num-%p \n",(void*)node,		
//				node->num,(void*)node->list);

printf("num-%i count-%li \n", node->num,node->count);

return 0;
}



/*
pr_node * pr_list_remove(pr_node * node){//удаление узла
puts("pr_list remove");
printf("count %li ",node->list->count);
printf("count-- %li \n",node->list->count);
if (node->list->head!=node) {node->prev->next=node->next->prev;
			     return node;} else node->list->head=node->prev;
node->list->count--;
if (node->list->tail==node) {node->list->tail=NULL;
if (node->list->count) {
      	printf("Warning! Count mismatch with pr_list is empty. %li nodes is orphaned!",node->list->count);
  			}return node;}
node->list=NULL;
return node;
}*/


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

pr_node * pr_list_min(pr_list * list){
pr_node * p = list->tail;
pr_node * mp = p;
int min=p->num;
while (p){if (p->num<min) {min=p->num; mp=p;}
p=p->next;}
//printf("mp-num=%i\n",mp->num);
return mp;}

pr_node * pr_list_max(pr_list * list){
if(!list->tail) return NULL;
pr_node * p = list->tail;
pr_node * mp = p;
int max=p->num;
while (p){if (p->num>max) {max=p->num; mp=p;}
p=p->next;}
return mp;}


pr_node * pr_list_find(pr_list * list,int num){
if(!list->tail) return NULL;
pr_node * p = list->tail;
while (p){if (p->num==num) return p;
p=p->next;}
return NULL;
}

unsigned long pr_list_sum(pr_list * list)
{
if(!list->tail) return 0;
unsigned long rez=0;
pr_node * p = list->tail;
while (p) {rez+=p->count;
p=p->next;}
return rez;
}


pr_node * pr_node_add(int num){
pr_node * p = (pr_node*)malloc(sizeof(pr_node));
if (!p) return NULL;
/*----*/
p->num=num;
p->count=1;
/**-----*/
p->prev=NULL;
p->next=NULL;
p->list=NULL;
return p;}


pr_node * pr_node_inc(pr_node * node){
if (!node) return node;
node->count++;
return node;
}


pr_list * pr_list_sort(pr_list * list){
//puts ("SORT");
if (pr_list_is_empty(list)) return NULL;
//puts("not empty");
if (pr_list_is_trivial(list)) return list;
//puts("not trivaial");
pr_list * p = pr_list_init();

p=list;
//puts("list p");
//printf ("tail p - %p pr_list_list %li\n",(void*)p->tail,pr_list_list(p));

pr_list * ps = pr_list_init();
while(p->count) {//puts("while");
pr_list_add(ps,pr_list_remove(pr_list_max(p)));
//pr_list_list(p);
}

return ps;
}



