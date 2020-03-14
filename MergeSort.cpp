// Merge sort
// Rohan Borkar 2020

// Import stuff
#include<stdlib.h> 
#include<stdio.h>
#include<iostream>



void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 



// Merge two arrays
void merge(int arr[], int L, int mid, int R) {
	// i, j, k will be counters
	int i, j, k;

	// n1 is the size of the L array, n2 is the size of the R array
	int n1 = mid-L+1;
	int n2 = R-mid;
	// Create empty temmp arrays with size of mid-L and R-mid
	int left_arr[n1];
	int right_arr[n2];


	for(i=0; i<n1; i++) 
		left_arr[i] = arr[L+i];
	
	for(j=0; j<n2; j++) 
		right_arr[j] = arr[mid+j+1];

	int r_size = sizeof(right_arr)/sizeof(right_arr[0]);
	int l_size = sizeof(left_arr)/sizeof(left_arr[0]);
	std::cout << "With n1 of " << n1 << ", array is\n";
	printArray(left_arr, l_size);
	std::cout << "With n2 of " << n2 << ", array is\n";
	printArray(right_arr, r_size);
	

	// Reset i (counting left array), j (counting right array), k (counting total array)
	i = 0;
	j = 0;
	k = L;
	while(i < n1 && j < n2) {
		if(left_arr[i] < right_arr[j]) {
			arr[k] = left_arr[i];
			std::cout << "Appending " << arr[k] << "\n";
			i++;
		}

		else {
			arr[k] = right_arr[j];
			std::cout << "Appending " << arr[k] << "\n";		
			j++;
		}

		k++;
	}

	while(i < n1) {
		arr[k] = left_arr[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}

}



void mergesort(int arr[], int L, int R) {
	if(L < R) {
		int mid = L+(R-L)/2;
		std::cout << "Mid is " << mid << "\n";
		mergesort(arr, L, mid);
		mergesort(arr, mid+1, R);
		merge(arr, L, mid, R);
	}
}



int main() {
	int arr[] = {6, 29, 392, 18, 395, 58, 403, 302, 596, 383, 6430, 314, 7950, 32478, 649450, 3423, 3283, 394, 554, 23, 1, 6565, 3423, 545, 787, 121, 576, 38, 8};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	std::cout << "Array size is " << arr_size << "\n";

	printf("The given array is \n");
	printArray(arr, arr_size);

	mergesort(arr, 0, arr_size-1);

	printf("The sorted array is \n");
	printArray(arr, arr_size);
	return 0;

}



