#include<iostream>
using namespace std;

void sorted(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
                
    }
            
    
}

int main(){
    int *a, n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    a=new (nothrow) int[n];
    cout<<"Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"The entered elements are:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    sorted(a, n);
    cout<<"\nThe sorted elements are:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}