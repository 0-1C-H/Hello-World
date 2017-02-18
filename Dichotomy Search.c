#include "stdio.h"
#include "stdlib.h"

#define TYPE int
#define CAPACITY 20
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
		swap(&arr[i], &arr[j]);//��������
	}

	quicksort(arr, left, i - 1);
	quicksort(arr, i + 1, right);


}

int halfsearch(TYPE *arr,int left,int right,TYPE num)
{
	int result=0;
	int i = left;
	int j = right;
	if (arr[i]==num)
	{
		return i;
	}
	if (arr[j] == num)
	{
		return j;
	}
	int mid = (i + j) / 2;
	if (arr[mid] > num){
		result=halfsearch(arr, i, mid,num);
	}
	if (arr[mid] < num){
		result=halfsearch(arr, mid, j, num);
		}
	if (arr[mid] == num)
	{
		result = mid;
	}
	return result;
}


int main()
{
	TYPE a[CAPACITY];
	int i = 0;
	int num;
	for (i=0; i <= (CAPACITY-1); i++)
	{
		scanf("%d", &a[i]);
	}
	i = 0;
	quicksort(a, 0, CAPACITY - 1);
	for (i = 0; i <= (CAPACITY - 1); i++)
	{
		printf("%d\n", a[i]);
	}
	i = 0;
	printf("?");
	scanf("%d", &num);
	i=halfsearch(a, 0, CAPACITY-1, num);
	printf("%d", i+1);


	
	system("pause");
	return 0;

}