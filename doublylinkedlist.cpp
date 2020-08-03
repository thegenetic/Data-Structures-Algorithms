#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *pre;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        pre = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoubleLinkedList
{
public:
    Node *head;
    DoubleLinkedList()
    {
        head = NULL;
    }
    DoubleLinkedList(Node *n)
    {
        head = n;
    }

    Node *NodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void AppendNode(Node *n)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value " << n->key << ". Cannot append the same node. Try appending a new node....." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout<<"Node appended"<<endl;
            }
            else
            {
                Node *ptr = head;
                while ((ptr->next) != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->pre = ptr;
                cout << "Node appended succesfully" << endl;
            }
        }
    }

    void PrependNode(Node *n)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value " << n->key << ". Cannot append the same node. Try appending a new node....." << endl;
        }
        else
        {
            Node *ptr = head; // changed: my own codes
            n->next = ptr;
            head = n;
            ptr->pre = head;
            cout << "Node prepended succesfully" << endl;
        }
    }

    void InsertNode(int k, Node *n)
    {
        Node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value " << n->key << ". Try a new node with different key value." << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with a key value " << k << ". Try inserting a new key " << endl;
            }
            else
            {
                Node *pos = ptr->next; // storing the adress of the previous node
                if (pos != NULL)       // to insert in any position
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    n->pre = ptr;
                    pos->pre - n;
                    cout << "Node inserted " << endl;
                }
                else // to insert at the very last cell
                {
                    ptr->next = n;
                    n->pre = ptr;
                    cout << "Node inserted" << endl;
                }
            }
        }
    }

    void DeleteNodeByKey(int k)
    {
        Node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            cout << "There is no node in the list please insert some node first and then try again" << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked or deleted succesfully" << endl;
            }
            else
            {
                Node *nextptr = ptr->next;
                Node *prevptr = ptr->pre;
                if (nextptr == NULL) // Deleting the very last node
                {
                    prevptr->next = NULL;
                    cout << "Node unlinked with key value " << k << endl;
                }
                else
                {
                    prevptr->next = nextptr;
                    nextptr->pre = prevptr;
                    cout << "Node unlinked with key value " << k << endl;
                }
            }
        }
    }

    void UpdateNode(int k, int d)
    {
        Node *ptr = NodeExists(k);
        if (head==NULL)
        {
            cout<<"The list is empty"<<endl;
        }
        
        else if(ptr == NULL)
        {
            cout << "There is no node with key value " << k << ". Please try with any other key" << endl;
        }
        else
        {
            ptr->data = d;
            cout << "Node updated" << endl;
        }
    }

    int Count(){
        int count=0;
        Node * temp=head;
        while (temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }

    void printlist()
    {
        if (head == NULL)
        {
            cout << "There is no node available" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << " ," << temp->data << " )"
                     << "<<--->>";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    int data, key, k, option;
    DoubleLinkedList d;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Count()" << endl;
        cout << "8. Clear Screen" <<endl<< endl;
             

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append function called\nEnter the key and data you want to add respectively" << endl;
            cin >> key >> data;
            n1->key = key;
            n1->data = data;
            d.AppendNode(n1);
            break;
        case 2:
            cout << "Prepend function called\nEnter the key and data you want to add respectively" << endl;
            cin >> key >> data;
            n1->key = key;
            n1->data = data;
            d.PrependNode(n1);
            break;
        case 3:
            cout << "Insert node function called\nEnter the key of the node after which you want to insert a new node" << endl;
            cin >> k;
            cout << "Enter the value of the new key and data respectively of the new node" << endl;
            cin >> key >> data;
            n1->key = key;
            n1->data = data;
            d.InsertNode(k, n1);
            break;
        case 4:
            cout << "Delete Node function called\nEnter the key of the node which you want to delete" << endl;
            cin >> k;
            d.DeleteNodeByKey(k);
            break;
        case 5:
            cout << "Update node function called\nEnter the key and the data of the node which you want to update" << endl;
            cin >> key >> data;
            d.UpdateNode(key, data);
            break;
        case 6:
            cout << "Print function called\nThe Double Linke List is:" << endl;
            d.printlist();
            break;
        case 7:
            cout<<"Count function called\nThere are total "<<d.Count()<<" elements in the list"<<endl;
            break;
        case 8:
            system("cls");
            break;

        default:
            cout << "Enter correct option number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
