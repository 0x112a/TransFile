#include "LinkQueue.h"

Status InitQueue(LinkQueue *Q){
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(Qnode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

Status QueueisEmpty(LinkQueue Q){
	if(Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}

Status DestoryQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(Qnode));
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e){
	QueuePtr p;
	if(Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = Q->front->data;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
