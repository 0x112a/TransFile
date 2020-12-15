typedef int Position;
typedef struct LNode *List;

struct LNode{
	ElementType Data[MaxSize];
	Position Last;
}

/* 初始化 */

List MakeEmpty(){
	List L;
	L =(List)malloc(sizeof(struct LNode));
	return L;
}

// find elementtype
//
#define ERROR -1

Position Find(List L, ElementType x){
	Position i = 0;
	while (i<= L->Last && L->Data[i]!=x) {
		i++;
	}
	if (i > L->Last) {
		return ERROR;
	}
	else
		return i;
}
// insert
//
bool Insert(List L ,ElementType x,Position P){
	Position i;
	if (L->Last == MaxSize-1) {
		print("full");
		return false;
	}
	if(P < 0 || P>L->Last+1){
		print("position is illegal");
		return false;
	}
	for (i=L->Last;i>=P;i--){
		L->Data[i+1]=L->Data[i];
	}
	L->Data[P]=x;
	L->Last++;
	return true;
}

// delete
bool Delete (List L,Position P){
	Position i;
	if(P<0||p>L->Last){
		print("no find position \"P\"");
		return false;
	}
	for(i=P+1;i<L->Last;i++)
		L->Data[i-1]=L->Data[i];
	L->Last--;
	return true;
}
