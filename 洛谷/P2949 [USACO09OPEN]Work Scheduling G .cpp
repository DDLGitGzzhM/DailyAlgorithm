#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Ackmann(int i, int j)
{
	if (j > 0 && i == 0)
		return  Ackmann(j, 1);
	if(j>0 && i>0)
		return  Ackmann(j-1, Ackmann(j, i-1));
	if (j == 0)
		return i + 1;
}

int main()
{
	int n = 0, m = 0;
	int ret = 0;
	scanf("%d %d", &n, &m);
	ret=Ackmann(n, m);
	printf("%d", ret);
	return 0;
}
