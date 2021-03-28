#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[500010];
void QuickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int k = arr[low];
		while (i < j)
		{
			while (i < j && arr[j] >= k)  
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}

			while (i < j && arr[i] < k)      
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}

		arr[i] = k;

		QuickSort(arr, low, i - 1); 
		QuickSort(arr, i + 1, high); 
	}
}

int main()
{
	int n, i, x, j = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	QuickSort(arr, 0, n - 1);

	int ticket = 0, num = 0;
	for (int i = (n-1) / 2, j = n-1; i >= 0 && j > (n-1) / 2;)
	{
		if (2 * arr[i] <= arr[j])
		{
			ticket++;
			num += 2;
			i--; j--;
		}
		else  i--;
	}

	ticket = ticket + (n - num);

	printf("%d\n", ticket);

	return 0;
}