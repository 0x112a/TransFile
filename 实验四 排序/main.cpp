#include "algrithm_sorts.h"


/********************������**********************/
int main()
{
    int n;

    while(1)
    {
        printf("    ���˵�\n");
        printf("��ѡ�������㷨\n");
        printf("ð������       1\n");
        printf("�۰��������   2\n");
        printf("ϣ������       3\n");
        printf("��������       4\n");
        printf("������         5\n");
        printf("ֱ�Ӳ�������   6\n");
        printf("��ѡ������   7\n");
        printf("�˳�             0\n");
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
