#include <iostream>
using namespace std;
class Queue
{
private:
    int arr[5], front, rare;

public:
    Queue()
    {
        front = -1;
        rare = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i]=0 ;
        }
    }
    bool isEmpty()
    {
        if (rare ==-1 && front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rare == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "The Queue is full" << endl;
            return ;
        }
        else if (isEmpty())
        {
            rare = 0;
            front = 0;
            arr[rare] = val;
        }
        else
        {
            rare++;
            arr[rare] = val;
        }
    }
    int dequeue()
    {
        int x=0;
        if (isEmpty())
        {
            cout << "The Queue is empty" << endl;
            return x;
        }
        // **********************THIS PART IS NOT NECESSARY AT ALL THE ELSE PART DOES ITS WORK**************************
        // else if (rare == front)
        // {
        //     x = arr[rare];
        //     arr[rare]=0;
            
        //     rare =-1; front = -1;
        //     return x;
        // }
        else
        {
            cout<<"front value : "<<front<<endl;
            x = arr[front];
            arr[front] = 0;
            front ++;
            return x;
        }
    }
    int count()
    {
        cout << "Total no. of elements present in the Queue is "<<(rare - front) + 1;
        return 0;
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i]<<"\t";
        }
    }
};

int main()
{
    int value, options;
    Queue q;
    do
    {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> options;
        switch (options)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue option is called" << endl;
            cout << "Enter the value you want to input:";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            cout << "Dequeue option called" << endl;
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
            {
                cout << "The Queue is empty" << endl;
            }
            else
            {
                cout << "The Queue is not empty" << endl;
            }
            break;
        case 4:
            if (q.isFull())
            {
                cout << "The Queue is full" << endl;
            }
            else
            {
                cout << "The Queue is not full" << endl;
            }
            break;
        case 5:
            cout << "Count function called" << endl;
            q.count();
            break;
        case 6:
            cout << "Displaying the Queue" << endl;
            q.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter a valid option number" << endl;
            break;
        }

    } while (options != 0);
}