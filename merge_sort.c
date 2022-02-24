#include <stdio.h>
#define max 6

//conquer = 서열정리
void merge(int a[], int low, int mid, int high)
{
	int	b[1000];
	int	i = low;
	int	j = mid + 1;
	int	k = 0;

	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		b[k] = a[j];
		k++;
		j++;
	}
	k--;
	while (k >= 0)
	{
		a[low + k] = b[k];
		k--;
	}
}

// divide = 대진표작성
void mergesort(int a[], int low, int high)
{
	if (low < high)
	{
		int m = (low + high) / 2;

		mergesort(a, low, m);
		mergesort(a, m + 1, high);
		merge(a, low, m, high);
	}
	else
	{
		return ;
	}
}

int	main()
{
	int	a[max] = {20, 10, 70, 80, 40, 90};
	int	i;

	printf("before merge");
	i = 0;
	while (i < max)
	{
		printf(" %d", a[i]);
		i++;
	}
	mergesort(a, 0, max - 1);

	printf("\nafter merge");
	i = 0;
	while (i < max)
	{
		printf(" %d", a[i]);
		i++;
	}
	printf("\n");
}