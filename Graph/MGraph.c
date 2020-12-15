#include "MGraph.h"
#include <stdio.h>
#include "LinkQueue.h"

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

//无向带权图的邻接矩阵的生成函数
//有向带权图的邻接矩阵的生成函数
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
	for(i=0;i<G.vexnum;i++){
		visited[i] = FALSE;
	}
	InitQueue(&Q);
	for(v=0;v<G.vexnum;v++){
		if(visited[v]==0){
			visited[v]=TRUE;
			printf("%c",G.vexs[v]);
			EnQueue(&Q,v);
			while (!QueueisEmpty(Q)) {
				DeQueue(&Q,v);
				for (w = FirstAdjVex(G,u); w>=0; w=NextAdjVex(G,u,w)) {
					if (!visited[w]) {
						printf("%c",G.vexs[w]);
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
//从顶点u出发， 按普里姆算法构造连通网G 的最小生成树， 并输出生成树的每条边
//在图G中求v0到其他点的最短路径
//输出v0到其他点的最短路径
//
