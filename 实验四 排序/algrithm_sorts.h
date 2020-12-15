#include <stdio.h>
#include <string.h>
#define MAXSIZE 100 /*参加排序元素的最大个数*/

/******************冒泡排序********************/
void maopao();
/*****************折半插入排序*******************/
void zheban();
/*******************希尔排序*********************/
void shell();

/*******************快速排序*********************/
void Fswap(int nums[], int i, int j);

int partition(int nums[], int low, int high,int n);

void quickSort(int nums[], int low, int high,int n);

void kuaipai();

/********************堆排序**********************/

void HeapAdjust(int nums[], int s, int n);
void HeapSort(int nums[], int n);
void duipai();

/*****************直接插入排序*******************/
void zhicha();

/*****************简单选择排序*******************/
void jiandan();



