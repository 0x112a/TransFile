#include "algrithm_sorts.h"

/******************冒泡排序********************/
void maopao()
{
    int nums[MAXSIZE];
    int i , j , n , temp;
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("您已进入冒泡排序\n");
    printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
    for(i=0 ; i<n ; i++)
        scanf("%d",&nums[i]);

    for(i=0 ; i<n-1 ; i++)
    {
        for(j=0 ; j<n-i-1 ; j++)
        {
            comnum++;
            if(nums[j] > nums[j+1])
            {

                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                movnum++;
            }
        }

        printf("第%d趟排序结果：",num++);
        for(j=0 ; j<n ; j++)
        {
            printf("%d ",nums[j]);
        }
        printf("\n");
    }
    printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",comnum,movnum);
    printf("\n");

    return ;
}
/************************************************/

/*****************折半插入排序*******************/
void zheban()
{
    int nums[MAXSIZE];
	int i , j , n , temp;
	int low , high , middle;
	int comnum = 0 , movnum = 0;
	int num = 1;

	printf("您已进入折半插入排序\n");
	printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
	for(i=0 ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }

	for(i=1 ; i<n ; i++)
	{
		low = 0; //有序数组的开头下标
		high = i-1; //有序数组的末尾下标
		temp = nums[i]; //要被插入的数
		middle = 0;
		//查找要被插入的下标
		while(low <= high)
		{
			middle = (low + high) / 2;
			if(temp < nums[middle])
			{
				high = middle-1;
			}
			else
			{
				low = middle+1;
			}
			comnum++;
		}
		//所有数右移,移完之后插入目标数
		for(j=i ; j>low ; j--)
		{
			nums[j] = nums[j-1];
		}
		//交换nums[i]与nums[low]的位置
		nums[low] = temp;
		movnum++;

		printf("第%d趟排序结果：",num++);
		for(j=0 ; j<n ; j++)
        {
            printf("%d ",nums[j]);
        }
        printf("\n");
	}
	printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",comnum,movnum);
	printf("\n");

    return ;
}
/************************************************/

/*******************希尔排序*********************/
void shell()
{
    int i , j , k , n , dk , temp;
    int nums[MAXSIZE];
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("您已进入希尔排序\n");
    printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }

    for(dk=n/2; dk>0; dk=dk/2)
    {
		for(i=0; i<dk; i++)
		{
			for(j=i+dk; j<n; j=j+dk)
			{	//单独一次的插入排序
				if(nums[j] < nums[j-dk])
				{
					temp = nums[j];	//哨兵
					k = j - dk;
					while(k>=0 && nums[k]>temp)
					{
						nums[k + dk] = nums[k];
						k = k - dk;
					}
					nums[k + dk] = temp;
					movnum++;
				}
				comnum++;
			}
		}
		printf("第%d趟排序结果：",num++);
        for(i=0 ; i<n ; i++)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");
	}
    printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",comnum,movnum);
    printf("\n");

    return ;
}
/************************************************/

/*******************快速排序*********************/
int CN = 0;
int MN = 0;
int T = 1;
void Fswap(int nums[], int i, int j)
{
	int temp;
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
	MN++;
}

int partition(int nums[], int low, int high,int n)
{
    int i;
	int pivotkey;
	pivotkey = nums[low];
	while (low < high)//以pivoekey为轴，将大于它的放在后边，小于它的放在前面
	{
		while (low < high && nums[high] >= pivotkey)//条件判断 low < high
		{
			high--;
			CN++;
		}
		Fswap(nums, low, high);
		while (low < high && nums[low] <= pivotkey)
        {
			low++;
			CN++;
        }
		Fswap(nums, low, high);

		printf("第%d趟排序结果：",T++);
		for(i=0 ; i<n ; i++)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");
	}
	return low;//返回枢轴所在位置
}

void quickSort(int nums[], int low, int high,int n)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(nums, low, high, n);//将nums[]一分为二

		quickSort(nums, low, pivot - 1, n);//对低子表递归排序
		quickSort(nums, pivot + 1, high, n);//对高子表递归排序
	}
}

void kuaipai()
{
    int i , n;
	int nums[MAXSIZE];

	printf("您已进入快速排序\n");
    printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
    CN = 0;
    MN = 0;
    T = 1;

	for (i=0; i<n; i++)
	{
		scanf("%d",&nums[i]);
	}

	quickSort(nums, 0, n-1, n);

	printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",CN,MN);
	printf("\n");

    return ;
}
/************************************************/

/********************堆排序**********************/
int HCN = 0;
int HMN = 0;
int H = 1;
void HeapAdjust(int nums[], int s, int n)
{
    int i , j;
    int temp;

    for(i=s ; 2*i+1<n ; i=j)
    {
        j = 2*i + 1;
        if((j<n-1)&&(nums[j]<nums[j+1]))
        {
            j++;
            HCN++;
        }
        if(nums[i] < nums[j])
        {
            temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			HCN++;
			HMN++;
        }
        else
            break;
    }
}

void HeapSort(int nums[], int n)
{
    int i , j;
    int temp;

    for(i=n/2-1 ; i>=0 ; i--)
    {
        HeapAdjust(nums, i, n);
        printf("第%d趟排序结果：",H++);
		for(j=0 ; j<n ; j++)
        {
            printf("%d ",nums[j]);
        }
        printf("\n");
    }
    for(i=n-1 ; i>0 ; i--)
    {
        temp = nums[i];
        nums[i] = nums[0];
        nums[0] = temp;
        HMN++;

        HeapAdjust(nums, 0, i);
        printf("第%d趟排序结果：",H++);
		for(j=0 ; j<n ; j++)
        {
            printf("%d ",nums[j]);
        }
        printf("\n");
    }
}

void duipai()
{
    int i , n;
    int nums[MAXSIZE];

    printf("您已进入堆排序\n");
    printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
    HMN = 0;
    HCN = 0;
    H = 1;

	for (i=0; i<n; i++)
	{
		scanf("%d",&nums[i]);
	}

	HeapSort(nums, n);
	printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",HCN,HMN);
	printf("\n");

    return ;
}
/************************************************/

/*****************直接插入排序*******************/
void zhicha()
{
    int nums[MAXSIZE];
    int i , j , n;
    int temp;
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("您已进入直接插入排序\n");
    printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }

    for(i=1 ; i<n ; i++)
    {
        if(nums[i] < nums[i-1])
        {
            temp = nums[i];
            for(j=i-1 ; j>=0 ; j--)
            {
                if(temp < nums[j])
                {
                    nums[j+1] = nums[j];
                    comnum++;
                }
                else
                {
                    break;
                    comnum++;
                }
            }
            nums[j + 1] = temp;
            movnum++;
        }
        else
        {
            comnum++;
            continue;
        }

        printf("第%d趟排序结果：",num++);
        for(j=0 ; j<n ; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("\n");
    }
    printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",comnum,movnum);
    printf("\n");
}
/************************************************/

/*****************简单选择排序*******************/
void jiandan()
{
    int nums[MAXSIZE];
    int i , j , n;
    int temp , t;
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("您已进入简单选择排序\n");
    printf("请输入排序序列长度：");
    scanf("%d",&n);
    printf("请输入排序序列：");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }

    for(i=0 ; i<n ; i++)
    {
        temp = nums[i];
        t = i;
        for(j=i+1 ; j<n ; j++)
        {
            if(nums[j] < temp)
            {
                temp = nums[j];
                t = j;
            }
            comnum++;
        }
        temp = nums[i];
        nums[i] = nums[t];
        nums[t] = temp;
        movnum++;

        printf("第%d趟排序结果：",num++);
        for(j=0 ; j<n ; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("\n");
    }
    printf("排序过程比较次数：%d\n排序过程移动次数：%d\n",comnum,movnum);
    printf("\n");
}


