// Quicksort
// Using last number as pivot
#include<stdlib.h> 
#include<stdio.h>
#include<iostream>

void printArray(int A[], int size) {
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int partition(int arr[], int L, int R) {
	int pivot = arr[L];

	// Initiate i right before the element. I separates the two partitions
	int i = L+1;
	// Initiate J as the pivot. Iterate through with J. If arr[j] is bigger than pivot then leave it alone (as it's to the right)
	// If element J is less than pivot, it should be to the left, so switch with whatever element is in I
	for(int j = L+1; j <= R; j++) {
		if(arr[j] < pivot) {
			int temp = arr[i];
			std::cout << "Swapping " << arr[i] << " and " << arr[j] << "\n";
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	int temp = arr[i-1];
	arr[i-1] = pivot;
	arr[L] = temp;
	return (i-1);
}

void quicksort(int arr[], int L, int R) {
	if (L < R) {
		int pi = partition(arr, L, R);

		quicksort(arr, L, pi-1);
		quicksort(arr, pi+1, R);
	}
}


// Make an aray, find size, then quicksort
int main() {
	int arr[] = {39, 50, 19, 4, 85, 71, 5, 7, 1, 4, 95, 189, 343};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("The given array is \n");
	printArray(arr, arr_size);

	quicksort(arr, 0, arr_size-1);

	printf("The sorted array is \n");
	printArray(arr, arr_size);
	return 0;
}

