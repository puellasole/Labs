#include "p_2.h"
#include <iostream>

const int N = 6;
template<typename T>

T* Copy(T* arr1, T* arr2)
{
    long long* arr1_ll = nullptr;
    long long* arr2_ll = nullptr;
    arr1_ll = reinterpret_cast<long long*> (arr1);
    arr2_ll = reinterpret_cast<long long*> (arr2);

    for (int i = 0; i < (N / 2); i++)
    {
        *arr2_ll = *arr1_ll;
        arr1_ll++;
        arr2_ll++;
    }

    char* arr1_ch = nullptr;
    char* arr2_ch = nullptr;
    arr1_ch = reinterpret_cast<char*> (arr1) + (N - (N % 2));
    arr2_ch = reinterpret_cast<char*> (arr2) + (N - (N % 2));

    for (int i = N - (N % 2) - 1; i < N; i++)
    {
        *arr2_ch = *arr1_ch;
        arr1_ch++;
        arr2_ch++;
    }
    return arr2;
}

int main()
{
    int arr1[N] = { 1, 2, 3 };
    int arr2[N] = { 0 };
    Copy(arr1, arr2);
    for (int x = 0; x < N; x++) { std::cout << arr2[x] << ' '; }
}
