#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> a)
{
    int n = a.size();
    for(int j = 1; j < n; ++j)
    {
        int key = a[j];
        int i = j - 1;
        while(i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i -= 1;
        }
        a[i + 1] = key;
    }
    cout << "After Insertion Sort: ";
    for(auto it: a)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: \n";
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    insertionSort(a);
    return 0;
}
