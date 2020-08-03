#include<iostream>
using namespace std;

void Countin_sort(int input_array[], int n, int r)
{
    int output_array[n],count_array[r];
    for (int i = 0; i < r; i++)
    {
        count_array[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        ++count_array[input_array[i]];
    }
    for (int i = 1; i < r; i++)
    {
        count_array[i]=count_array[i]+count_array[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        output_array[--count_array[input_array[i]]]=input_array[i];
    }
    for (int i = 0; i < n; i++)
    {
        input_array[i]=output_array[i];
    }
    
     
}
int main()
{
    int n, *a, range= 10;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    a=new (nothrow) int[n];
    cout<<"Enter the elements of the array in range 0-9: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"The unsorted list of the elements are: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n";

    Countin_sort(a,n,range);

    cout<<"The sorted list of the elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    
    return 0;
}