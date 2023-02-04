#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Table
{
	int* head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
	int length;//��¼��ǰ˳���ĳ���
}TABLE, * PTABLE;

//��ʼ��
void initTable(PTABLE t)
{
	t->head = (int*)malloc(sizeof(int) * SIZE);
	//�������ʧ�ܣ�������ʾ��ֱ���˳�����
	if (t->head == NULL)
	{
		printf("��ʼ��ʧ��");
		exit(0);
	}
	t->length = 0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
}

//����
void displayTable(PTABLE t)
{
	for (int i = 0; i < t->length; i++)
	{
		printf("%d ", t->head[i]);
	}
}

//���뺯�������У�elemΪ�����Ԫ�أ�addΪ���뵽˳����λ��
void addTable(PTABLE t, int elem, int add)
{
	//�жϲ��뱾���Ƿ��������(
	//�������Ԫ��λ�ñ����ű�ĳ��� + 1����
	//(�����ȣ���β������)
	//���߲����λ�ñ������ڣ�������Ϊ��ʾ���Զ��˳�)
	if (add > t->length || add < 1)
	{
		printf("����λ��������");
		exit(0);
	}
	//�����������Ҫ�Ӳ���λ�ÿ�ʼ�ĺ���Ԫ�أ��������
	for (int i = t->length - 1; i >= add - 1; i--)
	{
		t->head[i + 1] = t->head[i];
	}
	//������ɺ�ֱ�Ӽ��������Ԫ�أ�����˳������Ӧλ��
	t->head[add - 1] = elem;
	//���������Ԫ�أ����Գ��ȼ�һ
	t->length++;
}

//ɾ��ָ��λ��
void delTable(PTABLE t, int add)
{
	if (add > t->length || add < 1)
	{
		printf("��ɾ��Ԫ�ص�λ������");
		exit(0);
	}
	//��Ҫ�ú���İ�Ҫɾ����λ�ø���
	for (int i = add; i < t->length; i++)
	{
		t->head[i - 1] = t->head[i];
	}
	t->length--; 
}

//���Һ��������У�elem��ʾҪ���ҵ�����Ԫ�ص�ֵ
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

//����
void destoryLst(PTABLE t)
{
	if (t->head != NULL)
	{
		free(t->head);
	}
	t->head = NULL;
	printf("�ͷŶ�̬�ڴ�����\n");
}

void ClearList(PTABLE t)
{
	t->length = 0;
}

//˳����п�
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

//��ȡ˳���ĳ���
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
	printf("˳����д����Ԫ�طֱ��ǣ�\n");
	displayTable(&t);
	printf("\nɾ����\n");
	delTable(&t, 5);
	displayTable(&t);
	int ret = searchTable(&t, 4);
	printf("\n���ҽ��Ϊ��%d", ret);

	return 0;
}