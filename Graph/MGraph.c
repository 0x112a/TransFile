#include "MGraph.h"
#include "LinkQueue.h"
#include "SqStack.h"
#include <stdio.h>

int visited[N];//访问标识数组
Edge closedge[N];

//创建一个无向图的邻接矩阵
Status CreateUDG(MGraph *G){
	int i,j,k;
	char v1,v2;
	printf("请输入图G的顶点数和边数：");
	scanf("%d %d",&(G->vexnum),&G->arcnum);
	printf("请输入%d个顶点名字(以空格区分)：",G->vexnum);
	for(i=0;i<G->vexnum;i++){
		scanf(" %c",&G->vexs[i]);
	}
	//遍历邻接矩阵置为0
	for (i=0; i<G->arcnum; i++) {
		for(j=0; j<G->arcnum;j++){
			G->arcs[i][j]=0;
		}
	}
	for(k=1;k<=G->arcnum;k++){
		printf("请输入第%d条边的两个顶点(以字符表示，字符间以空格区分)：",k);
		scanf(" %c %c",&v1,&v2);
		i = LocateVex(*G, v1);
		j = LocateVex(*G, v2);
		if (i>=0 && j>=0) {
			G->arcs[i][j] = G->arcs[j][i] = 1;
		}
	}
	return OK;
}

//有向图的邻接矩阵的生成函数
Status CreateDG(MGraph *G){
	int i,j,k;
	char v1,v2;
	printf("请输入图G的顶点数和边数:");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	printf("请输入%d个顶点名字(以空格区分)：",G->vexnum);
	for(i=0;i<G->vexnum;i++)
		scanf(" %c",&G->vexs[i]);
	for(i=0;i<G->arcnum;i++)
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=0;
	for(k=1;k<=G->arcnum;k++){
		printf("请输入第%d条边的两个顶点(以字符表示，字符间以空格区分)：",k);
		scanf(" %c %c",&v1,&v2);
		i = LocateVex(*G, v1);
		j = LocateVex(*G, v2);
		if (i>=0 && j>=0) {
			G->arcs[i][j] = 1;
		}
	}
	return OK;
}
//无向带权图的邻接矩阵的生成函数
Status CreateUDN(MGraph *G){
	int i,j,k,value;
	char v1,v2;
	printf("请输入图G的顶点数和边数:");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	printf("请输入%d个顶点名字(以空格区分)：",G->vexnum);
	for(i=0;i<G->vexnum;i++)
		scanf(" %c",&G->vexs[i]);
	for(i=0;i<G->arcnum;i++)
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=MAX;
	for(k=1;k<=G->arcnum;k++){
		printf("请输入第%d条边的两个顶点(以字符表示，字符间以空格区分)及权值：",k);
		scanf(" %c %c %d",&v1,&v2,&value);
		i=LocateVex(*G, v1);
		j=LocateVex(*G, v2);
		if(i>=0 && j>=0)
			G->arcs[i][j]=G->arcs[j][i]=value;
	}
		
	
	return OK;	
}

//有向带权图的邻接矩阵的生成函数
Status CreateDN(MGraph *G){
	int i,j,k,value;
	char v1,v2;
	printf("请输入图G的顶点数和边数:");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	printf("请输入%d个顶点名字(以空格区分)：",G->vexnum);
	for(i=0;i<G->vexnum;i++)
		scanf(" %c",&G->vexs[i]);
	for(i=0;i<G->arcnum;i++)
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=MAX;
	for(k=1;k<=G->arcnum;k++){
		printf("请输入第%d条边的两个顶点(以字符表示，字符间以空格区分)及权值：",k);
		scanf(" %c %c %d",&v1,&v2,&value);
		i=LocateVex(*G, v1);
		j=LocateVex(*G, v2);
		if(i>=0 && j>=0)
			G->arcs[i][j]=value;
	}
		
	
	return OK;	
}
//查找顶点v在邻接矩阵存储法中的下标
int LocateVex(MGraph G, char v){
	int i;
	for(i = 0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			return i;
	return -1;
}
//深度优先遍历图G
void DFSTraverse(MGraph G){
	int i;
	for(i=0;i<G.vexnum;i++){
		visited[i]=FALSE;
	}
	for(i=0;i<G.vexnum;i++){
		if (visited[i]==0) {
			DFS(G, i);
		}
	}
	printf("\n");
}

void DFS(MGraph G, int v){
	int w;
	visited[v] = TRUE;
	printf("%c ",G.vexs[v]);
	for (w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G, v, w)) {
		if(visited[w]==0)
			DFS(G, w);
	}
}
//在图G中查找顶点v的第一个邻接点
int FirstAdjVex(MGraph G, int v){
	int i;
	for(i=0;i<=G.vexnum;i++)
		if(G.arcs[v][i]!=0)
			return i;
	return -1;
}
//在图G中查找顶点v的邻接点w之后的下一个邻接点
int NextAdjVex(MGraph G, int v, int w){
	int i;
	for(i=w+1;i<G.vexnum;i++)
		if(G.arcs[v][i]!=0)
			return i;
	return -1;
}
//BFSTraverse
void BFSTraverse(MGraph G){
	int i,v,u,w;
	LinkQueue Q;
	//初始化visited
	for(i=0;i<G.vexnum;i++){
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for(v=0;v<G.vexnum;v++){
		if(visited[v]==0){
			visited[v]=TRUE;
			printf("%c ",G.vexs[v]);
			EnQueue(&Q,v);
			while (!QueueisEmpty(Q)) {
				DeQueue(&Q,&u);
				for (w = FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w)) {
					if (!visited[w]) {
						printf("%c ",G.vexs[w]);
						visited[w]=TRUE;
						EnQueue(&Q,w);
					}
				}	
			}
		}
	}
	printf("\n");
}
//在图G中找closedge数组的当前最小值
//@@
int Minimum(MGraph G, Edge *closedge){
	int i,k,Min;
	//Min赋初值
	for(i=0;i<G.vexnum;i++){
		if(closedge[i].lowcost !=0){
			Min=closedge[i].lowcost;
			k=i;
			break;
		}
	}
	//
	for(i++;i<G.vexnum;i++){
		if(closedge[i].lowcost != 0 && closedge[i].lowcost <Min){
			Min = closedge[i].lowcost;
			k=i;
		}
	}
	return k;
}
//从顶点u出发， 按普里姆算法构造连通网G 的最小生成树， 并输出生成树的每条边
void MiniSpanTreePrim(MGraph G, VertexType u){
	int k,i,j,m;
	//找出顶点u在图G里的位置并赋值给k
	k = LocateVex(G,u);
	//初始化边定义
	closedge[k].lowcost =0;
	closedge[k].adjvex = -1;
	//k的边的信息
	for(j=0;j<G.vexnum;j++){
		if(j !=k){
			if(G.arcs[k][j] != MAX){
				closedge[j].adjvex = k;
				closedge[j].lowcost = G.arcs[k][j];
			}else{
				closedge[j].adjvex = -1;
				closedge[j].lowcost = MAX;
			}
		}
	}
	for(i=0;i<G.vexnum;i++){
		k=Minimum(G,closedge);
		//该边所对应的邻接点
		m = closedge[k].adjvex;
		printf("%c %c\n",G.vexs[m],G.vexs[k]);
		//k点纳入u的集合
		closedge[k].lowcost=0;

		for(j=0;j<G.vexnum;j++){
			if(G.arcs[k][j] < closedge[j].lowcost){
				closedge[j].adjvex = k;
				closedge[j].lowcost = G.arcs[k][j];
			}
		}
	}
}
//在图G中求v0到其他点的最短路径
void ShortPathDij(MGraph G, int v0, int *p, int *D){
	int final[N];//保存是否使用过
	int v,i,w,Min,j;
	//三个辅助数组初始化
	//P 存所有边信息
	for(v=0;v<G.vexnum;++v){
		final[v]=FALSE;
		D[v]=G.arcs[v0][v];//有路径则赋值路径值，无路径则即为MAX（3000）
		if(D[v] < MAX)//若有路径则p数组标记可v0
			p[v]=v0;
	}
	//标记顶点v0已从集合T加入到数组中
	D[v0] = 0;
	final[v0]=TRUE;
	//开始循环，每次求得V0到某个V顶点的最短路径，并加V到final数组
	for(i=1;i<G.vexnum;++i){//循环vexnum-1次
		Min =MAX;
		for(w = 0;w<G.vexnum;++w)//找出当前最小路径，并保存至v中,且权值保存至Min中
			if(!final[w])//求当前最短路经的相关信息
				if(D[w]<Min){
					v=w;
					Min=D[w];
				}
		if(Min<MAX)
			final[v] = TRUE;//标记顶点V已从集合T加入到数组f中
		else
			break;//表示v0没有边
		//修改从v0到其他顶点的最短距离和最短路径
		for(w=0;w<G.vexnum;++w){
			if(!final[w] && (Min + G.arcs[v][w]<D[w])){
				D[w] = Min + G.arcs[v][w];
				p[w] = v;
			}
		}
	}
}
//输出v0到其他点的最短路径
void PrintshortPath(MGraph G, int v0, int *p, int *D){
	int i,j;
	SqStack s;
	InitStack(&s);

	for(i=0;i<G.vexnum;i++){
		if(i != v0){
			Push(&s,i);
			j=p[i];//j为v0到i的最短路径
			while (1) {
				Push(&s,j);
				if(j== v0)
					break;
				j = p[j];
			}
			printf("%c到%c的最短路径值为：%d，路径信息为：", G.vexs[v0], G.vexs[i], D[i]);
			while (!StackEmpty(s)) {
				Pop(&s,&j);
				printf("%c->",G.vexs[j]);
			}
			printf("\n");
		}
	}
}
