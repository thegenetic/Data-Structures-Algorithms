#include<iostream>
using namespace std;

int Partition(int a[], int s, int e){
    int pevot=a[e];
    int pIndex=s;
    for (int i = s; i < e; i++)
    {
        if (a[i]<pevot)
        {
            int temp=a[i];
            a[i]=a[pIndex];
            a[pIndex]=temp;
            pIndex++;
        }
        
    }
    int temp=a[e];
    a[e]=a[pIndex];
    a[pIndex]=temp;
    return pIndex;
}

void QuickSort(int a[],int s,int e){
    if (s<e)
    {
        int p=Partition(a, s, e);
        QuickSort(a, s, p-1);
        QuickSort(a, p+1, e);
        
    }
    
}

int main(){
    int n, *a;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the elements of the array:"<<endl;
    a=new (nothrow) int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Before sorting the array was :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    QuickSort(a,0,(n-1));
    cout<<"After sorting the array becomes :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
        
    }
    return 0;
}