#include "SqStack.h"
#include <stdio.h>

Status InitStack(SqStack *S){
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status StackEmpty(SqStack S){
	if(S.top == S.base)
		return OK;
	else{
		return ERROR;
	}
}

Status GetTop(SqStack S, SElemType *e){
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top-1);
	return OK;
}

Status Push(SqStack *S, SElemType e){
	//判断stack是否已满，是就扩容
	if(*S->top - *S->base >= S->stacksize){
		S->base = (SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			exit(OVERFLOW);
		*S->top = *S->base +S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	//*S->top=e;
	//S->top = S->top+1;
	*S->top++=e;
	return OK;
}

Status Pop(SqStack *S, SElemType *e){
	if(S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}
