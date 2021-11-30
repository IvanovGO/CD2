#include <stdbool.h>

/*------------------for CD2 -------------------------------*/

typedef struct pr_node {
struct pr_node * prev;
struct pr_list * list;
unsigned int num;
unsigned long count;
struct pr_node * next; } pr_node;   
	        

typedef struct pr_list {
struct pr_node * head;
struct pr_node * tail;
long count;          } pr_list;
	             
	             
pr_list * pr_list_init();

pr_node * pr_list_remove(pr_node * node);

int pr_list_add(pr_list * list,pr_node * node);//добавление узла в конец

int pr_list_ins(pr_list * list, pr_node * node);//вставка узла в начало

bool pr_list_is_empty(pr_list * list);

bool pr_list_is_trivial(pr_list * list);


unsigned long pr_list_list(pr_list * list);//вывод узлов

pr_node * pr_list_remove(pr_node * node);//удаление узла

pr_node * pr_node_add(int data);

int pr_node_print(pr_node * node);

pr_list * pr_list_sort(pr_list * list);

pr_node * pr_list_find(pr_list * list,int num);

pr_node * pr_list_max(pr_list * list);

pr_node * pr_list_min(pr_list * list);

pr_node * pr_node_inc(pr_node * node);

unsigned long pr_list_sum(pr_list * list);

