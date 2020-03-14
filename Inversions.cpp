// Count inversions in aray, piggybacking on mergesort. AKA sort and counting
// Rohan Borkar 2020

// Largest number of inversions in given array is n choose 2, aka n(n-1)/2

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
int merge_count(int arr[], int L, int mid, int R) {
	// i, j, k will be counters
	int i, j, k, invCount;

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
	std::cout << "size of r and l: " << l_size << ", " << r_size << "\n";

	// Reset i (counting left array), j (counting right array), k (counting total array)
	i = 0;
	j = 0;
	k = L;
	invCount = 0;
	// Iterate through both arrays comparing the left[i] element to right[j].
	while(i < n1 && j < n2) {
		if(left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			i++;
		}
	// If the right one is bigger, add the remaining size of the left array to the total inversion count
		else {
			arr[k] = right_arr[j];	
			j++;
			std::cout << "there are " << mid-i << " elements left in the array\n";
			invCount += (n1 - i);
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
	std::cout << "Adding " << invCount << " to count\n";
	return invCount;
}



int mergesort(int arr[], int L, int R) {
	int invCount = 0;
	if(L < R) {
		int mid = (L+R)/2;
		invCount = invCount + mergesort(arr, L, mid);
		invCount = invCount + mergesort(arr, mid+1, R);
		invCount = invCount + merge_count(arr, L, mid, R);
	}
	return invCount;
}



int main() {
	int arr[] = {6, 29, 392, 18, 395, 58, 403, 302, 596, 383, 6430, 314, 7950, 32478, 649450, 3423, 3283, 394, 554, 23, 1, 6565, 3423, 545, 787, 121, 576, 38, 8};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int inversions = 0;

	std::cout << "Array size is " << arr_size << "\n";

	printf("The given array is \n");
	printArray(arr, arr_size);

	inversions = mergesort(arr, 0, arr_size-1);

	printf("The sorted array is \n");
	printArray(arr, arr_size);
	std::cout << "Inversions = " << inversions << "\n";
	return 0;

}



