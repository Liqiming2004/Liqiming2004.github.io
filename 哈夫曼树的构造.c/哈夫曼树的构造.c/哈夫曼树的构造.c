#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight; //Ȩֵ
    //˫�׽ڵ�����꣬�������꣬�Һ�������
    int parent, lch, rch;
} HTNode, * HuffmanTree;

//������������ n:��ʼ�����
void CreateHuffmanTree(HuffmanTree HT, int n)
{
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        //�ܽ����
        int m = 2 * n - 1;
        //��Ϊ����0�±꣬���п��ٿռ�+1
        //HT[m]�Ǹ����
        HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
        //��ʼ�� ��2n-1��Ԫ����Ϊ0
        for (int i = 1; i <= m; i++)
        {
            HT[i].weight = 0;
            HT[i].parent = 0;
            HT[i].lch = 0;
            HT[i].rch = 0;
        }
        //Ȩֵ��ֵ
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &HT[i].weight);
        }

        //������Ҷ�ӽڵ㣬����������
        for (int i = n + 1; i <= m; i++)
        {
            //ѡ��Ȩֵ��С�������ڵ�,���������ǵ��±꣨��ţ�
            //Select(HT,i-1,s1,s2);
            int s1, s2;
            //��ʱ��i�ǵ�ǰ�´����ڵ�����
            HT[s1].parent = i;
            HT[s2].parent = i;
            HT[i].lch = s1;
            HT[i].rch = s2;
            HT[i].weight = HT[s1].weight + HT[s2].weight;
        }
    }
}
