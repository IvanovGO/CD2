#include "prepare.h"
#include "conv.h"

#define _deb 

//struct hysto {int num; long count; char * next; };
/*
Гистограмма представляет собой 
*/


hysto * hysto_head=NULL;//корень гистограммы


hysto * create_hysto(int n){ //функция создает корень сети
hysto * p = (hysto*)malloc(sizeof(hysto));//выделяем память
if (p!=NULL) {//если выделилась
p->num=n;//задаем первое значение
p->count=1;}//оно одно
return p;//возвращаем результат каким бы он ни был
}

hysto * get_last_hysto(hysto * p){//функция возвращает указатель на верхушку сети
			//передаем корень
while (1){//бесконечный цикл
if (p->next==NULL) return p; //если следующего нет, значит вершина
p=p->next;}//загружаем следующий узел
return NULL;// пустая сеть
}

hysto * hysto_add(int n){ //функция создания нового узла гистограммы
 hysto * p = (hysto*)malloc(sizeof(hysto));//выделяем память
 if (p!=NULL) {  //если память выделилась
 get_last_hysto(hysto_head)->next=p;
 p->num=n; //для этого чила узел
 p->count=1;//таких числе пока что одно
 p->next=NULL;//следующего может не быть
 return p; }//возвращаем успех
return NULL;//возвращаем неуд
}

int  inc_hysto (hysto * p){//функция инкремента узла
		// ссылка на узел
		puts("inc hysto");
if (p!=NULL) {
puts("inc hysto not null");
p->count++;return 0;}//если ссылка не на пустоту то увеличиваем количество в узле
puts("inc hysto null");	//                 и возвращаем ложь чтобы не добавить узел
return 1;//иначе надо добавлять           
}


hysto * is_there(int n){//функция проверяет наличие числа в гистограмме
  puts("is there");             //искомое число 
 hysto * tp = hysto_head;//корень
  puts("is there struct"); 
while (tp->next!=NULL){//пока есть следующий узел
puts("is there while"); 
if (tp->num==n) return tp;//если число надено то выходим и возвращаем адрес (не пустой)
tp=tp->next;//переключаемся на следующий узел
}
return NULL;//ничего не найдено
}

hysto * alter_hysto(int * p){//функция создания гистограммы
                            //ссылка на область памяти с исходными данными  
//struct hysto * tp = NULL; //
puts(" hysto head");
hysto_head=create_hysto(p[0]);
puts("alter hysto");
for (long i=1;i<MemAllocated;i++){ puts("alter for");//проходим по исходным данным
   if (inc_hysto(is_there(p[i]))) //если уже было плюсуем соответсвующий
   	if (hysto_add(p[i])==NULL) return NULL;	//если нет добавляем новый узел
   			}	//если не получилось выход в пустоту
return hysto_head;//вызвращаем ссылку на корень
}


void print_hysto(hysto * p){
puts("print_hysto");
while(p->next!=NULL) {
	printf("Output - %i %li\n",p->num,p->count);
	 p=p->next; }

}


int * conv(int * p){


return NULL;
}



