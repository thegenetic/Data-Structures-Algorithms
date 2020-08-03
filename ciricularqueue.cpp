#include<iostream>
using namespace std;
class circularqueue
{
private:
    int arr[5], rare, front, count;
public:
    circularqueue()
    {
        rare=-1;
        front=-1;
        count=0;
        // *****for intializing queue values to 0******
        for (int i = 0; i < 5; i++)
        {
            arr[i]=0;
        }
    }

    bool isEmpty(){
        if (rare==-1 && front==-1)
        {
            return true;    
        }
        else
        {
            return false;
        }
        
    }

    bool isFull(){
        if ((rare+1)%5==front)//*******condition differs from simple queue**********
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void enqueue(int val){
        if (isFull())
        {
            cout<<"The Queue is full"<<endl;
            return;
        }
        else if (isEmpty())
        {
            rare=0;
            front=0;
            arr[rare]= val;
            count++;
        }
        else
        {
            rare=(rare + 1)%5;//*******condition differs from simple queue**********
            arr[rare]=val;
            count++;
        }
        
    }

    int dequeue(){int x=0;
        if (isEmpty())
        {
            cout<<"The Queue is empty"<<endl;
            return 0;
        }
        else if (rare==front)
        {
            x=arr[rare];
            rare=-1;
            front=-1;
            return x;
        }
        else
        {
            cout<<"The front value is: "<<front<<endl;
            x=arr[front];
            arr[front]=0;
            front=(front+1)%5;//*******condition differs from simple queue**********
            return x;
        }
        
    }

    int itemcount(){
       
        return (count) ;
    }

    void display(){
        cout<<"The Queue is :"<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout<<arr[i]<<"\t";
        }
        
    }
};

int main(){
    int value, options;
    circularqueue q;
    do
    {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> options;
    switch (options)
    {
    case 0:
        break;
    case 1:
        cout<<"Enqueue function called>>>"<<endl;
        cout<<"Enter the value: ";
        cin>>value;
        q.enqueue(value);
        break;
    case 2:
        cout<<"Dequeue function called>>>"<<endl;
        q.dequeue();
        break;
    case 3:
        cout<<"IsEmpty function called>>>"<<endl;
        if (q.isEmpty())
        {
            cout<<"The Queue is empty"<<endl;
        }
        else
        {
            cout<<"The Queue is not empty"<<endl;
        }
        
        break;
    case 4:
        cout<<"IsFull function called>>>"<<endl;
        if (q.isFull())
        {
            cout<<"The Queue is full"<<endl;
        }
        else
        {
            cout<<"The Queue is not full"<<endl;
        }
        
        break;
    case 5:
        cout<<"Count function called>>>"<<endl;
        cout<<"Totoal elements in the Queue is "<<q.itemcount()<<endl;
        break;
    case 6:
        cout<<"Display function called>>>"<<endl;
        q.display();
        break;
    case 7:
        system("cls");
        break;
    
    default:
        cout<<"Enter a valid option...... "<<endl;
        break;
    }
    } while (options!=0);
    return 0;
}

