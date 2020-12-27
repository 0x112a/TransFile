#include <stdio.h>
void LargestTow(int a[],int n,int *pfirst,int *psecond);

int main(){
	int n;
	int pfirst,psecond;
	scanf("%d",&n);
	int a[n];
	for (int i=0; i<n;i++) {
		scanf("%d",a+i);
	}
	LargestTow(a,n,&pfirst,&psecond);
	printf("%d %d\n",pfirst,psecond);
	return 0;
}
void LargestTow(int a[],int n,int *pfirst,int *psecond)
{
      /*数组a有n个元素，将数组中的最大值存入形参指针pfirst所指内存单元，将数组中第二大的值存入形参指针psecond所指内存单元。 */
	int i,j;
	*pfirst=a[0];
	for (i=0; i<n; i++) {
		
		if(a[i]>*pfirst){
			*pfirst=a[i];
			j=i;
		}
	}
	*psecond= 0==j?a[1]:a[0];
	for (i=0; i<n ; i++) {
		if(a[i]>*psecond && i!=j){
			*psecond=a[i];
		}
	}	
}
