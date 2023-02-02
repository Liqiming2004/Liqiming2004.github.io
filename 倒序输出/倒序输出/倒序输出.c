#define  _CRT_SECURE_NO_WARNINGS 1
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	//for (i = 0; i < 5; i++)
	//{
	//	int t;
	//	t = a[i];
	//	a[i] = a[9 - i];
	//	a[9 - i] = t;
	//}
	int b[10];
	for (i = 0; i < 10; i++)
	{
		b[i] = a[9 - i];
	}
	for (i = 0; i < 10; i++)
	{
		a[i] = b[i];
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
