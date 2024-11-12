#include <stdio.h>
#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n)
{
	int i, key, j;
    
	for (i = 1; i < n; i++) 
	{
        for (int k = 0; k < n; k++)
		printf("%d ", arr[k]);
	    printf("\n");
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
    printf("RESULT: \n");
	for (i = 0; i < n; i++)
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
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}