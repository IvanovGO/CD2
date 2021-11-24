#include "prepare.h"
#include "conv.h"

#define _deb 

//struct hysto {int num; long count; char * next; };
/*
Гистограмма представляет собой 
*/


hysto * hysto_head=NULL;//корень гистограммы

int hysto_add(int n){ //функция создания нового узла гистограммы
 hysto * p = (hysto*)malloc(sizeof(hysto));//выделяем память
 if (p!=NULL) { //если память выделилась
 p->num=n; //для этого чила узел
 p->count=1;//таких числе пока что одно
 p->next=NULL;//следующего может не быть
 return 0; }//возвращаем успех
return 1;//возвращаем неуд
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
 struct hysto * tp = &hysto_head;//корень
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
puts("alter hysto");
for (long i=0;i<MemAllocated;i++){ puts("alter for");//проходим по исходным данным
   if (inc_hysto(is_there(p[i]))) //если уже было плюсуем соответсвующий
   	if (hysto_add(p[i])) return NULL;	//если нет добавляем новый узел
   			}	//если не получилось выход в пустоту
return hysto_head;//вызвращаем ссылку на корень
}


void print_hysto(hysto * p){

while(p->next!=NULL) printf("%i %li\n",p->num,p->count);

}


int * conv(int * p){


return NULL;
}



