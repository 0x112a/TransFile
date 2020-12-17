#include "Huffman.h"
#include <stdio.h>
#include <stdlib.h>

void menu();

void Select(HuffmanTree *ht, int n, int *s1, int *s2){
	int i;
	for (i=1; i<=n; i++) {
		if(ht[i]->parent == 0){
			*s1=i;
			break;
		}
	}
	for (i++; i <= n ; i++) {
		if(ht[i]->parent==0){
			*s2=i;
			break;
		}
	}
	for(i=1; i<=n ; i++){
		if(ht[i]->parent == 0 && ht[i]->weight < ht[*s1]->weight){
			//@@
			*s2=*s1;
			*s1 = i;
		}else if (ht[i]->parent == 0 && i != *s1 && ht[i]->weight < ht[*s1]->weight) {
			*s2 = i;
		}
	}
}

void CrtHuffmanTree(HuffmanTree *ht, HuffmanCode *hc, int *w, int n){
	int m,i,s1,s2,start,c,f;
	char *cd;
	if(n<=1)
		return;
	m = 2*n-1;
	*ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for(i = 1;i<=n;i++){
		ht[i]->weight=w[i];
		ht[i]->parent = ht[i]->LChild = ht[i]->RChild = 0;
	}
	for(i=n+1;i<=m;i++){
		ht[i]->weight = ht[i]->LChild = ht[i]->RChild = 0;
	}
	for(i=n+1;i<=m;i++){
		Select(ht,i-1,&s1,&s2);
		ht[s1]->parent = i;
		ht[s2]->parent=i;
		ht[i]->LChild = s1;
		ht[i]->weight = ht[s1]->weight + ht[s2]->weight;
		
	}
	for(i=1;i<=m;i++)
		printf("%d %d %d %d\n",ht[i]->weight,ht[i]->parent,ht[i]->LChild,ht[i]->RChild);
	*hc = (HuffmanCode)malloc((n+1)*sizeof(char *));
	cd = (char *)malloc(n*sizeof(char));
	cd[n-1]= '\0';

}
