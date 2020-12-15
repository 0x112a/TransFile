#include <stdio.h>

#define MAX_stack_size 100

typedef struct{
	int key;

}element;

int top=-1;

void add(int *top,element item){
	if (*top>=MAX_stack_size-1){
		stack_full;
		return;
	}
	stack[++*top]=item;
}

