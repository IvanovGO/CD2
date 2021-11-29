#include "prepare.h"
#include "conv.h"


//struct hysto {int num; long count; char * next; };
/*
Гистограмма представляет собой множдество значений число-частота где под частотой понимается количество вхождений числа в множество
*/

/*
hysto * hysto_head=NULL;//корень гистограммы


hysto * create_hysto(int n){ //функция создает корень сети
hysto * p = (hysto*)malloc(sizeof(hysto));//выделяем память
if (p) {//если выделилась
p->num=n;//задаем первое значение
p->count=1;//оно одно
p->next=NULL;}//no next

return p;//возвращаем результат каким бы он ни был
}

hysto * hysto_add(hysto * head,int n){ //функция создания нового узла гистограммы
 hysto * p = (hysto*)malloc(sizeof(hysto));//выделяем память
 if (p) {  //если память выделилась
 p->num=n; //для этого чила узел
 p->count=1;//таких числе пока что одно
 p->next=head;}//следующего может не быть
return p;//возвращаем результат
}

hysto *  inc_hysto (hysto * p){//функция инкремента узла
		// ссылка на узел
		//puts("inc hysto");
if (p) {
//puts("inc hysto not null");
p->count++;}//если ссылка не на пустоту то увеличиваем количество в узле
//puts("inc hysto null");	
return p;//                 и возвращаем ложь чтобы не добавить узел
}


hysto * is_there(hysto * p,int n){//функция проверяет наличие числа в гистограмме
  //puts("is there");             //искомое число 
while (p){
if (p->num==n) return p;
p=p->next;}
  //puts("!is there"); 
return NULL;
}

*/

/*
for (long i=1;i<MemAllocated;i++){ //printf("%i ",p[i]); //puts("alter for");//проходим по исходным данным
   if (!inc_hysto(is_there(hysto_head,p[i]))) {//если уже было плюсуем соответсвующий
   	hysto_head = hysto_add(hysto_head,p[i]);//если нет добавляем новый узел
   	if (!hysto_head) return NULL;	
   			}}	
*/
dlist * alter_hysto(int * p){//функция создания гистограммы
                            //ссылка на область памяти с исходными данными  

dlist * hysto = dlist_init();

for (unsigned long i=1;i<MemAllocated;i++) //printf("%i ",p[i]); //puts("alter for");//проходим по исходным данным
   if (!dlist_find(hysto,p[i])) {dlist_add(hysto,dnode_add(p[i]));} else {//если нет добавляем новый узел
           dnode_inc(dlist_find(hysto,p[i])); }//уже было плюсуем соответсвующий
    
hysto=dlist_sort(hysto);

printf("Sum of count=%li\n",dlist_sum(hysto));

return  hysto;
}


void print_hysto(dlist * p){
//puts("print_hysto");

dlist_list(p);

}


int * conv(int * p){


return NULL;
}



