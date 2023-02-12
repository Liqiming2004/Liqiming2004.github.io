#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    char data;
    // L是左  child是孩子
    struct BTNode* pLchild;
    struct BTNode* pRchild;

} BTNode, * PBTNode;

// 创建一个树
PBTNode CreateBTree();
//先序遍历
void PreTraverseBTree(PBTNode pT);
//中序
void InTraverseBTree(PBTNode pT);
//后序
void PostTraverseBTree(PBTNode pT);

int main()
{
    PBTNode pT = CreateBTree();
    PreTraverseBTree(pT);
    printf("\n");
    InTraverseBTree(pT);
    printf("\n");
    PostTraverseBTree(pT);
    printf("\n");
    return 0;
}

// 创建一个树
PBTNode CreateBTree()
{
    PBTNode pA = (PBTNode)malloc(sizeof(BTNode));
    PBTNode pB = (PBTNode)malloc(sizeof(BTNode));
    PBTNode pC = (PBTNode)malloc(sizeof(BTNode));
    PBTNode pD = (PBTNode)malloc(sizeof(BTNode));
    PBTNode pE = (PBTNode)malloc(sizeof(BTNode));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';

    //没有值的指针域给null
    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pE->pRchild = NULL;

    return pA;
}

//先序遍历
void PreTraverseBTree(PBTNode pT)
{
    if (pT != NULL)
    {
        printf("%c", pT->data);
        PreTraverseBTree(pT->pLchild);
        PreTraverseBTree(pT->pRchild);
    }
}
//中序遍历
void InTraverseBTree(PBTNode pT)
{
    if (pT != NULL)
    {
        PreTraverseBTree(pT->pLchild);
        printf("%c", pT->data);
        PreTraverseBTree(pT->pRchild);
    }
}

//后序遍历
void PostTraverseBTree(PBTNode pT)
{
    if (pT != NULL)
    {
        PreTraverseBTree(pT->pLchild);
        PreTraverseBTree(pT->pRchild);
        printf("%c", pT->data);
    }
}
