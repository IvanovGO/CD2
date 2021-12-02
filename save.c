#include "pair.h"
#include "save.h"

#include <stdio.h>

#include <stdlib.h>
/*
Модуль записи свертки данных в файл
*/





bool pr_save(char * od, unsigned long flen, char file[40]){ //функция сохраняет 
FILE * f = fopen(file, "r");//открываем файл для чтения чтобы проверить наличие
unsigned long count;
if (f){//если не NULL
FILE * f = fopen(file, "w");//открываем файл для записи
   count = fwrite(od,sizeof(char),flen, f);//записываем данные в файл
fclose(f); //закрытие файла
} else {puts("file exists"); return false;}//есди файл сущевствует то не рискуем
 if (count==flen) return true; //если записано все то передаем ок
 	else 
 		return false;} //иначе собщаем что что-то пошло не так





