#include <stdbool.h>
#include "conv.h"

/*------------------for CD2 -------------------------------*/
// модуль с процедурами нахождения кусков кода с повторяющимися бинарными данными

typedef struct pr_node {
struct pr_node * prev;
struct pr_list * list;
//-----------------
int n1,n2;//найденная пара
unsigned long start,end; // смещение начала и конца последовательности из найденной пары

unsigned int conv_len;
unsigned char * conv; //ссылка на готовую свертку



//------------------
struct pr_node * next; } pr_node;   

typedef struct pr_list {
struct pr_node * head;
struct pr_node * tail;
unsigned long count; 
unsigned long c_count; 
unsigned long conv_len;
unsigned char * conv;
         } pr_list;
	            
	            
pr_node *  find_pr_node(pr_list * list, unsigned long m);//возвращает ссылку на свертку в которую "попали" исходные данные пo адресу m 
	            
pr_list * convolutions(pr_list * pl,int * d_in); //свертка 

void print_conv(pr_list * pl);// вывод свертки на stdout

pr_list * find_pr(dlist * hysto, int * d_in);
	             
pr_list * pr_list_init();

pr_node * pr_list_remove(pr_node * node);

int pr_list_add(pr_list * list,pr_node * node);//добавление узла в конец

int pr_list_ins(pr_list * list, pr_node * node);//вставка узла в начало

bool pr_list_is_empty(pr_list * list);

bool pr_list_is_trivial(pr_list * list);


unsigned long pr_list_list(pr_list * list);//вывод узлов

pr_node * pr_list_remove(pr_node * node);//удаление узла

pr_node * pr_node_add(int n1,int n2,unsigned long start,unsigned long end);

int pr_node_print(pr_node * node);



pr_node * pr_list_find(pr_list * list,int n1,int n2);



//unsigned long pr_list_sum(pr_list * list);

