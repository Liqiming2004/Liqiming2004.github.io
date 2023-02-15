#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define maxInt 32767    //��ʾ����ֵ�����������
#define maxPointNum 100 //��󶥵���

typedef struct
{
    char vexs[maxPointNum];             //�����
    int arcs[maxPointNum][maxPointNum]; //�ڽӾ���
    int vexNum, arcNum;                 //ͼ�ĵ�ǰ�������ͱ���
} UDGraph, * PUDGraph;                   //������Undirected Graph

//���Ҷ�����±�
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

//����������
void createUDG(PUDGraph G)
{
    //���붥�����ͱ���
    printf("���붥�����ͱ���");
    scanf("%d %d", &G->vexNum, &G->arcNum);

    //����ÿ�������Ϣ
    for (int i = 0; i < G->vexNum; i++)
    {
        scanf("%c", &G->vexs[i]);
    }

    //��ʼ���ڽӾ���,ÿ����ֵ����ֵ(����)
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            G->arcs[i][j] = maxInt;
        }
    }

    //�����ڽӾ���
    for (int k = 0; k < G->arcNum; k++)
    {
        int v1, v2, weight;
        //����һ���ߵ����������ֵ�ͱߵ�Ȩֵ
        scanf("%d %d %d", &v1, &v2, &weight);
        int i = locateVex(*G, v1);
        int j = locateVex(*G, v2);
        G->arcs[i][j] = weight;
        //������ǶԳƵ�
        G->arcs[j][i] = G->arcs[i][j];
    }
    return;
}