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

	TYPE base = arr[left];//将最左边的值作为基准值
	
	while (i < j)//当左边的标识在右边的标识的左边
	{
		while (arr[j] > base&&j > i)
		{
			j--;
		}//往前寻找直到找到一个比base小的数
		while (arr[i] < base&&i < j)
		{
			i++;
		}//往后寻找直到找到一个比base大的数
		swap(&arr[i],&arr[j]);//交换两数
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