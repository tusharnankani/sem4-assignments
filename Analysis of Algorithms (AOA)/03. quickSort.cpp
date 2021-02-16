#include <iostream>
#include <vector>

using namespace std;

int cnt, siz;

int partition(int a[], int i, int j) {
    int p = a[i]; // p is the pivot
    int m = i; // S1 and S2 are initially empty
    for (int k = i+1; k <= j; k++) { // explore the unknown region
    if (a[k] < p) { // case 2
        m++;
        swap(a[k], a[m]); // C++ STL algorithm std::swap
    } // notice that we do nothing in case 1: a[k] >= p
    }
    swap(a[i], a[m]); // final step, swap pivot with a[m]

    cout << "Pivot Index: " << m << "\t\t|\t";
    cout << "Iteration " << cnt++ << ": ";
    for(int i = 0 ; i < siz; ++i)
        cout << a[i] << " ";
    cout << endl;
    return m; // return the index of pivot
}


void quickSort(int a[], int low, int high) {
  if (low < high) {
    int m = partition(a, low, high); // O(N)
    // a[low..high] ~> a[low..m–1], pivot, a[m+1..high]
    quickSort(a, low, m-1); // recursively sort left subarray
    // a[m] = pivot is already sorted after partition
    quickSort(a, m+1, high); // then sort right subarray
  }
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    siz = n;
    int a[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << endl;
    quickSort(a, 0, n - 1);
    cout << "\nAfter Quick Sort: ";
    for(auto it: a)
        cout << it << " ";
    cout << endl;
    return 0;
}
