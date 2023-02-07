#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

// //栈的顺序存储
//typedef struct
//{
//    int data[MAXSIZE];
//    int top;
//} stack;

//链栈的表示
//typedef struct StackNode
//{
//	int data;
//	struct StackNode* next;
//}StackNode,*LinkStack;
//LinkStack S;
////初始化栈
//LinkStack InitStack(LinkStack S)
//{
//	S = NULL;
//	return S;
//}
//
////判断栈是否为空
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

////判断栈是否满
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

//入栈
//bool Push(StackNode* S, int x)
//{
//    if (StackFull(S))
//    {
//        printf("栈已满，无法入栈\n");
//        return false;
//    }
//    else
//    {
//        S->top++;
//        S->data[S->top] = x;
//        return true;
//    }
//}

////出栈
//bool Pop(STACK* S, int* x)
//{
//    if (StackEmpty(S))
//    {
//        printf("栈为空，无法出栈\n");
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
////查看栈顶元素
//bool GetTop(STACK* S, int* x)
//{
//    if (StackEmpty(S))
//    {
//        printf("栈为空，无法查看栈顶元素\n");
//        return false;
//    }
//    else
//    {
//        *x = S->data[S->top];
//        return true;
//    }
//}
//
////遍历
//void Traverse(STACK* S)
//{
//    int i;
//    if (StackEmpty(S))
//    {
//        printf("栈为空，无法遍历\n");
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
//    printf("出栈元素%d\n", e);
//    Traverse(&s);
//}
//顺序栈
////// typedef struct stack
////// {
//////     int *top;       /* 栈顶指针 */
//////     int *base;//botoom    /* 栈底指针 */
//////     int stacksize; /* 栈的最大容量 */
////// } SqStack;//STACK, *PSTACK;
//////
////// //初始化
//////SqStack initStack(SqStack S)
////// {
//////    S.base = (int*)malloc(sizeof(int) * MAXSIZE);
//////    if (S.base == NULL)
//////     {
//////         printf("初始化失败");
//////         exit(0);
//////     }
//////     S.top = S.base;
//////     S.stacksize = MAXSIZE;
//////     return S;
////// }
//////
////// //入栈
////// SqStack push(SqStack s, int data)
////// {
//////     if (s.top - s.base == s.stacksize)
//////     {
//////         printf("栈空间已满，无法入栈");
//////         return s;
//////     }
//////     *s.top = data;
//////     s.top++;
//////     return s;
////// }
//////
////// //出栈
////// SqStack pop(SqStack s, int *e)
////// {
//////
//////     if (s.top == s.base)
//////     {
//////         printf("栈空，无法出栈");
//////         return s;
//////     }
//////     s.top--;
//////     *e = *s.top;
//////     return s;
//////}

// //遍历
// void traverse(STACK s)
// {
//     if (s.top - s.bottom == s.stack_size)
//     {
//         printf("栈为空栈，无法遍历\n");
//         return;
//     }
//     while (s.top != s.bottom)
//     {
//         s.top--;
//         printf("%d ", *s.top);
//     }
// }

// /* 判断栈是否为满 */
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

////// /* 判断栈是否为空 */
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
////// //求顺序栈的长度
//////int  StackEmpty(SqStack s)
////// {
//////     return s.top - s.base;
////// }
//////
////// //清空顺序栈
////// SqStack clearstack(SqStack s)
////// {
//////     if (s.base)
//////     {
//////         s.top = s.base;
//////     }
//////     return s;
////// }
//////
////// //销毁顺序栈
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
//     printf("出栈元素%d\n", e);
//     traverse(s);
// }