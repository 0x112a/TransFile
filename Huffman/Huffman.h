#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "DS.h"
typedef struct{
	int weight;
	int parent,LChild,RChild;
}HTNode,*HuffmanTree;

typedef char * *HuffmanCode;
void CrtHuffmanTree(HuffmanTree *ht,HuffmanCode *hc,int *w,int n);
void Select(HuffmanTree *ht,int n,int *s1,int *s2);

#endif
