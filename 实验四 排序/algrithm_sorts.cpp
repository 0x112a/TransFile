#include "algrithm_sorts.h"

/******************ð������********************/
void maopao()
{
    int nums[MAXSIZE];
    int i , j , n , temp;
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("���ѽ���ð������\n");
    printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
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

        printf("��%d����������",num++);
        for(j=0 ; j<n ; j++)
        {
            printf("%d ",nums[j]);
        }
        printf("\n");
    }
    printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",comnum,movnum);
    printf("\n");

    return ;
}
/************************************************/

/*****************�۰��������*******************/
void zheban()
{
    int nums[MAXSIZE];
	int i , j , n , temp;
	int low , high , middle;
	int comnum = 0 , movnum = 0;
	int num = 1;

	printf("���ѽ����۰��������\n");
	printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
	for(i=0 ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }

	for(i=1 ; i<n ; i++)
	{
		low = 0; //��������Ŀ�ͷ�±�
		high = i-1; //���������ĩβ�±�
		temp = nums[i]; //Ҫ���������
		middle = 0;
		//����Ҫ��������±�
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
		//����������,����֮�����Ŀ����
		for(j=i ; j>low ; j--)
		{
			nums[j] = nums[j-1];
		}
		//����nums[i]��nums[low]��λ��
		nums[low] = temp;
		movnum++;

		printf("��%d����������",num++);
		for(j=0 ; j<n ; j++)
        {
            printf("%d ",nums[j]);
        }
        printf("\n");
	}
	printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",comnum,movnum);
	printf("\n");

    return ;
}
/************************************************/

/*******************ϣ������*********************/
void shell()
{
    int i , j , k , n , dk , temp;
    int nums[MAXSIZE];
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("���ѽ���ϣ������\n");
    printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&nums[i]);
    }

    for(dk=n/2; dk>0; dk=dk/2)
    {
		for(i=0; i<dk; i++)
		{
			for(j=i+dk; j<n; j=j+dk)
			{	//����һ�εĲ�������
				if(nums[j] < nums[j-dk])
				{
					temp = nums[j];	//�ڱ�
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
		printf("��%d����������",num++);
        for(i=0 ; i<n ; i++)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");
	}
    printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",comnum,movnum);
    printf("\n");

    return ;
}
/************************************************/

/*******************��������*********************/
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
	while (low < high)//��pivoekeyΪ�ᣬ���������ķ��ں�ߣ�С�����ķ���ǰ��
	{
		while (low < high && nums[high] >= pivotkey)//�����ж� low < high
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

		printf("��%d����������",T++);
		for(i=0 ; i<n ; i++)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");
	}
	return low;//������������λ��
}

void quickSort(int nums[], int low, int high,int n)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(nums, low, high, n);//��nums[]һ��Ϊ��

		quickSort(nums, low, pivot - 1, n);//�Ե��ӱ�ݹ�����
		quickSort(nums, pivot + 1, high, n);//�Ը��ӱ�ݹ�����
	}
}

void kuaipai()
{
    int i , n;
	int nums[MAXSIZE];

	printf("���ѽ����������\n");
    printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
    CN = 0;
    MN = 0;
    T = 1;

	for (i=0; i<n; i++)
	{
		scanf("%d",&nums[i]);
	}

	quickSort(nums, 0, n-1, n);

	printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",CN,MN);
	printf("\n");

    return ;
}
/************************************************/

/********************������**********************/
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
        printf("��%d����������",H++);
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
        printf("��%d����������",H++);
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

    printf("���ѽ��������\n");
    printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
    HMN = 0;
    HCN = 0;
    H = 1;

	for (i=0; i<n; i++)
	{
		scanf("%d",&nums[i]);
	}

	HeapSort(nums, n);
	printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",HCN,HMN);
	printf("\n");

    return ;
}
/************************************************/

/*****************ֱ�Ӳ�������*******************/
void zhicha()
{
    int nums[MAXSIZE];
    int i , j , n;
    int temp;
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("���ѽ���ֱ�Ӳ�������\n");
    printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
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

        printf("��%d����������",num++);
        for(j=0 ; j<n ; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("\n");
    }
    printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",comnum,movnum);
    printf("\n");
}
/************************************************/

/*****************��ѡ������*******************/
void jiandan()
{
    int nums[MAXSIZE];
    int i , j , n;
    int temp , t;
    int comnum = 0 , movnum = 0;
    int num = 1;

    printf("���ѽ����ѡ������\n");
    printf("�������������г��ȣ�");
    scanf("%d",&n);
    printf("�������������У�");
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

        printf("��%d����������",num++);
        for(j=0 ; j<n ; j++)
        {
            printf("%d ", nums[j]);
        }
        printf("\n");
    }
    printf("������̱Ƚϴ�����%d\n��������ƶ�������%d\n",comnum,movnum);
    printf("\n");
}


