#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

// //ջ��˳��洢
//typedef struct
//{
//    int data[MAXSIZE];
//    int top;
//} stack;

//��ջ�ı�ʾ
//typedef struct StackNode
//{
//	int data;
//	struct StackNode* next;
//}StackNode,*LinkStack;
//LinkStack S;
////��ʼ��ջ
//LinkStack InitStack(LinkStack S)
//{
//	S = NULL;
//	return S;
//}
//
////�ж�ջ�Ƿ�Ϊ��
//bool StackEmpty(LinkStack S)
//{
//    if (S == NULL) 
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

////�ж�ջ�Ƿ���
//bool StackFull(STACK* S)
//{
//    if (S->top == MAXSIZE - 1)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

//��ջ
//bool Push(StackNode* S, int x)
//{
//    if (StackFull(S))
//    {
//        printf("ջ�������޷���ջ\n");
//        return false;
//    }
//    else
//    {
//        S->top++;
//        S->data[S->top] = x;
//        return true;
//    }
//}

////��ջ
//bool Pop(STACK* S, int* x)
//{
//    if (StackEmpty(S))
//    {
//        printf("ջΪ�գ��޷���ջ\n");
//        return false;
//    }
//    else
//    {
//        *x = S->data[S->top];
//        S->top--;
//        return true;
//    }
//}
//
////�鿴ջ��Ԫ��
//bool GetTop(STACK* S, int* x)
//{
//    if (StackEmpty(S))
//    {
//        printf("ջΪ�գ��޷��鿴ջ��Ԫ��\n");
//        return false;
//    }
//    else
//    {
//        *x = S->data[S->top];
//        return true;
//    }
//}
//
////����
//void Traverse(STACK* S)
//{
//    int i;
//    if (StackEmpty(S))
//    {
//        printf("ջΪ�գ��޷�����\n");
//    }
//    else
//    {
//        for (i = S->top; i >= 0; i--)
//        {
//            printf("%d ", S->data[i]);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int e;
//    STACK s;
//    InitStack(&s);
//    Push(&s, 15);
//    Push(&s, 20);
//    Traverse(&s);
//    printf("\n");
//    Pop(&s, &e);
//    printf("��ջԪ��%d\n", e);
//    Traverse(&s);
//}
//˳��ջ
////// typedef struct stack
////// {
//////     int *top;       /* ջ��ָ�� */
//////     int *base;//botoom    /* ջ��ָ�� */
//////     int stacksize; /* ջ��������� */
////// } SqStack;//STACK, *PSTACK;
//////
////// //��ʼ��
//////SqStack initStack(SqStack S)
////// {
//////    S.base = (int*)malloc(sizeof(int) * MAXSIZE);
//////    if (S.base == NULL)
//////     {
//////         printf("��ʼ��ʧ��");
//////         exit(0);
//////     }
//////     S.top = S.base;
//////     S.stacksize = MAXSIZE;
//////     return S;
////// }
//////
////// //��ջ
////// SqStack push(SqStack s, int data)
////// {
//////     if (s.top - s.base == s.stacksize)
//////     {
//////         printf("ջ�ռ��������޷���ջ");
//////         return s;
//////     }
//////     *s.top = data;
//////     s.top++;
//////     return s;
////// }
//////
////// //��ջ
////// SqStack pop(SqStack s, int *e)
////// {
//////
//////     if (s.top == s.base)
//////     {
//////         printf("ջ�գ��޷���ջ");
//////         return s;
//////     }
//////     s.top--;
//////     *e = *s.top;
//////     return s;
//////}

// //����
// void traverse(STACK s)
// {
//     if (s.top - s.bottom == s.stack_size)
//     {
//         printf("ջΪ��ջ���޷�����\n");
//         return;
//     }
//     while (s.top != s.bottom)
//     {
//         s.top--;
//         printf("%d ", *s.top);
//     }
// }

// /* �ж�ջ�Ƿ�Ϊ�� */
// int StackFull(STACK s)
// {
//     if (s.top - s.bottom == s.stack_size)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
// }

////// /* �ж�ջ�Ƿ�Ϊ�� */
////// int StackEmpty(SqStack s)
////// {
//////     if (s.top == s.base )
//////     {
//////         return 0;
//////     }
//////     else
//////     {
//////         return 1;
//////     }
////// }
//////
////// //��˳��ջ�ĳ���
//////int  StackEmpty(SqStack s)
////// {
//////     return s.top - s.base;
////// }
//////
////// //���˳��ջ
////// SqStack clearstack(SqStack s)
////// {
//////     if (s.base)
//////     {
//////         s.top = s.base;
//////     }
//////     return s;
////// }
//////
////// //����˳��ջ
////// SqStack destroyStack(SqStack s)
////// {
//////     if (s.base)
//////     {
//////         free(s.base);
//////         s.stacksize = 0;
//////         s.base = s.top = NULL;
//////     }
//////     return s;
////// }
// int main()
// {
//     int e;
//     STACK s;
//     s = init(s);
//     s = push(s, 15);
//     s = push(s, 20);
//     traverse(s);
//     printf("\n");
//     s = pop(s, &e);
//     printf("��ջԪ��%d\n", e);
//     traverse(s);
// }