#include "DS.h"

typedef int Elemtype;

typedef struct Node
{
    Elemtype  data;
	struct Node *next;
}Lnode,*LinkList;

void menu();
Status Init_Linklist(LinkList &L);
Status Creat_Linklist(LinkList &L);
void Disp_Linklist(LinkList L);
int length_Linklist(LinkList L);
void Reverse_Linklist(LinkList L);
void DelEven_Linklist(LinkList L);
Status Insert_Linklist(LinkList L, int x);
Status CreatOrder_Linklist(LinkList &L);
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc);
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc);
void Split_Linklist(LinkList La, LinkList &Lb);
