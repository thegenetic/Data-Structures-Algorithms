#include <iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int n)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == n)
            return mid;
        else if (n < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10], num;
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value whose position you want to check:" << endl;
    cin >> num;
    int output = binarysearch(arr, 0, 9, num);
    if (output == -1)
    {
        cout << "Cannot find the position of this value" << endl;
    }
    else
    {
        int rem;
        rem = (output + 1);
        if (rem == 1)
        {
            cout << "The element is in " << output + 1 << "st position." << endl;
        }
        else if (rem == 3)
        {
            cout << "The element is in " << output + 1 << "rd position." << endl;
        }
        else if (rem == 2)
            cout << "The element is in " << output + 1 << "nd position." << endl;

        else
        {
            cout << "The element is in " << output + 1 << "th position." << endl;
        }
    }

    return 0;
}