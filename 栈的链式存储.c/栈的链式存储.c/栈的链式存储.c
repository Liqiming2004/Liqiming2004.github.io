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
////��ʼ��һ��ջ
//void init(PSTACK pS)
//{
//    //����һ���൱��ͷ���Ľ��
//    pS->pTop = (PNODE)malloc(sizeof(NODE));
//    if (NULL == pS->pTop)
//    {
//        printf("��̬�ڴ����ʧ��!\n");
//        exit(-1);
//    }
//    else
//    {
//        pS->pBottom = pS->pTop;
//        pS->pTop->pNext = NULL;
//    }
//}

//��ջ�ı�ʾ
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;
LinkStack S;

//��ʼ��ջ
LinkStack InitStack(LinkStack S)
{
	S = NULL;
	return S;
}

//��ջ
void push(LinkStack S, int e)
{
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S;
    S = p;
    return S;
}

//��ջ
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

//����
void traverse(LinkStack pS)
{
    //��ΪpTop���ܶ������ƻ�ջ�Ľṹ
    LinkStack p = S;
    while (p != S)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

//�ж��Ƿ�Ϊ��
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

//��pS��ָ���ջ��ջһ�Σ����ѳ�ջ��Ԫ�ش���pVal�β�
// ��ָ��ı����У������ջʧ�ܣ�����false,���򷵻�true
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

//clear���
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
            printf("���");
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
        printf("��ջ�ɹ�����ջ��Ԫ����%d\n", val);
    }
    else
    {
        printf("��ջʧ��!\n");
    }
    printf("���\n");
    clear(&s);
    traverse(&s);
    if (empty(&s))
    {
        printf("�����");
    }
}