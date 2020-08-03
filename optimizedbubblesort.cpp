#include<iostream>
using namespace std;

void optimizedbubblesort(int a[], int n){
    int round = 0;
    for (int i = 0; i < n; i++)
    {
        round++;
        int flag=false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                flag=true;
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            
        }
        if (flag==false)
        {
            break;
        }
        
    }
    cout<<endl<<"Total rounds needed for sorting is: "<<round<<endl;
}

int main(){
    int *a,n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    a=new (nothrow) int[n];
    cout<<"Enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    cout<<"The Unsorted list of the array is:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    optimizedbubblesort(a,n);
    cout<<endl<<"The sorted list of the array is:" <<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}