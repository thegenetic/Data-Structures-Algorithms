#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1; //initializing top to -1
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0; //initializing all the values of it to 0
        }
    }

    bool isFull()
    {
        if (top ==4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack downflow" << endl;
            return 0;
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
    }

    int count()
    {
        return top + 1;
    }

    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void change(int pos, int val)
    {
        if (pos >= 0 && pos < 5)
        {
            arr[pos] = val;
        }
        else
        {
            cout << "Please enter a correct position limit. From 0 to 4" << endl;
        }
    }

    void display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Stack s;
    int option, value, position;
    do
    {
        cout << "0. Exit" << endl;
        cout << "1. peek" << endl;
        cout << "2. display" << endl;
        cout << "3. change" << endl;
        cout << "4. push" << endl;
        cout << "5. pop" << endl;
        cout << "6. is empty" << endl;
        cout << "7. is full" << endl;
        cout << "8. count" << endl;
        cout << "9. clear screen" << endl
             << endl;

        cout << "Please choose your option:" << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the position you want to access:" << endl;
            cin >> position;
            break;
        case 2:
            cout << "The Stack is:\n";
            s.display();
            break;
        case 3:
            cout << "Enter the position: " << endl;
            cin >> position;
            cout << "Enter the value: " << endl;
            cin >> value;
            s.change(position, value);
            break;
        case 4:
            cout << "Enter the value of you choice: " << endl;
            cin >> value;
            s.push(value);
            break;
        case 5:
            cout << "The value " << s.pop()<<" is poped " << endl;
            break;
        case 6:
            if (s.isEmpty())
            {
                cout<<"The stack is empty"<<endl;
            }
            else
            {
                cout <<"The stack is not empty "<<endl
            ;
            }
            
            break;
        case 7:
            if(s.isFull())
                cout<<"The stack is full"<<endl;
            else
                cout<<"The stack is not full"<<endl;
            break;
        case 8:
            cout << "Total elements in the stack is " << s.count() << endl;
            break;
        case 9:
            system("cls");
            break;

        default:
            cout << "Please choose an appropriate option" << endl;
            break;
        }

    } while (option != 0);
    return 0;
}
