#include <stdio.h>
#include <limits.h>


void find(int rows, int cols, int arr[rows][cols]) {
    int maxVal=INT_MIN, minVal= INT_MAX;
    int diagonalSum= 0;

    
    for(int i= 0;i<rows;i++) {
        for (int j= 0;j< cols;j++) {
            if (arr[i][j] >maxVal) maxVal= arr[i][j];
            if (arr[i][j]< minVal) minVal= arr[i][j];
            if (i ==j) diagonalSum +=arr[i][j];
        }
    }

    printf("Max value: %d\n",maxVal);
    printf("Min value: %d\n",minVal);
    printf("Diagonal sum: %d\n",diagonalSum);
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("Enter elements of the array:\n");
    for(int i= 0;i< rows;i++) {
        for (int j= 0;j< cols; j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    find(rows,cols,arr);

    return 0;
}
