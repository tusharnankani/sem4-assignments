#include <iostream>
#include <vector>

using namespace std;
int siz, cnt;
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    // Initial index of first subarray
    int i = 0;
    // Initial index of second subarray
    int j = 0;
    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "Iteration: " << cnt++ << ": ";
    for(int i = 0; i < siz; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// l is for left index and r is right index of the sub-array of arr to be sorted;
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        //returns recursively
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
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
    mergeSort(a, 0, n - 1);
    cout << "\nAfter Merge Sort: ";
    for(auto it: a)
        cout << it << " ";
    cout << endl;
    return 0;
}
