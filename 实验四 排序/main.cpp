#include "algrithm_sorts.h"


/********************主函数**********************/
int main()
{
    int n;

    while(1)
    {
        printf("    主菜单\n");
        printf("请选择排序算法\n");
        printf("冒泡排序法       1\n");
        printf("折半插入排序法   2\n");
        printf("希尔排序法       3\n");
        printf("快速排序法       4\n");
        printf("堆排序法         5\n");
        printf("直接插入排序法   6\n");
        printf("简单选择排序法   7\n");
        printf("退出             0\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: maopao();   continue;
            case 2: zheban();   continue;
            case 3: shell();    continue;
            case 4: kuaipai();  continue;
            case 5: duipai();   continue;
            case 6: zhicha();   continue;
            case 7: jiandan();  continue;
            default:    break;
        }
        if(n == 0)
            break;
    }

    return 0;
}
