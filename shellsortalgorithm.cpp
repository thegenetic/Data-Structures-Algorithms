#include <iostream>
using namespace std;

void ShellSorting(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = a[j];
            int i = 0;
            for (i = j; (i >= gap) && (a[i - gap] > temp); i -= gap)
            {
                a[i] = a[i - gap];
            }
            a[i] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Befor sorting the array was: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
    ShellSorting(a, n);

    cout << "After sorting the array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    return 0;
}