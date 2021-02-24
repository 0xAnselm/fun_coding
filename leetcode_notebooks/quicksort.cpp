#include <iostream>
using namespace std;

int A[] = { 5,4,3,2,1 };

void printArray() {
    for (int i : A) {
        cout << i << " ";
    }
    cout << "\n";
}

void swap(int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivot(int links, int rechts) {
    return(rechts);
}

int partition(int p, int links, int rechts) {
    int alpha, l, r;
    alpha = A[p];
    l = links - 1;
    A[l] = INT8_MIN;
    r = rechts;
    swap(r,p);
    cout << "p " << p << " l " << l << " r " << r << "\n";
    do {
        cout << "Comp l " << l << " " << A[l] << " " << alpha << "\n";
        while (A[l] <= alpha){
            l++;
        }
        cout << "Comp l " << r << " " << A[r]  << " " << alpha << "\n";
        while (A[r] >= alpha){
            r--;
        }
        if (l < r){
            swap(l,r);
        }
    } while (l < r);
    swap(rechts, l);
    return l;
}

void quicksort(int links, int rechts) {
    int p, i;
    if (links < rechts) {
        cout << "asd";
        p = pivot(links, rechts);
        i = partition(p, links, rechts);
        cout << "Pivot: " << i << " Value: " << A[i] << "\n";
        quicksort(links, i-1);
        quicksort(i+1, rechts);
        printArray();
    }
}

int main() {
    printArray();
    quicksort(0,4);
}