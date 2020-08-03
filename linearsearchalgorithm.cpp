#include<iostream>
using namespace std;

void LinerarSearch(int arr[], int n){
    int temp=0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]==n)
        {
            cout<<"The element is in posisition"<<i+1<<endl;
            temp++;
        }
        
    }
    if (temp==0)
    {
        cout<<"Element not ound"<<endl;
    }
    

}

int main()
{
    
    int option;
    int arr[5];
    do
    {
        cout<<"Enter 0 to exit and 1 to continue"<<endl;
        cin>>option;
        switch (option)
        {
        case 0:
            /* code */
            break;
        case 1:
        cout<<"Enter the elements of the array:"<<endl;
        for (int i = 0; i < 5; i++)
        {
            cin>>arr[i];
        }
        cout<<"Enter the number you want to search:"<<endl;
        int n;
        cin>>n;
        LinerarSearch(arr,n);

            /* code */
            break;
        
        default:
        cout<<"Enter correct option"<<endl;
            break;
        }
    } while (option!=0);
    
    return 0;
}