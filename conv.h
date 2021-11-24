#include <stdbool.h>

typedef struct hysto {int num; long count; struct hysto * next; } hysto;



hysto * alter_hysto(int * p); 

void print_hysto(hysto * p);

int * conv(int * p);
