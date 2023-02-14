#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight; //权值
    //双亲节点的坐标，左孩子坐标，右孩子坐标
    int parent, lch, rch;
} HTNode, * HuffmanTree;

//创建哈夫曼树 n:初始结点数
void CreateHuffmanTree(HuffmanTree HT, int n)
{
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        //总结点数
        int m = 2 * n - 1;
        //因为不用0下标，所有开辟空间+1
        //HT[m]是根结点
        HT = (HuffmanTree)malloc(sizeof(HTNode) * (m + 1));
        //初始化 将2n-1个元素置为0
        for (int i = 1; i <= m; i++)
        {
            HT[i].weight = 0;
            HT[i].parent = 0;
            HT[i].lch = 0;
            HT[i].rch = 0;
        }
        //权值赋值
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &HT[i].weight);
        }

        //创建非叶子节点，建哈夫曼树
        for (int i = n + 1; i <= m; i++)
        {
            //选出权值最小的两个节点,并返回它们的下标（序号）
            //Select(HT,i-1,s1,s2);
            int s1, s2;
            //此时的i是当前新创建节点的序号
            HT[s1].parent = i;
            HT[s2].parent = i;
            HT[i].lch = s1;
            HT[i].rch = s2;
            HT[i].weight = HT[s1].weight + HT[s2].weight;
        }
    }
}
