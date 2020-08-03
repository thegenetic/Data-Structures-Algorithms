#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    
}

int main(){
    int *a;
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    a=new (nothrow) int[n];
    cout<<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"The arrays in unsorted order is:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    bubblesort(a,n);
    cout<<endl<<"The arrays in sorted order is:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0; 
}