#include "pair.h"
#include "save.h"

#include <stdio.h>

#include <stdlib.h>
/*
Модуль записи свертки данных в файл
*/

bool pr_compose(pr_list * pl,int * d_in, unsigned long MemAllocated, char * file){

puts("pr_compose & save");

FILE * f = fopen(file, "r");//открываем файл для чтения чтобы проверить наличие
unsigned long count;
if (!f){//если  NULL
FILE * f = fopen(file, "w");//открываем файл для записи
             
union  { //это нужно чтобы записать 2400 в первые два байта результата
unsigned short w;
unsigned char c[2];}w;
w.w=2400;
//p[0]=w.c[0];
//p[1]=w.c[1]; //it was per rectuum))

unsigned char * ch = (unsigned char*)malloc(sizeof(unsigned char));
pr_node * tn; //temporary node

   count = fwrite(&w.w,sizeof(w),1, f);//записываем данные в файл
   printf("2400 in %li bytes written\n",count*sizeof(w));

for (unsigned long m=2;m<MemAllocated;m++)
 { printf("Next iteration with m=%li\n",m);
   
    tn=find_pr_node(pl,m);    
   
    printf("Finding node by m? tn=%p \n",(void*)tn);  
   
         //если данные  не в свертке то всё тривиально                  
   
   if  (!tn) {    *ch = (unsigned char) d_in[m];
                   fprintf(f,"%c",*ch);
                  //   fprintf(f,"%i\n",*ch);
                 /* count = fwrite(ch,sizeof(unsigned char),1, f);//записываем данные в файл
                  printf(" %li bytes written d_in[%li]=%i \n",count,m,d_in[m]);*/
   
    }  else 
                //иначе ищем длину в соответствующей ноде
          {  printf("Node with conv found\n");
             for (unsigned int cm=0;cm<tn->conv_len;cm++){ //заводим цикл
                            //если вдруг не вышли за пределы исходных данных
                    printf("Copying mem2mem cm=%i  \n",cm);

                      if (m<MemAllocated) { 

                      *ch=tn->conv[cm];
                      fprintf(f,"%0c",*ch);
                   //   fprintf(f,"%i ",*ch);
                  /*    count = fwrite(ch,sizeof(unsigned char),1, f);//записываем данные в файл

                  printf(" %li bytes written d_in[%li]=%i \n",count,m,d_in[m]);  */  

  printf("copying from conv cm=%i conv_lenc=%i m=%li\n",cm,tn->conv_len,m);       } //пишем свёрточные данные в результат 
               
                else { puts("Epic FAIL");return NULL;}//иначе все пошло не так возвращаем ничего
             
          } //fprintf(f,"\n"); 
          m=tn->end; } //устанавливаем адресс данных в конец свертки
}
printf("Returns conv len=%li, pointer on conv %p\n ",pl->conv_len,pl->conv);


fclose(f); //закрытие файла
} else {puts("file exists"); return false;}//если файл сущевствует то не рискуем

return false;}//возвращаем ссылку на результат






