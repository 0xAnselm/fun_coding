#include <iostream>
using namespace std;

// int A[] = {5, 4, 3, 2, 1};
// int A[] = [42, 32, 96, 23, 13, 24, 94, 52, 71]
int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
const int len = sizeof(A) / sizeof(A[0]);
int B[len];
void printArray()
{
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void swap(int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void merge(int l, int m, int r)
{
    int i, j, k;
    for (i = l; i <= m; i++)
    {
        B[i] = A[i];
    }
    for (i = m + 1; i <= r; i++)
    {
        B[i] = A[r - i + m + 1];
    }
    i = l;
    j = r;
    for (k = l; k <= r; k++)
    {
        A[k] = (B[i] < B[j]) ? B[i++] : B[j--];
    }
}

void mergesort(int l, int r)
{
    if (r > l)
    {
        int m = (int)((r + l) / 2);
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}

void test()
{
    int arr[] = {1, 2, 37, 40, 5, 7};
    int i = 3;
    arr[i]++;
    cout << i << " " << arr[i] << endl;
    arr[i++];
    cout << i << " " << arr[i] << endl;
}

int main()
{
    printArray();
    mergesort(0, len - 1);
    printArray();
    test();
}