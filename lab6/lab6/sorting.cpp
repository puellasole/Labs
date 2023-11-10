#include <math.h>
#include "swaping.h"

int** sorting(int** arr, int rows, int cols) {
    int* arr2 = new int[rows];
    for (int i = 0; i < rows; i++) {
        arr2[i] = 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2[i] = arr2[i] + abs(arr[i][j]);
        }
    }
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i; j < cols - 1; j++) {
            if (arr2[i] >= arr2[j]) {
                arr = swaping(arr, i, j, cols);
            }
        }
    }
    return arr;
}