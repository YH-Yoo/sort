#include <stdio.h>
#include <stdlib.h>
#define max 10

int partition(int A[], int start, int end)
{
	int pivot = A[end];
	int i;
	int index = start;
	int	temp;

	i = start;
	while (i < end)
	{
		if (A[i] <= pivot)
		{
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
		i++;
	}
	temp = A[index];
	A[index] = A[end];
	A[end] = temp;
	return (index);
}

void quicksort(int A[] ,int start, int end)
{
	int	index;
	int	i;

	if(start < end)
	{
		index = partition(A, start, end);
		quicksort(A, start, index - 1);
		quicksort(A, index + 1, end);
	}
	else
		return ;
}

int main()
{
	int A[max] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50};
	int i;

	i = 0;
	printf("befoer sorting\n");
	while (i < max)
	{
		printf("%d ", A[i]);
		i++;
	}
	quicksort(A, 0, max -1);
	printf("\nafter sorting\n");
	i = 0;
	while (i < max)
	{
		printf("%d ", A[i]);
		i++;
	}
}
