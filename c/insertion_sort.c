#include <stdio.h>
// Creating algorithm insertion sort
// Date: 03/02/2024
// Author: Lukas Silva Machado
// Iterative and Recursive forms

int insertion_sort(int array[], int size_array){
    if(size_array > 0){
        printf("Ordering array...\n");
    	printf("Size array %d\n", size_array);
        for(int i = 1; i < size_array; i++){
	    int key = array[i];
	    int check = i - 1;
	    while(check >= 0 && key < array[check]){
    	        array[check + 1] = array[check];
		check--;
	    }
	    array[check + 1] = key;
	}
    	printf("Ordened array: ");
        for(int i = 0; i < size_array; i++){
            printf("%d", array[i]);
            if (i < size_array - 1){
                printf(", ");
            }
        }
        printf("\n");
    }
    return 0;
}

void print_array(int array[], int size_array){
    printf("\n");
    for(int i = 0; i < size_array; i++){
        printf("%d", array[i]);
        if (i < size_array - 1){
            printf(", ");
        }
    }
    printf("\n");
}

int check_left_elements(int array[], int check, int j, int key){
    if(check >= j){
    	return check - 1;
    }
    int k = check_left_elements(array, check + 1, j, key);
    if(key < array[k]){
        array[k + 1] = array[k];
	return k - 1;
    }else{
       return k;
    }
}

int recursive_insertion_sort(int array[], int size_array, int j){
    if(j >= size_array){
        return j;
    }
    int key = array[j];
    int insert = check_left_elements(array, 0, j, key);
    array[insert + 1] = key;
    print_array(array, size_array);
    return recursive_insertion_sort(array, size_array, j+1);
}

int main(){
    int array[] = {10,9,8,7,5,4,9};
    int array2[] = {10,9,8,7,5,4,9};
    // Printing not sorted arrays
    printf("Not sorted arrays\n:");
    print_array(array, size_array);
    print_array(array2, size_array2);
    // Sorting arrays
    int size_array = sizeof(array) / sizeof(array[0]);
    int size_array2 = sizeof(array2) / sizeof(array2[0]);
    insertion_sort(array2, size_array2);
    recursive_insertion_sort(array, size_array, 1);
    // Printing sorted arrays
    printf("Array in sorted order:\n");
    print_array(array, size_array);
    print_array(array2, size_array2);
    return 0;
}



