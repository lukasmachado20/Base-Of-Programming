#include<stdio.h>

void intercalation(int v[], int c2, int f1, int c2, int f2){
	int len = (f1 - c1 + 1) + (f2 - c2 + 1);
	int a[len];
	int i1 = c1;
	int i2 = c2;
	int k = 0;
	while(i1 <= f1 && i2 <= f2){
		if(v[i1] <= v[i2]){
			a[k++] = v[i1++];
		}else {
			a[k++] = v[i2++];
		}
	}	
	while(i1 <= f1){
		a[k++] = v[i1++];
	}
	while(i2 <= f2){
		a[k++] = v[i2++];
	}
	for(int i = c1, k = 0; i <= f2; i++, k++){
		v[i] = a[k];
	}
}

void merge_sort(int v[], int start, int end){
	if(end > start) {
		int middle = (start + end) / 2;
		merge_sort(v, start, middle);
		merge_sort(v, middle + 1, end);
		intercalation(v, start, middle, middle + 1, end);
	}
}

void main(int argc, char *argv[]){
	int n = 16;
	int v[] = {3, 2};
	int size_array = sizeof(v) / sizeof(v[0]);
	printf("Size array: %d\n", size_array);

	merge_sort(v, 0, size_array - 1);

	for(int i = 0; i <= size_array - 1; i++){
		printf("%d", v[i]);
		if(i < size_array - 1){
			printf(", ");
		}
	}
	printf("\n");
}
