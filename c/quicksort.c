#include <stdio.h>

void print_vector(int v[], int size){
	printf("Size array: %d\n", size);
	for(int i = 0; i < size; i++){
		printf("(%d): %d", i, v[i]);
		if(i < size - 1){
			printf("\n");
		}
	}
	printf("\nEnd print of array!\n");
}

int partition(int v[], int start, int end){
	int pivot = v[end];
	int i = start - 1;
	for(int j = start; j < end; j++){
		if(v[j] <= pivot){
			i++;
			int aux_j = v[j];
			v[j] = v[i];
			v[i] = aux_j;
		}
	}
	v[end] = v[i + 1];
	v[i + 1] = pivot;
	return i + 1;
}

void quicksort(int v[], int start, int end){
	if(start < end){
		int pivot = partition(v, start, end);
		quicksort(v, start, pivot - 1);
		quicksort(v, pivot + 1, end);
	}
}

void main(int argc, char *argv[]){
	int vector[] = {5, 9, 2, 1, 8, 45, 20, 16, 12, 13, 0, -56, 23, -285};
	int size_array = sizeof(vector) / sizeof(*vector);
	printf("Printing the vector UNORDERED!\n");

	print_vector(vector, size_array);
	quicksort(vector, 0, size_array - 1);
	printf("Printing the vector ORDERED!\n");
	print_vector(vector, size_array);

}
