#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
	int M;
	int K;
	int monky[1001];
	printf("输入M\n");
	scanf("%d", &M);
	printf("输入K\n");
	scanf("%d", &K);
	int restnum = M;
	int ind0=0;//全部初始化为0
	for (ind0 = 0; ind0 <= 1001; ind0++)
	{
		monky[ind0] = 0;
	}
	
	int ind1=1;//空出第一个并把M个格子初始化为1 
	while (ind1 <= M)
	{
		monky[ind1] = 1;
		ind1++;
	}
	
	int ind2;//扫描器
	int cou=0;//K个出1个
	int ind3;//输出扫描器
	int tim = 1;

L:	ind2 = 0;
	ind3 = 0;
	while (ind2 <= M)
	{
		if (monky[ind2] == 1)
		{
			cou++;
			if (cou == K)
			{
				monky[ind2] = 0;
				restnum--;
				cou = 0;
			}
		}
		ind2++;

	}
	
	if (restnum > 1)
		goto L;
	system("cls");
	ind3 = 0;
	while (ind3 <= 1001)
	{
		if (monky[ind3] == 1)
		{
			
			printf("%d\n", ind3);
		}
		ind3++;
	}
	tim++;
	
	
	system("pause");
	return 0;
}
