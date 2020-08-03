#include <iostream>
using namespace std;

class Node
{
public:
    int key, data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    CircularLinkedList(Node *n)
    {
        head = n;
    }

    Node *NodeExists(int k)
    {
        Node *temp = head;
        Node *ptr = NULL;
        if (temp == NULL)
        {
            return ptr;
        }
        else
        {
            do // we used do while because this needs to run at least once to step out of the condition "while(temp!=head)" because its a circular linked list its next will link back to itself as it is the very first node in the whole list.
            {
                if (temp->key == k)
                {
                    ptr = temp;
                }
                temp = temp->next;
            } while (temp != head);
            return ptr;
        }
    }

    void AppendNode(Node *n)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node appended successfully" << endl;
            }
            else
            {
                Node *ptr = head;
                while ((ptr->next) != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                cout << "Node appended successfully" << endl;
            }
        }
    }

    void PrependNode(Node *n)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists. Try with a different key value." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node Prepended successfully" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                head=n;
                cout << "Node Prepended successfully" << endl;
            }
        }
    }
    // Insert node with the help of the previous node
    void InsertNode(int k, Node *n)
    {
        Node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            head=n;
            n->next=head;
            cout<<"Node inserted"<<endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists. Try something with a different key value" << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    n->next = head;
                    ptr->next = n;
                    cout << "Node inserted." << endl;
                }
                else
                {
                    Node *nextptr = ptr->next;
                    n->next = nextptr;
                    ptr->next = n;
                    cout << "Node inserted." << endl;
                }
            }
        }
    }
    void DeleteNode(int k)
    {
        Node *ptr = NodeExists(k);
        if (ptr == NULL)
        {
            cout << "The list is empty.";
        }
        else
        {
            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Node unlinked.\nThe list is empty..." << endl;
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr->next = head->next;
                    head = head->next;
                    cout << "Node unlinked" << endl;
                }
            }
            else
            {
                Node *prevptr = head;
                Node *currentptr = head->next;
                Node *temp = NULL;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                prevptr->next = temp->next;
                cout << "Node unlinked" << endl;
            }
        }
    }

    void UpdateNode(int k, int d)
    {
        Node *ptr = NodeExists(k);
        if (ptr->key == k)
        {
            ptr->data = d;
            cout << "Node updated successfully" << endl;
        }
        else
        {
            cout << "Node doesnot exists. Cannot update node" << endl;
        }
    }

    void PrintNode()
    {
        if (head != NULL)
        {
            cout << "The circular linked list is:" << endl;
            Node *temp = head;
            do
            {
                cout << "( " << temp->key << ", " << temp->data << " ) -->>";
                temp = temp->next;
            }while (temp != head);
            
        }
        else
        {
            cout << "The list is empty" << endl;
        }
    }
};
int main()
{
    CircularLinkedList c;
    int k1, d, k, option;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;
        cin >> option;
        Node *n1 = new Node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node function called\nEnter the key and data of the new node:";
            cin >> k >> d;
            n1->key = k;
            n1->data = d;
            c.AppendNode(n1);
            break;
        case 2:
            cout << "Prepend Node function called\nEnter the key and data of the new node:";
            cin >> k >> d;
            n1->key = k;
            n1->data = d;
            c.PrependNode(n1);
            break;
        case 3:
            cout << "Insert Node function called\nEnter the key after which you want to insert a new node:";
            cin >> k1;
            cout << "Enter the key and data of the new node:" << endl;
            cin >> k >> d;
            n1->key = k;
            n1->data = d;
            c.InsertNode(k1, n1);
            break;
        case 4:
            cout << "Delete Node function called\nEnter the key of the node which you want to delete:";
            cin >> k1;
            c.DeleteNode(k1);
            break;
        case 5:
            cout << "Update Node function called\nEnter the key of the node and enter the data you want to insert in it:";
            cin >> k >> d;
            c.UpdateNode(k, d);
            break;
        case 6:
            c.PrintNode();
            break;
        case 7:
            system("cls");
            break;

        default:
            cout << "Please enter the correct option" << endl;
            break;
        }
    } while (option != 0);
    return 0;
}
