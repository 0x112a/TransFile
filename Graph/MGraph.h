#include "DS.h"

#ifndef MGRAPH_H_INCLUDED
#define MGRAPH_H_INCLUDED

#define MAX 3000
#define N 10 //最多定点数
typedef char VertexType;//顶点类型
typedef struct{
	VertexType vexs[N];
	int arcs[N][N];//存边信息的矩阵
	int vexnum,arcnum;//顶点数，边数

}MGraph;

typedef struct{
	VertexType adjvex;
	int lowcost;//边权值
}Edge;
#endif
//无向图
Status CreateUDG(MGraph *G);
//有向图
Status CreateDG(MGraph *G);
//无向带权图
Status CreateUDN(MGraph *G);
//有向带全图
Status CreateDN(MGraph *G);

// 查找顶点V 在邻接矩阵存储法中的下标
int LocateVex(MGraph G,char v);
//在图G 中查找顶点v的第一个邻接点
int FirstAdjVex(MGraph G,int v);
//在图G中查找顶点v的邻接点w之后的下一个邻接点
int NextAdjVex(MGraph G, int v, int w);
//深度优先搜索图G
void DFSTraverse(MGraph G);
//
void DFS(MGraph G,int v);
//广度优先搜素图G
void BFSTraverse(MGraph G);

//求closedge数组的最小值
int Minimum(MGraph G,Edge closedge[]);
//Prim算法求最小生成树
void MiniSpanTreePrim(MGraph G,VertexType u);

//求closedge数组的最小值
void ShortPathDij(MGraph G, int v0,int *p,int *D);
//求closedge数组的最小值
void PrintshortPath(MGraph G,int v0,int *p,int *D);

