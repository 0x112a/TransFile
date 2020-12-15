#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int data;
	struct Node *pNext;
}NODE,*Pnode;

Pnode create_slist();
void traverse_slist(Pnode);
bool is_empty(Pnode);
int length_slist(Pnode);
void sort_slist(Pnode);
bool insert_slist(Pnode);
bool delete_slist(Pnode);
void cleat_slist(Pnode);

int main(void){
	int len;
	int data_del;
	Pnode phead = NULL;
	
	phead = create_slist();


}
Pnode create_slist(){
	int val;
	Pnode phead = (Pnode)malloc(sizeof(NODE));
	Pnode pCurrent = phead;
	pCurrent->pNext = NULL;
	if (phead == NULL){
		printf("phead malloc failed！");
		exit(-1);
	}
	printf("Input first data(q to quit):");
	while(scanf("%d",&val)==1){
		Pnode pNew = (Pnode)malloc(sizeof(NODE));
		if(NULL == pNew){
			printf("pNew malloc failed");
			exit(-1);
		}
		pNew->data = val;
		pCurrent->pNext = pNew;
		pNew->pNext=NULL;
		pCurrent = pNew;
		printf("input next data(q to quit):");
	}
	return phead;
}

void traverse_list(Pnode phead){
	Pnode pCurrent = phead->pNext;
	printf("now dataes in the slist are:\n");
	while(pCurrent != NULL){
		printf("%d\n",pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
	printf("\n");
	return ;
}
bool is_empty(Pnode phead){
	if(phead->pNext == NULL)
		return true;
	else
		return false;
}

int length_slist(Pnode phead){
	int count=0;
	Pnode p = phead->pNext;
	while(p!=NULL){
		count++;
		p=p->pNext;
	}
	return count;
}
// 排序
// 复杂度n^2
void sort_slist(Pnode phead){
	Pnode p,q;
	int temp;
	for (p=phead->pNext; p!=NULL ;p=p->pNext) {
		for (q=p->pNext; q!=NULL; q=q->pNext) {
			if (p->data > q->data) {
				temp = q->data;
				q->data=p->data;
				p->data=temp;
			}	
		}
	}
	return;
}

bool insert_slist(Pnode phead){

	return true;
}
