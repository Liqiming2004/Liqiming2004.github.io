#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define maxInt 32767    //表示极大值，即无穷符号
#define maxPointNum 100 //最大顶点数

typedef struct
{
    char vexs[maxPointNum];             //顶点表
    int arcs[maxPointNum][maxPointNum]; //邻接矩阵
    int vexNum, arcNum;                 //图的当前顶点数和边数
} UDGraph, * PUDGraph;                   //无向网Undirected Graph

//查找顶点的下标
int locateVex(UDGraph G, int vex)
{
    for (int i = 0; i < G.vexNum; i++)
    {
        if (vex == G.vexs[i])
        {
            return i;   
        }
        else
        {
            return -1;
        }
    }
}        

//创建无向网
void createUDG(PUDGraph G)
{
    //输入顶点数和边数
    printf("输入顶点数和边数");
    scanf("%d %d", &G->vexNum, &G->arcNum);

    //输入每个点的信息
    for (int i = 0; i < G->vexNum; i++)
    {
        scanf("%c", &G->vexs[i]);
    }

    //初始化邻接矩阵,每个赋值极大值(无穷)
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            G->arcs[i][j] = maxInt;
        }
    }

    //构造邻接矩阵
    for (int k = 0; k < G->arcNum; k++)
    {
        int v1, v2, weight;
        //输入一条边的两个顶点的值和边的权值
        scanf("%d %d %d", &v1, &v2, &weight);
        int i = locateVex(*G, v1);
        int j = locateVex(*G, v2);
        G->arcs[i][j] = weight;
        //无向的是对称的
        G->arcs[j][i] = G->arcs[i][j];
    }
    return;
}