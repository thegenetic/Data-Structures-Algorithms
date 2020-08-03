#include <iostream>
using namespace std;

int GetMax(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m;
}

void CountingSort(int a[], int n, int div)
{
    int output_array[n];
    int count_array[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count_array[(a[i] / div) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output_array[count_array[(a[i] / div) % 10]-1] = a[i];
        count_array[(a[i] / div) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output_array[i];
    }
}

void RedixSort(int a[], int s)
{
    int m = GetMax(a, s);
    for (int div = 1; m / div > 0; div *= 10)
    {
        CountingSort(a, s, div);
    }
}

int main()
{
    int n, *a;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    a = new (nothrow) int[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The array before sorting was: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
    
    RedixSort(a, n);
    
    cout << "The array after soting is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}