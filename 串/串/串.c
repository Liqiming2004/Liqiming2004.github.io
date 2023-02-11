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

//初始化
void StrAssign(SqString* str, char cstr[])
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
        str->data[i] = cstr[i];
    // str->len = i;
    str->length = strlen(cstr);
}

//输出
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

//bf算法
int index_BF(SqString* S, SqString* T, int pos)
{
    //返回子串t在主串s中第一次出现的位置，若不存在则返回0
    int i = pos;
    int j = 1;
    //i <= S->len表示到整个主串比较完都没找到，
    //j <= T->len表示子串还没完全匹配上
    while (i <= S->length && j <= T->length)
    {
        if (S->data[i] == T->data[j])
        {
            //进行下一个字符的比较
            i++;
            j++;
        }
        else
        {
            //j回到第一个字符的位置
            j = 1;
            //i回到上一次开始比较位置+1
            i = i - j + 2;
        }
    }
    //此时是匹配到相等的时候
    if (j >= T->length)
    {
        //返回位置
        return i - T->length;
    }
    else
    {
        printf("没找到\n");
        return 0;
    }
}

int main()
{
    SqString s, s1;
    printf("建立串s和s1\n");
    StrAssign(&s, "abcdefghijklmn");
    StrAssign(&s1, "abc");
    printf("建立串s和s1\n");
    printf("输出串s\n");
    DispStr(s);
    printf("输出串s1\n");
    DispStr(s1);
    int ret = index_BF(&s, &s1, 0);
    printf("bf算法:%d", ret);
}