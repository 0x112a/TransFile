#include "LinkList.h"

void menu()
{
    printf("\t\t\t   单链表基本操作\n\n");
    printf("\t\t\t1.建  立  单  链  表\n");
    printf("\t\t\t2.遍  历  单  链  表\n");
    printf("\t\t\t3.计  算  链 表 长 度\n");
    printf("\t\t\t4.链  表  逆  置\n");
    printf("\t\t\t5.删  除  偶 数 节 点\n");
    printf("\t\t\t6.生成值有序单链表\n");
    printf("\t\t\t7.合  并生成降  序  链 表\n");
    printf("\t\t\t8.合  并生成升  序  链 表\n");
    printf("\t\t\t9.分  解  链  表\n");
    printf("\t\t\t0.退          出\n\n");
}

Status Init_Linklist(LinkList &L)
//初始化空表
{
    L=(LinkList)malloc(sizeof(Lnode));
    if(!L) return ERROR;
	L->next=NULL;
	return OK;
}

Status Creat_Linklist(LinkList &L)
//尾插法建立单链表
{
    int x;
    LinkList p,rear;
    Init_Linklist(L);
    rear = L;
    printf("输入-1表示输入结束\n");
    while(scanf("%d",&x),x != -1)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        if(!p) return ERROR;
        p->data = x;
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    return OK;
}

void Disp_Linklist(LinkList L)
//单链表遍历
{
    LinkList p;
    p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length_Linklist(LinkList L)
//计算单链表长度
{
    int count = 0;
    LinkList p;
    p = L->next;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}
void Reverse_Linklist(LinkList L)
//单链表逆置
{
    LinkList p, q ;
    p = L->next;
    L->next = NULL;
    while(p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
void DelEven_Linklist(LinkList L)
//删除值为偶数的结点
{
    LinkList p, q;
    q = L;
    p = L->next;
    while(p)
    {
        if(p->data % 2 == 0)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
Status Insert_Linklist(LinkList L, int x)
//在有序单链表中插入元素，链表仍然有序
{
    LinkList p, q, s;
    q = L;
    p = L->next;
    while(p)
    {
        if(p->data <= x)
        {
            q = p;
            p = p->next;
        }
        else
            break;
    }
    s = (LinkList)malloc(sizeof(Lnode));
    if(!s) return ERROR;
	s->data = x;
    q->next = s;
	s->next = p;
	return OK;
}
Status CreatOrder_Linklist(LinkList &L)
//创建非递减有序单链表
{
    int x;
    Init_Linklist(L);
    printf("请输入表中元素值，以-1结束\n");
    while(scanf("%d", &x), x != -1)
        Insert_Linklist(L, x);
    return OK;
}

void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
//两个非递减有序单链表合并成一个非递增有序链表
{
    LinkList pa, pb, pc;
    Lc = La;
    pa = La->next; La->next = NULL;
    pb = Lb->next; Lb->next = NULL;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc = pa->next; pa->next = Lc->next; Lc->next = pa; pa = pc;
        }
        else
        {
            pc = pb->next; pb->next = Lc->next; Lc->next = pb; pb = pc;
        }
    }
    while(pa)
    {
        pc = pa->next;
        pa->next = Lc->next;
        Lc->next = pa;
        pa = pc;
    }
    while(pb)
    {
        pc = pb->next;
        pb->next = Lc->next;
        Lc->next = pb;
        pb = pc;
    }
}

void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
//两个非递减有序单链表合并成一个非递减有序链表
{
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    pc = Lc = La;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa; pc = pa; pa = pa->next;
        }
        else
        {
            pc->next = pb; pc = pb; pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

void Split_Linklist(LinkList La, LinkList &Lb)
//链表按值分解成两个链表，一个全部为奇数，另一个全部为偶数
{
    LinkList p, q, r;
    Init_Linklist(Lb);
    q = La;
    p = La->next;
    r = Lb;
    while(p)
    {
        if(p->data %2 == 0)
        {
            q->next = p->next;
            r->next = p;
            r = p;

        }
        else
        {
            q = p;
        }
        p = q->next;
    }
    r->next = NULL;
}
