#include "MGraph.h"
#include <stdio.h>

int main(){
	MGraph G;
	VertexType u;
	int i,j,v0;
	int D[N],P[N]={-1};//若P[v]==w，则w是从v0(起点)到v当前求得最短路径上的-点-,D保存v0到v 的最短路径值
	printf("无向图的基本操作：\n");
	CreateUDG(&G);
	printf("图中的顶点信息为：\n");
	for(i=0;i<G.vexnum;i++)
		printf("%c ",G.vexs[i]);
	printf("\n");
	printf("邻接矩阵为：\n");
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			printf("%d ",G.arcs[i][j]);
		}
		printf("\n");
	}
	printf("深度优先搜索序列：");
	DFSTraverse(G);
	printf("广度优先搜索序列：");
	BFSTraverse(G);
	
	printf("带权无向图求最小生成树：\n");
	CreateUDN(&G);
	printf("最小生成树的信息为：\n");
	u=G.vexs[0];
	MiniSpanTreePrim(G, u);
	printf("带权有向图求最短路径：\n");
	CreateDN(&G);
	printf("请输入起点：");
	scanf(" %c",&u);
	v0 = LocateVex(G,u);
	ShortPathDij(G,v0,P,D);
	PrintshortPath(G,v0,P,D);
	return 0;
}
