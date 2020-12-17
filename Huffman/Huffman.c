#include "Huffman.h"
#include <stdio.h>
#include <stdlib.h>


void Select(HuffmanTree *ht, int n, int *s1, int *s2){
	int i;
	//假设第一个双亲为0的点为最小值
	for (i=1; i<=n; i++) {
		if((*ht+i)->parent == 0){
			*s1=i;
			break;
		}
	}
	//假设第二个双亲为0的点为次小值
	for (i++; i <= n ; i++) {
		if((*ht+i)->parent==0){
			*s2=i;
			break;
		}
	}
	//选出权值最小的两个结点，并把下标赋值给 s1,s2
	for(i=1; i<=n ; i++){
		if((*ht+i)->parent == 0 && (*ht+i)->weight < (*ht+*s1)->weight){
			*s2=*s1;
			*s1 = i;
		}else if ((*ht+i)->parent == 0 && i != *s1 && (*ht+i)->weight < (*ht+*s2)->weight) {
			*s2 = i;
		}
	}
}
//构造Huffman树，并求出huffman便面
void CrtHuffmanTree(HuffmanTree *ht, HuffmanCode *hc, int *w, int n){
	int m,i,s1,s2,start,c,f;
	char *cd;
	if(n<=1)
		return;
	// 计算Huffman树的node数
	m = 2*n-1;
	//创建树的空间
	*ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	//给树的叶结点赋权值
	for(i = 1;i<=n;i++){
		//printf("%d ",*(w+i));
		(*ht+i)->weight=*(w+i);
		(*ht+i)->parent = (*ht+i)->LChild = (*ht+i)->RChild = 0;
	}
	//给树的非叶结点赋初始权值
	for(i=n+1;i<=m;i++){
		(*ht+i)->weight = (*ht+i)->LChild = (*ht+i)->RChild = 0;
	}
	//创建非叶子结点, 建哈夫曼树
	for(i=n+1;i<=m;i++){
		//找出当前权值最小的两个结点
		Select(ht,i-1,&s1,&s2);
		//把对应结点指向父节点
		(*ht+s1)->parent = i;
		(*ht+s2)->parent=i;
		//父结点指向孩子节点
		(*ht+i)->LChild = s1;
		(*ht+i)->RChild = s2;
		//权值为两个孩子节点之和
		(*ht+i)->weight =(*ht+s1)->weight + (*ht+s2)->weight;
		
	}
	//输出哈夫曼树对应的静态链表（数组），帮助检查建立过程是否正确
	for(i=1;i<=m;i++)
		printf("%d %d %d %d\n",(*ht+i)->weight,(*ht+i)->parent,(*ht+i)->LChild,(*ht+i)->RChild);
	//创建n个Huffman编码的指针
	*hc = (HuffmanCode)malloc((n+1)*sizeof(char *));
	cd = (char *)malloc(n*sizeof(char));
	//从右向左逐位存放编码， 首先存放编码结束符
	cd[n-1]= '\0';
	for (i=1;i<=n;i++) {
		// 从右向左逐位存放编码
		start = n-1;
		for(c=i,f=(*ht+i)->parent;f != 0;c=f,f=(*ht+f)->parent)
			//分辨是做还是右分支
			if((*ht+f)->LChild == c)
				cd[--start]= '0';
			else
				cd[--start] = '1';
		//为第i个编码分配空间
		*(*hc+i) = (char *)malloc((n-start)*sizeof(char));
		//存储字符串
		strcpy(*(*hc+i),&cd[start]);
	}
	free(cd);
}
