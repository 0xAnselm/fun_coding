#include <iostream>
using namespace std;

// int A[] = {5, 4, 3, 2, 1};
// int A[] = [42, 32, 96, 23, 13, 24, 94, 52, 71]
int A[] = {2, 8, 7, 1, 3, 5, 6, 4};

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

int pivot(int links, int rechts)
{
    int m = int((links + rechts) / 2);
    cout << "Pivot: " << A[m] << "\n";
    return (m);
}

int partition(int p, int links, int rechts)
{
    int alpha, l, r;
    alpha = A[p];
    l = links - 1;
    r = rechts;
    swap(r, p);
    while (l < r)
    {
        do
        {
            l++;
        } while (A[l] < alpha);
        cout << "li:" << A[l] << "\n";
        do
        {
            r--;
        } while (A[r] > alpha);
        cout << "re:" << A[l] << "\n";
        if (l < r)
        {
            swap(l, r);
        }
    }
    swap(rechts, l);
    printArray();
    return l;
}

void quicksort(int links, int rechts)
{
    int p, i;
    if (links >= rechts)
    {
        cout << "A[links]=" << links << " A[rechts]=" << rechts << "\n";
    }
    if (links < rechts)
    {
        cout << "A[links]=" << links << " A[rechts]=" << rechts << "\n";
        p = pivot(links, rechts);
        i = partition(p, links, rechts);
        quicksort(links, i - 1);
        quicksort(i + 1, rechts);
    }
}

int main()
{
    printArray();
    int len = sizeof(A) / sizeof(A[0]);
    quicksort(0, len - 1);
    printArray();
}