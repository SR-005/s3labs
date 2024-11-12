#include <stdio.h>
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
        for (int k=0; k < n; k++)
		    printf("%d ", arr[k]);
	    printf("\n");
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}
void printArray(int arr[], int size)
{
	int i;
    printf("RESULT: \n");
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[100],n,i;
	printf("enter no of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    printf("enter:");
	    scanf("%d",&arr[i]);
	}
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
