#include "Huffman.h"
#include <stdio.h>

int main(){
	HuffmanTree ht;
	HuffmanCode hc;
	int n,i;
	int *weight;
	printf("please input the number of weight:");
	scanf("%d",&n);
	weight = (int *)malloc((n+1)*sizeof(int));
	//权值数组从一开始
	for(i=1;i<=n;i++){
		scanf("%d",&weight[i]);
	}
	CrtHuffmanTree(&ht,&hc,weight,n);
	//输出每个权值对应的哈夫曼编码
	for(i = 1;i<=n;i++)
		printf("%d-->%s\n",ht[i].weight,hc[i]);
	return 0;
}
