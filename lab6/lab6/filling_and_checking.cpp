
#include <iostream>
#include "isprime.h"
#include "isequal.h"
using namespace std;
int filling_and_checking(int** arr, int rows, int cols) {
    int a;
    int h = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "enter arr[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a;
            int module = abs(a);
            h += int(isprime(module));
            arr[i][j] = a;
        }
    }
    int g = 0;
    int k = isequal(arr, rows, cols);
    if ((k == 1) && (h > 0)) {
        return k;
    }
    else {
        return g;
    }
}