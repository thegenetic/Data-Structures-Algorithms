#include <iostream>
using namespace std;

void merge(int b[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[size];

    while (i <= m && j <= r)
    {
        if (b[i] <= b[j])
        {
            temp[k] = b[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = b[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = b[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = b[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++)
    {
        b[p] = temp[p];
    }
}

void mergeSort(int a[], int l, int r, int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m, size);
        mergeSort(a, m + 1, r, size);
        merge(a, l, m, r, size);
    }
}

int main()
{
    int *arr, n;
    cout << "Enter the size of the array :" << endl;
    cin >> n;
    arr = new (nothrow) int[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting the elements were: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1, n);
    cout << endl
         << "After sorting the elements were: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}