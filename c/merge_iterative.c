#include<stdio.h>
void intercalation(int v[], int c1, int f1, int c2, int f2){
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

int min(int x, int y){
	if(x < y){
		return x;
	}else{
		return y;
	}
}

void merge_iterative(int array[], int size_array){
	for(int i = 1; i < size_array - 1; i = 2 * i){
		printf("i é igual a : %i\n", i);
		for(int start_sub_array_1 = 0; start_sub_array_1 < size_array - 1; start_sub_array_1  += 2 * i){
			int end_sub_array_1 = min(start_sub_array_1 + i - 1, size_array - 1);

			int start_sub_array_2 = min(end_sub_array_1 + 1, size_array - 1);
			int end_sub_array_2 = min(start_sub_array_1 + 2*i - 1, size_array - 1);
			intercalation(array, start_sub_array_1, end_sub_array_1, start_sub_array_2, end_sub_array_2);
		}
	}
}
void main(int argc, char *argv[]){
	int array[] = {5,16,2,45,12,23,13,15,97,100, -1, -45, 17, 4, -598};
	int size_array = sizeof(array) / sizeof(array[0]);
	int teste = 1;
	printf("Size of array: %d\n", size_array);
	merge_iterative(array, size_array);

	for(int i = 0; i <= size_array - 1; i++){
		printf("%d", array[i]);
		if(i < size_array - 1){
			printf(", ");
		}	
	}
	printf("\n");
}

