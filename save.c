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

unsigned long m=0;

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

bool not_in_conv;//не попадает в свертку
for (unsigned long m=2;m<MemAllocated;m++)
{
not_in_conv=true;
for (pr_node * i = pl->tail;i!=pl->head;i=i->next) 
             if (i->prev)  if ( !((m>i->start) && (m<i->end)) ) {not_in_conv=false;}
                                
   if  (!not_in_conv)  p[m]=d_in[m];  else 
                                           while() 
   
}
return p;}//возвращаем ссылку на результат



bool pr_save(unsigned char * od, unsigned long flen, char file[40]){ //функция сохраняет 
FILE * f = fopen(file, "r");//открываем файл для чтения чтобы проверить наличие
unsigned long count;
if (!f){//если  NULL
FILE * f = fopen(file, "w");//открываем файл для записи
   count = fwrite(od,sizeof(char),flen, f);//записываем данные в файл
fclose(f); //закрытие файла
} else {puts("file exists"); return false;}//если файл сущевствует то не рискуем
 if (count==flen) return true; //если записано все то передаем ок
 	else 
 		return false;} //иначе собщаем что что-то пошло не так





