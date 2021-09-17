#include<stdio.h>
#include <time.h>

void swap(int *x, int *y){ //pass the address of the variables to swap
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int *arr, int n){
	int i, j;
	for (i = 0; i < (n-1); ++i)
	{
		printf("inside first for loop i=%d, arr[%d] = %d\n", i,i, arr[i]);
		for (j = 0; j < (n-(i+1)); ++j)
		{
			printf("\tinside second for loop j=%d, arr[%d]=%d\n", j,j, arr[j]);
			printf("\t\tcomparing arr[%d] with arr[%d]\n", j, j+1);
			if (arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void merge(int *arr, int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;//r-(m+1)+1;
	int L[n1], R[n2];
	int i,j,k;
	/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[(m + 1) + j];
	i = 0; // Initial index of first or left subarray
    j = 0; // Initial index of second or right subarray
    k = l; // Initial index of merged subarray
    while(i<n1 && j<n2){
    	if (L[i]<=R[j])
    	{
    		arr[k] = L[i];
    		i++;
    	} else{
    		arr[k] = R[j];
    		j++;
    	}
    	k++;
    }
    while (i < n1) { // right is empty
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) { // left is empty
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int *arr, int l, int r){//recursive function
	int m;
	if (l < r)
	{
		
		m = (l+r)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int printArray(int *arr, int size){
	int count;
	for (count = 0; count < size; ++count)
	{
		printf("\narr[%d] = %d", count, *(arr+count));
	}
	return (count+1);// returns the number of elements printed
}

int getInput(int *arr, int size){
	int count;
	for (count = 0; count < size; ++count)
	{
		printf("Enter arr[%d]=",count);
		scanf(" %d", (arr+count));
	}
	return (count+1);// returns the number of elements read
}

int main(int argc, char const *argv[])
{
	int arr[10];
	getInput(arr, 10);

    clock_t begin = clock();
	bubbleSort(arr, 10);
	printArray(arr, 10);
    printf("\n\n");
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent : %f\n", time_spent);

    printf("\n\n");

    begin = clock();
    mergeSort(arr, 0, 9);
    printArray(arr, 10);
    printf("\n\n");
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent : %f\n", time_spent);

	return 0;
}
