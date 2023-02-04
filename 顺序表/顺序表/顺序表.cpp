#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Table
{
	int* head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
	int length;//记录当前顺序表的长度
}TABLE, * PTABLE;

//初始化
void initTable(PTABLE t)
{
	t->head = (int*)malloc(sizeof(int) * SIZE);
	//如果申请失败，作出提示并直接退出程序
	if (t->head == NULL)
	{
		printf("初始化失败");
		exit(0);
	}
	t->length = 0;//空表的长度初始化为0
}

//遍历
void displayTable(PTABLE t)
{
	for (int i = 0; i < t->length; i++)
	{
		printf("%d ", t->head[i]);
	}
}

//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置
void addTable(PTABLE t, int elem, int add)
{
	//判断插入本身是否存在问题(
	//如果插入元素位置比整张表的长度 + 1还大
	//(如果相等，是尾随的情况)
	//或者插入的位置本身不存在，程序作为提示并自动退出)
	if (add > t->length || add < 1)
	{
		printf("插入位置有问题");
		exit(0);
	}
	//插入操作，需要从插入位置开始的后续元素，逐个后移
	for (int i = t->length - 1; i >= add - 1; i--)
	{
		t->head[i + 1] = t->head[i];
	}
	//后移完成后，直接减所需插入元素，田间道顺序表的相应位置
	t->head[add - 1] = elem;
	//由于添加了元素，所以长度加一
	t->length++;
}

//删除指定位置
void delTable(PTABLE t, int add)
{
	if (add > t->length || add < 1)
	{
		printf("被删除元素的位置有误");
		exit(0);
	}
	//需要用后面的吧要删除的位置覆盖
	for (int i = add; i < t->length; i++)
	{
		t->head[i - 1] = t->head[i];
	}
	t->length--; 
}

//查找函数，其中，elem表示要查找的数据元素的值
int searchTable(PTABLE t, int elem)
{
	for (int i = 0; i < t->length; i++)
	{
		if (t->head[i] = elem)
		{
			return i + 1;
		}
		return -1;
	}
}

//销毁
void destoryLst(PTABLE t)
{
	if (t->head != NULL)
	{
		free(t->head);
	}
	t->head = NULL;
	printf("释放动态内存数组\n");
}

void ClearList(PTABLE t)
{
	t->length = 0;
}

//顺序表判空
int ListEmpty(PTABLE t)
{
	if (t->length = 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//获取顺序表的长度
int GetLen(PTABLE t)
{
	return t->length;
}

int main()
{
	TABLE t;
	initTable(&t);
	int i = 0;
	for (i = 0; i < SIZE; i++);
	{
		t.head[i] = i + 1;
		t.length++;
	}
	addTable(&t, 8, 5);
	printf("顺序表中储存的元素分别是：\n");
	displayTable(&t);
	printf("\n删除后：\n");
	delTable(&t, 5);
	displayTable(&t);
	int ret = searchTable(&t, 4);
	printf("\n查找结果为：%d", ret);

	return 0;
}