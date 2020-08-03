#include<iostream>
using namespace std;
void Selectionsorting(int a[]){
    int key, j;
    for (int i = 1; i < 5; i++)
    {
        key=a[i];
        j=i-1;
        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    
}
int main()
{
    int arr[5];
    cout<<"Enter the element of the array:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<"The Unsorted list is: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<"The sorted list is:"<<endl;
    Selectionsorting(arr);
    for (int i = 0; i < 5; i++)
    { 
        cout<<arr[i]<<"\t";
    }
    return 0;
}
