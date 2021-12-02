#include "pair.h"
#include "prepare.h"
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



bool pr_in_list(){return 0;}


pr_list * find_pr(dlist * hysto, int * d_in){

printf("find_pr \n MemAllocated-%li\n",MemAllocated);

// for (unsigned long a=1;a!=MemAllocated;a++) printf("d_in[%li]=%4i    ",a,d_in[a]);

pr_list * p = pr_list_init();


unsigned long len;

for (dnode * i = hysto->head->prev;i != NULL;i = i->prev ){ //пробегаем по гистограмме количеств чисел 
                     //i - узел для каждого числа       в порядке убывания со второго элемена сверху  (1)
puts("!NULL");
len=0; //обнуляем длинну участка
 
    for (unsigned long j = 0;j!=i->num;j++){ //пробегаем по всем числам менее текущего начиная со второго
//              printf("j=%i ",j);
 if (dlist_find(hysto,j)) {  //если число есть в списке количеств
  
   for (unsigned long a=1;a!=MemAllocated;a++) {//пробегаем по исходным данным
  
 //  printf("j=%li, i->num-%li \r",j,i->num); //выводим пару
   
    if (len>sizeof(pr_list)*2) {printf("len=%li j=%li i->num=%li d_in[%li]=%i\n",len,j,(long int)i->num,a,d_in[a]); 

    pr_node * pn=pr_node_add(j,i->num,a-len,a);    
    pr_list_add(p,pn);
    
    }
   
        len = 0;
        
        
//        printf("len=%li j=%li i->num=%li d_in[%li]=%i\n",len,j,i->num,a,d_in[a]);  
        while (  ( (d_in[a]==j)||(d_in[a]==i->num) )&&( a< MemAllocated-1 )  )//пробегаем по участку
        
      { a++; len++;  }
      //прирост счетчика длинны участка  и печатем результат 
    
     
/*    if ((d_in[a]==i->num||(d_in[a]==i->next->num))&&(a!=MemAllocated)) {
                len++;                     
    			     }

   printf(" i->num %i i->next->num = %i %li \n",i->num,i->next->num,len);
*/     
// printf("\ni->num=%li j=%li len=%li ",(long int)i->num,j,len);
                                                }
                          } /*else puts("skip");*/}
//                    printf("%i ",i->num);                                
						   }
return p;}




pr_list * convolutions(pr_list * pl,int * d_in){ //функция битовой свертки 
puts ("conv");



for (pr_node * i = pl->tail;i!=pl->head;i=i->next) {//пробегаем по спискам найденных двоичных 
//								последователностей
pr_node_print(i);//отладочный вывод

i->conv_len=(i->start-i->end)/sizeof(char);//вычисляем длинну памяти под свертку
char * b = (char*) malloc(i->conv_len+1);//выделяем память
i->conv=b;
for(unsigned long m=i->start;m<i->end;m++){ //пробегаемся по участку исходных данных 
	for (char b=1;b!=sizeof(char);b++) {
				m++;
					   }


}


}

return pl;}


