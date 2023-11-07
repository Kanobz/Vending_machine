#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for exit

#define SIZE 24
#define nRows 8
#define nCols 3

void set_array(int arr[], int length);
void rem_align(int arr[], int length, int pos);
void print_array(int array[], int length);
//void insert_align(int array[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols]);
void print_matrix(int mat[][nCols], int rows);
bool found_duplicate(int arr[], int length);
void flip_array(int arr[], int length, int flippedArr[]);



int main() {
    int arr[SIZE];
    int arr2d[nRows][nCols];
    int flippedArr[SIZE];

    // Setting array
    set_array(arr, SIZE);

    // Rem align
    printf("Original array:\n");
    print_array(arr, SIZE);

    
    int pos = 3; 
    rem_align(arr, SIZE, pos);

   
    printf("\nArray after removing element at index %d:\n", pos);
    print_array(arr, SIZE);

    printf("\n");
    
    // Print the matrix
    print_matrix(arr2d, nRows);

    /*
    int value = 8;
    insert_align(arr, SIZE, pos, value);
    */

    // Reshaping array 
    reshape(arr, SIZE, arr2d);

    // Transposed matrix
    printf("\nTransposed Matrix:\n");
    print_trans_matrix(arr2d);

    // Checking for dupes
    if (found_duplicate(arr, SIZE)) {
        printf("\nDuplicate values found in the array.\n");
    } else {
        printf("\nNo duplicate values found in the array.\n");
    }

    // Flipping array 
    flip_array(arr, SIZE, flippedArr);
    printf("\nFlipped Array:\n");
    print_array(flippedArr, SIZE);

    
    return 0;
}


void set_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = i;
    }
}

void rem_align(int arr[], int length, int pos) {
    if (pos < 0 || pos >= length) {
        printf("Invalid array index. Exiting the function.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
}


void print_array(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d]= %d\n", i, j, mat[i][j]);
        puts("");
    }
}
/*
void insert_align(int arr[], int length, int pos, int value) {
    if (pos < 0 || pos >= length) {
        printf("Invalid array index. Exiting the function.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i - 1];
    }
}

*/
void reshape(int arr[], int length, int arr2d[nRows][nCols]) {
    if (length != nRows * nCols) {
        printf("Error: Length of arr does not match nRows * nCols. Exiting the function.\n");
        exit(EXIT_FAILURE);
    }

    int k = 0;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            arr2d[i][j] = arr[k++];
        }
    }
}

void print_trans_matrix(int arr2d[nRows][nCols]) {
    for (int j = 0; j < nCols; j++) {
        for (int i = 0; i < nRows; i++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
}

bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true; 
            }
        }
    }
    return false; 
}

void flip_array(int arr[], int length, int flippedArr[]) {
    for (int i = 0; i < length; i++) {
        flippedArr[i] = arr[length - i - 1];
    }
}
