#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode//声明节点的类型和指向节点的指针
{
    int data;           //节点的数据域
    struct LNode* Next; //指针，节点的指针域
    //指向struct Node这个节点的指针，嵌套定义 
} LNODE, * LinkList; //都是类型 LNODE a;a.date/a.next       
//NODE等价于struct LNode，链表当中的节点    
//LinkList等价于struct LNode *，指向这个结构体的一个指针类型 
//LNODE *L==LinkList L;
 
//创建链表
LinkList create_list()
{
    int len; //用来存放有效节点的个数
    int val; //用来临时存放用户输入的结点的值

    //分配了一个不存放有效数据的头结点
    LinkList L = (LinkList)malloc(sizeof(LNODE));
    if (NULL == L)
    {
        printf("分配失败, 程序终止!\n");
        exit(-1);
    }

    // 定义一个临时结构体指针指向最后一个结点
    /*LinkList pTail = L;
    pTail->pNext = NULL;*/
    L->Next == NULL;
    printf("请输入您需要生成的链表节点的个数: len = ");
    scanf("%d", &len);
    for (int i = 0; i < len; ++i)
    {
        printf("请输入第%d个节点的值: ", i + 1);
        scanf("%d", &val);

        //新结点
        LinkList pNew = (LinkList)malloc(sizeof(LNODE));
        if (NULL == pNew)
        {
            printf("分配失败, 程序终止!\n");
            exit(-1);
        }
        pNew->data = val;
        pNew->Next = NULL;
        // 将之前的最后一个结点指向新结点
        L->Next = pNew;
        //再将pTail指向新的最后一个结点
        L = pNew;
    }
    return L;
}

//头插法创建链表(每一个新结点插入到上一个结点的前面)
LinkList create_list_head()
{
    int len; //用来存放有效节点的个数
    int val; //用来临时存放用户输入的结点的值

    //分配了一个不存放有效数据的头结点
    LinkList L = (LinkList)malloc(sizeof(LNODE));
    if (NULL == L)
    {
        printf("分配失败, 程序终止!\n");
        exit(-1);
    }
    L->Next = NULL;
    printf("请输入您需要生成的链表节点的个数: len = ");
    scanf("%d", &len);
    for (int i = len; i > 0; i--)
    {
        //新结点
        LinkList pNew = (LinkList)malloc(sizeof(LNODE));
        if (NULL == pNew)
        {
            printf("分配失败, 程序终止!\n");
            exit(-1);
        }
        printf("请输入第%d个节点的值: ", i);
        scanf("%d", &val);
        pNew->data = val;
        //pHead->pNext就是上一个结点的地址
        pNew->Next = L->Next;
        L->Next = pNew;
    }
    return L;    
}


//遍历链表
void traverse_list(LinkList L)
{
    //获取第一个结点的地址
    LinkList p = L->Next;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        //将结点的指针域(下一个结点的地址)赋值给p
        p = p->Next;
    }
    printf("\n");
}

//判断链表是否为空
bool is_empty(LinkList L)
{
    if (L->Next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//求链表长度
int length_list(LinkList L)
{

    LinkList p;
    p = L->Next;
    int i = 0; 
    while (p != NULL)
    {
        i++;
        p = p->Next;
    }
    return i;
}

//排序
void sort_list(LinkList pHead)
{
    int i, j, t;
    int len = length_list(pHead);
    int arr[] = { 5, 10, 1, 4, 2 };
    LinkList q, p;
    for (i = 0, q = pHead->Next; i < len - 1; i++, q = q->Next)
    {
        for (j = i + 1, p = q->Next; j < len; j++, p = p->Next)
        {

            if (q->data > p->data) //arr[i] > arr[j]
            {
                t = q->data;       //t = arr[i];
                q->data = p->data; //arr[i] = arr[j];
                p->data = t;       //arr[j] = t;
            }
        }
    }
    return;
}

//在L所指向链表的第i个节点的前面插入一个新的结点，
// 该节点的值是e， 并且j的值是从1开始
bool insert_list(LinkList L, int i, int e)
{
    int j = 0;
    LinkList p = L;
    while (NULL != p && j < i - 1)
    {//寻找第i-1个节点，p指向i-1节点
        p = p->Next;
        ++j;
    }

    if (j > i - 1 || NULL == p) //大于表长或者小于1都不可以
        return false;

    //分配了一个不存放有效数据的新结点
    LinkList pNew = (LinkList)malloc(sizeof(LNODE));
    if (NULL == pNew)
    {
        printf("分配失败, 程序终止!\n");
        exit(-1);
    }
    pNew->data = e;
    pNew->Next = p->Next;
    p->Next = pNew;
    //不可倒序
   // printf("插入结果");
    return true;
}

//***为什么插入是循环是p，删除是p->pNext？
//***因为插入i可以加到最后的元素位置， 删除的i必须在倒数第二停住

//删除
bool delete_list(LinkList L, int i)
{
    int j = 0;
    LinkList p = L;

    while (NULL != p->Next && j < i - 1)
    {
        ++j;
        p = p->Next;
    }

    if (j > i - 1 || NULL == p->Next)
        return false;

    //如果程序能执行到这一行说明p已经指向了第pos-1个结点，并且第pos个节点是存在的
    LinkList q = p->Next;
    p->Next = p->Next->Next;
    //释放q所指向的节点所占的内存
    free(q);
    //变量的值清空
    q = NULL;
    printf("删除结果\n");
    return true;
}
    
//取第i个元素的值
int getElem(LinkList L, int i)
{
    int j = 1; //定义一个计数器
    LinkList p;
    p = L->Next;
    //p不为空且j还有等于i的时候
    //(如果就是第一个元素那么直接调过循环)
    while (p && j < i)
    {
        j++;
        p = p->Next;
    }

    if (p == NULL || j > i)
    {
        return -1;
    }

    return p->data;  
}

//按值查找,并返回所在的位置
int locate(LinkList L, int e)
{
    int i = 1;
    LinkList p = L->Next;
    while (p && p->data != e)
    {
        i++;
        p = p->Next;
    }
    if (p)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

//销毁(包括头结点)
void destoryList(LinkList L)
{
    LinkList p;//或Londe *p;
    while (L)//或while（L！=NULL）
    {
        //先移动头指针的指向，再去用释放p所对应的空间
        p = L;
        L = L->Next;
        free(p);
       // p = NULL;
    }
}

//清空
// 链表仍然存在将其置空(头结点和头指针仍然存在)
void cleanList(LinkList L)
{
    LinkList p, q; //p用来存储上一个结点，q用来移动指针
    //先移动在释放
    p = L->Next;
    while (p)
    {
        q = p->Next;
        free(p);
        p = NULL;
        p = q;
    }
    //pHead的指针域要清空
    L->Next = NULL;
}

int main(void)
{
    LinkList pHead = NULL;
    //create_list()功能：创建一个非循环单链表，并将该链表的头结点的地址付给pHead
    pHead = create_list_head();
    //循环遍历
    traverse_list(pHead);
    //判断是否为空
    if (is_empty(pHead))
        printf("链表为空!\n");
    else
        printf("链表不空!\n");
    //链接长度
    int len = length_list(pHead);
    printf("链表的长度是%d\n", len);
    //链表排序
    sort_list(pHead);
    //循环遍历
    traverse_list(pHead);
    //插入
    // insert_list(pHead, 2, 33);
    //删除
    delete_list(pHead, 3);
    //循环遍历
    traverse_list(pHead);

    return 0;
}