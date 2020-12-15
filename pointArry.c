#include<stdio.h>

void print1(int *ptr,int rows);
int main(void){
	int a[]={1,2,3,4,5,6,};
	print1(a, sizeof(a)/sizeof(a[0]));
	return 0;
}
void print1(int *ptr,int rows){
	int i;
	printf("Address Contents\n");
	for (i=0;i<rows;i++){
		printf("%8u%5d\n", ptr+i ,*(ptr+i));
	}
}
