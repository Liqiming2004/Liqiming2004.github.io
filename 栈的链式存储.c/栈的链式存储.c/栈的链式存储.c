#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//typedef struct Node
//{
//    int data;
//    struct Node* pNext;
//} NODE, * PNODE;
//
//typedef struct Stack
//{
//    PNODE pTop;
//    PNODE pBottom;
//} STACK, * PSTACK;
//
////初始化一个栈
//void init(PSTACK pS)
//{
//    //创建一个相当于头结点的结点
//    pS->pTop = (PNODE)malloc(sizeof(NODE));
//    if (NULL == pS->pTop)
//    {
//        printf("动态内存分配失败!\n");
//        exit(-1);
//    }
//    else
//    {
//        pS->pBottom = pS->pTop;
//        pS->pTop->pNext = NULL;
//    }
//}

//链栈的表示
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;
LinkStack S;

//初始化栈
LinkStack InitStack(LinkStack S)
{
	S = NULL;
	return S;
}

//进栈
void push(LinkStack S, int e)
{
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return S;
}

//出栈
void pop(LinkStack s, int e)
{
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    if (s == NULL)
    {
        printf("ERRROR");
        return -1;
    }
    else
    {
        e = s->data;
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}

//遍历
void traverse(LinkStack pS)
{
    //因为pTop不能动，会破坏栈的结构
    LinkStack p = S;
    while (p != S)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

//判断是否为空
bool empty(LinkStack pS)
{
    if (pS->pBottom == pS->pTop)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参
// 所指向的变量中，如果出栈失败，返回false,否则返回true
bool pop(LinkStack pS, int* pVal)
{
    if (empty(pS))
    {
        return false;
    }
    else
    {
        PNODE p = pS->pTop;
        *pVal = p->data;
        pS->pTop = p->pNext;
        free(p);
        p = NULL;
        return true;
    }
    {
        return false;
    }
}

//clear清空
void clear(PSTACK pS)
{
    if (empty(pS))
    {
        return;
    }
    else
    {

        LinkStack p = pS->pTop;
        while (pS->pTop != pS->pBottom)
        {
            p = pS->pTop;

            pS->pTop = p->pNext;
            free(p);
            p = NULL;
        }
        // pS->pTop = pS->pBottom;
        if (pS->pTop == pS->pBottom)
        {
            printf("相等");
        }
        return;
    }
}

int main()
{
    int val;
    STACK s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    traverse(&s);

    if (pop(&s, &val))
    {
        printf("出栈成功，出栈的元素是%d\n", val);
    }
    else
    {
        printf("出栈失败!\n");
    }
    printf("清空\n");
    clear(&s);
    traverse(&s);
    if (empty(&s))
    {
        printf("清空了");
    }
}