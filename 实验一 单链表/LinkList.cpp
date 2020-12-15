#include "LinkList.h"

void menu()
{
    printf("\t\t\t   �������������\n\n");
    printf("\t\t\t1.��  ��  ��  ��  ��\n");
    printf("\t\t\t2.��  ��  ��  ��  ��\n");
    printf("\t\t\t3.��  ��  �� �� �� ��\n");
    printf("\t\t\t4.��  ��  ��  ��\n");
    printf("\t\t\t5.ɾ  ��  ż �� �� ��\n");
    printf("\t\t\t6.����ֵ��������\n");
    printf("\t\t\t7.��  �����ɽ�  ��  �� ��\n");
    printf("\t\t\t8.��  ��������  ��  �� ��\n");
    printf("\t\t\t9.��  ��  ��  ��\n");
    printf("\t\t\t0.��          ��\n\n");
}

Status Init_Linklist(LinkList &L)
//��ʼ���ձ�
{
    L=(LinkList)malloc(sizeof(Lnode));
    if(!L) return ERROR;
	L->next=NULL;
	return OK;
}

Status Creat_Linklist(LinkList &L)
//β�巨����������
{
    int x;
    LinkList p,rear;
    Init_Linklist(L);
    rear = L;
    printf("����-1��ʾ�������\n");
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
//���������
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
//���㵥������
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
//����������
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
//ɾ��ֵΪż���Ľ��
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
//�����������в���Ԫ�أ�������Ȼ����
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
//�����ǵݼ���������
{
    int x;
    Init_Linklist(L);
    printf("���������Ԫ��ֵ����-1����\n");
    while(scanf("%d", &x), x != -1)
        Insert_Linklist(L, x);
    return OK;
}

void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
//�����ǵݼ���������ϲ���һ���ǵ�����������
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
//�����ǵݼ���������ϲ���һ���ǵݼ���������
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
//����ֵ�ֽ����������һ��ȫ��Ϊ��������һ��ȫ��Ϊż��
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
