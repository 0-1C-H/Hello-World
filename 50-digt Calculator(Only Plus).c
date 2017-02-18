#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char no_one[51], no_two[51], result[51];
	int t;
	t = 0;
	while (t <= 50)
	{
		result[t] = 0;
		t++;
	}
	scanf("%s", no_one);
	scanf("%s", no_two);
	int i;
	i = 0;
	while (i <= 50)
	{
		no_one[i] = no_one[i] - '0';
			no_two[i] = no_two[i] - '0';
			i++;
	}
	int j;
	j = 49;
	while (j >= 0)
	{
		result[j] = no_one[j] + no_two[j] + result[j];
		if (result[j] >= 10)
		{
			result[j - 1] = result[j - 1] + 1;
			result[j] = result[j] - 10;

		}
		j--;

	}


	printf("\n%s", result);
	return 0;

}