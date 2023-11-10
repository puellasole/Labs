
int** swaping(int** matr, int firstRow, int secondRow, int cols) {
    for (int i = 0; i < cols; ++i)
    {
        int tempCell = matr[firstRow][i];
        matr[firstRow][i] = matr[secondRow][i];
        matr[secondRow][i] = tempCell;
    }
    return matr;
}