#include "pair.h"
#include "save.h"

#include <stdio.h>

#include <stdlib.h>
/*
Модуль записи свертки данных в файл
*/

unsigned char * pr_compose(pr_list * pl,int * d_in, unsigned long MemAllocated){
puts("pr_compose");

unsigned long count_byte=1;//длинна данных 
                //плохой стиль - если первое число больше 0xffff будет крах 


for (pr_node * i = pl->tail;i!=pl->head;i=i->next) {//проходим по списку пар
         if (i->prev) {count_byte+=i->start-i->prev->end;  } 
              //еслит есть предыдущий элемент вычиляем разницу между концом пред и началом текущего
           else count_byte+= i->start; //если нет предыдущего это первый и его начало=длинне
                                count_byte+=i->conv_len; //приплюсовываем длинну свёртки
                                }
printf("Convolution`s data length count_byte= %li\n",count_byte);

unsigned char * p = (unsigned char*)malloc(count_byte);

union  { //это нужно чтобы записать 2400 в первые два байта результата
unsigned short w;
unsigned char c[2];}w;
w.w=2400;
p[0]=w.c[0];
p[1]=w.c[1]; //it was per rectuum))
pr_node * tn;

for (unsigned long m=2;m<MemAllocated;m++)
{
   tn=find_pr_node(pl,m);    
   printf("Finding node by m? tn=%p ",tn);                    
   if  (!tn) { p[m]=d_in[m]; printf("d_in[%li]=%i \n",m,d_in[m]); }  else //если данные  не в свертке то всё тривиально
                //иначе ищем длинну в соответствующей ноде
          {  printf("Node with conv found\n");
             for (unsigned int cm=0;cm<tn->conv_len;cm++){ //заводим цикл
                            //если вдруг не вышли за пределы исходных данных
                    printf("Copying mem 2 mem cm=%i  \n",cm);
                      if (m<MemAllocated) { p[m]=tn->conv[cm];m++; 
            printf("copying from conv cm=%i conv_lenc=%i m=%li\n",cm,tn->conv_len,m);       } //пишем свёрточные данные в результат 
                                        else { puts("Epic FAIL");return NULL;}//иначе все пошло не так возвращаем ничего
             m=tn->end;//устанавливаем адресс данных в конец свертки
          }  }
}
printf("Returns conv len=%li, pointer on conv %p\n ",pl->conv_len,pl->conv);
pl->conv_len=count_byte;
pl->conv=p;
return p;}//возвращаем ссылку на результат



bool pr_save(pr_list * pl, char * file){ //функция сохраняет 
if (!pl) return false;
unsigned char * od = pl->conv;
unsigned long flen = pl->conv_len;//это надо перенсти в тело функции
printf("Saving flen=%li ",flen);
FILE * f = fopen(file, "r");//открываем файл для чтения чтобы проверить наличие
unsigned long count;
if (!f){//если  NULL
FILE * f = fopen(file, "w");//открываем файл для записи
   count = fwrite(od,sizeof(char),flen, f);//записываем данные в файл
   printf(" %li bytes written\n",count);
fclose(f); //закрытие файла
} else {puts("file exists"); return false;}//если файл сущевствует то не рискуем
 if (count==flen) return true; //если записано все то передаем ок
 	else 
 		return false;
 		} //иначе собщаем что что-то пошло не так
