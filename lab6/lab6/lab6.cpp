
#include <iostream>
#include <math.h>
#include "printing.h"
#include "filling_and_checking.h"
#include "sorting.h"
using namespace std;

int main()
{
    int rows, cols;
    cin >> rows;
    cin >> cols;
    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    int t = filling_and_checking(arr, rows, cols);
    printing(arr, rows, cols);
    cout << "------------------------" << endl;
    if (t == 0)
    {
        cout << "Nothing changed" << endl;
    }
    else {
        arr = sorting(arr, rows, cols);
        printing(arr, rows, cols);
    }
    cout << "------------------------" << endl;
}