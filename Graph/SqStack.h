#include "DS.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);
Status GetTop(SqStack S, SElemType *e);
Status Push(SqStack *S,SElemType e);
Status Pop(SqStack *S,SElemType *e);
Status StackEmpty(SqStack S);
