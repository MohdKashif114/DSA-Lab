#include <stdio.h>


int removeDuplicates(int arr[], int n, int maxValue) {
    int freq[maxValue + 1]; 
    for(int i = 0; i <= maxValue; i++) {
        freq[i] = 0;
    }

    int uniqueCount= 0;
    for(int i= 0;i < n; i++) {
        if (freq[arr[i]] == 0) { 
            freq[arr[i]] = 1;
            arr[uniqueCount++] = arr[i]; 
        }
    }
    return uniqueCount;
}

int main() {
    int n, maxValue = 100; 
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int newSize= removeDuplicates(arr, n, maxValue);

    printf("Array after removing duplicates:\n");
    for (int i= 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
