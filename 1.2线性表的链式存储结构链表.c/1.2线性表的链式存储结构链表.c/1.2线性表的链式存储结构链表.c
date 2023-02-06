#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode//�����ڵ�����ͺ�ָ��ڵ��ָ��
{
    int data;           //�ڵ��������
    struct LNode* Next; //ָ�룬�ڵ��ָ����
    //ָ��struct Node����ڵ��ָ�룬Ƕ�׶��� 
} LNODE, * LinkList; //�������� LNODE a;a.date/a.next       
//NODE�ȼ���struct LNode�������еĽڵ�    
//LinkList�ȼ���struct LNode *��ָ������ṹ���һ��ָ������ 
//LNODE *L==LinkList L;
 
//��������
LinkList create_list()
{
    int len; //���������Ч�ڵ�ĸ���
    int val; //������ʱ����û�����Ľ���ֵ

    //������һ���������Ч���ݵ�ͷ���
    LinkList L = (LinkList)malloc(sizeof(LNODE));
    if (NULL == L)
    {
        printf("����ʧ��, ������ֹ!\n");
        exit(-1);
    }

    // ����һ����ʱ�ṹ��ָ��ָ�����һ�����
    /*LinkList pTail = L;
    pTail->pNext = NULL;*/
    L->Next == NULL;
    printf("����������Ҫ���ɵ�����ڵ�ĸ���: len = ");
    scanf("%d", &len);
    for (int i = 0; i < len; ++i)
    {
        printf("�������%d���ڵ��ֵ: ", i + 1);
        scanf("%d", &val);

        //�½��
        LinkList pNew = (LinkList)malloc(sizeof(LNODE));
        if (NULL == pNew)
        {
            printf("����ʧ��, ������ֹ!\n");
            exit(-1);
        }
        pNew->data = val;
        pNew->Next = NULL;
        // ��֮ǰ�����һ�����ָ���½��
        L->Next = pNew;
        //�ٽ�pTailָ���µ����һ�����
        L = pNew;
    }
    return L;
}

//ͷ�巨��������(ÿһ���½����뵽��һ������ǰ��)
LinkList create_list_head()
{
    int len; //���������Ч�ڵ�ĸ���
    int val; //������ʱ����û�����Ľ���ֵ

    //������һ���������Ч���ݵ�ͷ���
    LinkList L = (LinkList)malloc(sizeof(LNODE));
    if (NULL == L)
    {
        printf("����ʧ��, ������ֹ!\n");
        exit(-1);
    }
    L->Next = NULL;
    printf("����������Ҫ���ɵ�����ڵ�ĸ���: len = ");
    scanf("%d", &len);
    for (int i = len; i > 0; i--)
    {
        //�½��
        LinkList pNew = (LinkList)malloc(sizeof(LNODE));
        if (NULL == pNew)
        {
            printf("����ʧ��, ������ֹ!\n");
            exit(-1);
        }
        printf("�������%d���ڵ��ֵ: ", i);
        scanf("%d", &val);
        pNew->data = val;
        //pHead->pNext������һ�����ĵ�ַ
        pNew->Next = L->Next;
        L->Next = pNew;
    }
    return L;    
}


//��������
void traverse_list(LinkList L)
{
    //��ȡ��һ�����ĵ�ַ
    LinkList p = L->Next;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        //������ָ����(��һ�����ĵ�ַ)��ֵ��p
        p = p->Next;
    }
    printf("\n");
}

//�ж������Ƿ�Ϊ��
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

//��������
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

//����
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

//��L��ָ������ĵ�i���ڵ��ǰ�����һ���µĽ�㣬
// �ýڵ��ֵ��e�� ����j��ֵ�Ǵ�1��ʼ
bool insert_list(LinkList L, int i, int e)
{
    int j = 0;
    LinkList p = L;
    while (NULL != p && j < i - 1)
    {//Ѱ�ҵ�i-1���ڵ㣬pָ��i-1�ڵ�
        p = p->Next;
        ++j;
    }

    if (j > i - 1 || NULL == p) //���ڱ�����С��1��������
        return false;

    //������һ���������Ч���ݵ��½��
    LinkList pNew = (LinkList)malloc(sizeof(LNODE));
    if (NULL == pNew)
    {
        printf("����ʧ��, ������ֹ!\n");
        exit(-1);
    }
    pNew->data = e;
    pNew->Next = p->Next;
    p->Next = pNew;
    //���ɵ���
   // printf("������");
    return true;
}

//***Ϊʲô������ѭ����p��ɾ����p->pNext��
//***��Ϊ����i���Լӵ�����Ԫ��λ�ã� ɾ����i�����ڵ����ڶ�ͣס

//ɾ��
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

    //���������ִ�е���һ��˵��p�Ѿ�ָ���˵�pos-1����㣬���ҵ�pos���ڵ��Ǵ��ڵ�
    LinkList q = p->Next;
    p->Next = p->Next->Next;
    //�ͷ�q��ָ��Ľڵ���ռ���ڴ�
    free(q);
    //������ֵ���
    q = NULL;
    printf("ɾ�����\n");
    return true;
}
    
//ȡ��i��Ԫ�ص�ֵ
int getElem(LinkList L, int i)
{
    int j = 1; //����һ��������
    LinkList p;
    p = L->Next;
    //p��Ϊ����j���е���i��ʱ��
    //(������ǵ�һ��Ԫ����ôֱ�ӵ���ѭ��)
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

//��ֵ����,���������ڵ�λ��
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

//����(����ͷ���)
void destoryList(LinkList L)
{
    LinkList p;//��Londe *p;
    while (L)//��while��L��=NULL��
    {
        //���ƶ�ͷָ���ָ����ȥ���ͷ�p����Ӧ�Ŀռ�
        p = L;
        L = L->Next;
        free(p);
       // p = NULL;
    }
}

//���
// ������Ȼ���ڽ����ÿ�(ͷ����ͷָ����Ȼ����)
void cleanList(LinkList L)
{
    LinkList p, q; //p�����洢��һ����㣬q�����ƶ�ָ��
    //���ƶ����ͷ�
    p = L->Next;
    while (p)
    {
        q = p->Next;
        free(p);
        p = NULL;
        p = q;
    }
    //pHead��ָ����Ҫ���
    L->Next = NULL;
}

int main(void)
{
    LinkList pHead = NULL;
    //create_list()���ܣ�����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
    pHead = create_list_head();
    //ѭ������
    traverse_list(pHead);
    //�ж��Ƿ�Ϊ��
    if (is_empty(pHead))
        printf("����Ϊ��!\n");
    else
        printf("������!\n");
    //���ӳ���
    int len = length_list(pHead);
    printf("����ĳ�����%d\n", len);
    //��������
    sort_list(pHead);
    //ѭ������
    traverse_list(pHead);
    //����
    // insert_list(pHead, 2, 33);
    //ɾ��
    delete_list(pHead, 3);
    //ѭ������
    traverse_list(pHead);

    return 0;
}