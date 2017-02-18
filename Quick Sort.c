#include "stdio.h"
#include "stdlib.h"

#define TYPE int

void swap(TYPE *one, TYPE  *two)
{
	TYPE temp;
	temp = *one;
	*one = *two;
	*two = temp;
}

void quicksort(TYPE arr[], int left, int right)
{

	if (left >= right)
	{
		return;
	}
	int i = left;
	int j = right;//Avoid rewriting.

	TYPE base = arr[left];//������ߵ�ֵ��Ϊ��׼ֵ
	
	while (i < j)//����ߵı�ʶ���ұߵı�ʶ�����
	{
		while (arr[j] > base&&j > i)
		{
			j--;
		}//��ǰѰ��ֱ���ҵ�һ����baseС����
		while (arr[i] < base&&i < j)
		{
			i++;
		}//����Ѱ��ֱ���ҵ�һ����base�����
		swap(&arr[i],&arr[j]);//��������
	}
	
	quicksort(arr, left, i - 1);
	quicksort(arr, i+1, right);
	
	
}


int main()
{
	TYPE a[10];
	int i = 0;
	while (i <= 9)
	{
		scanf("%d", &a[i]); 
		i++;
	}
	i = 0;
	quicksort(a, 0, 9);
	while (i <= 9)
	{
		printf("%d\n", a[i]);
		i++;
	}
	
	system("pause");
	
	return 0;
}