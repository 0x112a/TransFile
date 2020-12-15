#include "DS.h"

typedef int QElemType;

typedef struct Qnode{
	QElemType data;
	struct Qnode *next;
}Qnode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化队列
Status InitQueue(LinkQueue *Q);
//判断队列是否为空
Status QueueisEmpty(LinkQueue Q);
//销毁队列
Status DestoryQueue(LinkQueue *Q);
//入队列
Status EnQueue(LinkQueue *Q, QElemType e);
//出队列
Status DeQueue(LinkQueue *Q, QElemType e);

