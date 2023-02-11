#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 255

typedef struct
{
    char data[MAXLEN+1];
    int length;//len
} SqString;

//��ʼ��
void StrAssign(SqString* str, char cstr[])
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
        str->data[i] = cstr[i];
    // str->len = i;
    str->length = strlen(cstr);
}

//���
void DispStr(SqString s)
{
    int i;
    if (s.length > 0)
    {
        for (i = 0; i < s.length; i++)
            printf("%c", s.data[i]);
        printf("\n");
    }
}

//bf�㷨
int index_BF(SqString* S, SqString* T, int pos)
{
    //�����Ӵ�t������s�е�һ�γ��ֵ�λ�ã����������򷵻�0
    int i = pos;
    int j = 1;
    //i <= S->len��ʾ�����������Ƚ��궼û�ҵ���
    //j <= T->len��ʾ�Ӵ���û��ȫƥ����
    while (i <= S->length && j <= T->length)
    {
        if (S->data[i] == T->data[j])
        {
            //������һ���ַ��ıȽ�
            i++;
            j++;
        }
        else
        {
            //j�ص���һ���ַ���λ��
            j = 1;
            //i�ص���һ�ο�ʼ�Ƚ�λ��+1
            i = i - j + 2;
        }
    }
    //��ʱ��ƥ�䵽��ȵ�ʱ��
    if (j >= T->length)
    {
        //����λ��
        return i - T->length;
    }
    else
    {
        printf("û�ҵ�\n");
        return 0;
    }
}

int main()
{
    SqString s, s1;
    printf("������s��s1\n");
    StrAssign(&s, "abcdefghijklmn");
    StrAssign(&s1, "abc");
    printf("������s��s1\n");
    printf("�����s\n");
    DispStr(s);
    printf("�����s1\n");
    DispStr(s1);
    int ret = index_BF(&s, &s1, 0);
    printf("bf�㷨:%d", ret);
}