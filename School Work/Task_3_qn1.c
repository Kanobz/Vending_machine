#include <stdio.h>

void shuffleRecursive(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    
    for (int i = start; i <= mid; i++) {
        if (arr[i] % 2 != 0) {
            for (int j = mid + 1; j <= end; j++) {
                if (arr[j] % 2 == 0) {
                    
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }
    }

    
    shuffleRecursive(arr, start, mid);
    shuffleRecursive(arr, mid + 1, end);
}

int main() {
    int arr[] = {3, 1, 4, 6, 9, 2, 5, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    shuffleRecursive(arr, 0, size - 1);

    printf("\nShuffled array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
