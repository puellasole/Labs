
int isequal(int** arr, int rows, int cols) {
    int t = 0;
    int t1 = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = i + 1; j < cols; j++) {
            for (int k = 0; k < rows; k++) {
                if (arr[k][i] == arr[k][j]) {
                    t++;
                }
            }
            if (t == rows) {
                t1 = 1;
            }
            t = 0;
        }
    }
    return t1;
}