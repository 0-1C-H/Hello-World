#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
	int M;
	int K;
	int monky[1001];
	printf("����M\n");
	scanf("%d", &M);
	printf("����K\n");
	scanf("%d", &K);
	int restnum = M;
	int ind0=0;//ȫ����ʼ��Ϊ0
	for (ind0 = 0; ind0 <= 1001; ind0++)
	{
		monky[ind0] = 0;
	}
	
	int ind1=1;//�ճ���һ������M�����ӳ�ʼ��Ϊ1 
	while (ind1 <= M)
	{
		monky[ind1] = 1;
		ind1++;
	}
	
	int ind2;//ɨ����
	int cou=0;//K����1��
	int ind3;//���ɨ����
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
