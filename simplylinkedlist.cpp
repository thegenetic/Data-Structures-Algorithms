#include <iostream>
using namespace std;

class Node
{ // this class consists all the basic keys of the whole prg.....
public:
    int key, data;
    Node *next;
    Node()
    { // a node(botton consists these three items in it)
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

class SingleLinkedList
{ // this class consists all the main program functions..........
public:
    Node *head; // a pointer of type of class Node
    SingleLinkedList()
    {
        head = NULL; // it is the very first position of the buttons (key , data, next the linkable structures) , the very first button...........
    }
    SingleLinkedList(Node *n)
    {
        head = n;
    }
    // Checking if the node exists
    Node *NodeExists(int k)
    {
        Node *temp = NULL; // it is used to store the final value (see ahead)
        Node *ptr = head;  // stores value of head also stores the address of the button(node)
        while (ptr != NULL)
        {
            if (ptr->key == k) // Here key (helps us accessing the key value) . it initializes ptr value i.e. head value to the key  and checks if its equal with k
            {
                temp = ptr; // this will be printed finally but not the least
            }
            ptr = ptr->next; // here next helps us accessing the next values address. "Here next is a key word made by us see Node class at the top"
        }
        return temp;
    }
    // Appending or adding a node( adds a node only at the back of the list)
    void appendNode(Node *n) // Here n is the key for all the elements. "***ONLY IN THIS MEMBER fUNCTION***". It is a "pass by address"
    {
        if (NodeExists(n->key) != NULL) // This will implement only if the node exsits..
        {
            cout << "Node already exist with a key value " << n->key << ". Try appending another node with a different key value." << endl;
        }
        else // THis will implement if the node part doesn't exist...
        {
            if (head == NULL) // if the node is full empty..
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else // if the node consists some elements..
            {
                Node *ptr = head;         //we use these pointer ptr so that the actual value of head doesn't gets changed
                while (ptr->next != NULL) // This will help to move on to the next node.
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }
    //Prepending a list(adds a list only at the front of a list)
    void PrependNode(Node *n) // in all the cases this n  represented the adress of the node (because its a pointer)
    {
        if (NodeExists(n->key) != NULL)
        {
            cout << "Node already exists with a key value " << n->key << ". Try adding node with a different key value" << endl;
        }
        else
        {
            n->next = head; // here we do not need any other pointer to denote head's value because here the newly added node will be the head
            head = n;
            cout << "Node appended" << endl;
        }
    }
    //Inserting a new node in between two nodes
    void InsertNode(int k, Node *n) // k is the value of a key after which we will store the new node
    {
        Node *ptr = NodeExists(k); // Storing the value in ptr pointer casue we need it in the following conditions.
        if (ptr == NULL)
        {
            cout << "No node exists with the key value " << k << ". Try inserting a new node after a different key value." << endl;
        }
        else
        {
            if (NodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key value " << n->key << ". Try inserting a new node with a different key value." << endl;
            }
            else
            {
                n->next = ptr->next;                                               //storing the adress of the following node in the new node
                ptr->next = n;                                                     // stroing the adress of the new node in the preceeding node
                cout << "A new node inserted with a key value " << n->key << endl; // Thus we created the link between three nodes(preceeding, new, following)
            }
        }
    }
    // Deleting or unlinking a node with the help of its key
    void DeletNodeWithKey(int k)
    {
        if (head == NULL) // If head is null
        {
            cout << "The list is empty. Nothing can be unlinked" << endl;
        }
        else if (head != NULL) // If only head node is not null(only if the k value is the head value)
        {
            if (head->key == k)
            {
                head = head->next; // It means the head is initaializing itself the adress of the node next to it (and will unlink itself)
                cout << "Node unlinked with the key value " << k << endl;
            }

            else // If any other node except head node is to be unlinked
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k) // k is the value we will insert
                    {
                        temp = currentptr; // Storing currentptr's value in temp
                        currentptr = NULL; // Making it null/empty
                    }
                    else
                    {
                        prevptr = prevptr->next;       // pointing it to the next address
                        currentptr = currentptr->next; // pointing it to the next address
                    }
                }
                if (temp != NULL) // it will run after the while loop iterates
                {
                    prevptr->next = temp->next; // the preceeding node will store the address which is stored in the next of the deleted node
                    cout << "Node unlinked with the key value " << k << endl;
                }
                else
                {
                    cout << "There is no node with the key value " << k << ". Try using a different key value" << endl;
                }
            }
        }
    }
    // Updating the node
    void UpdateNode(int k, int d)
    { // k is for the key and d is for the data
        Node *ptr = NodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node is updated" << endl;
        }
        else
        {
            cout << "Node doesn't exist" << endl;
        }
    }
    // Printing node
    void PrintNode()
    {
        if (head == NULL)
        {
            cout << "The node is empty" << endl;
        }
        else
        {
            Node *temp = head;
            cout << "The single linked list is:" << endl;
            while (temp != NULL)
            {
                cout << "( " << temp->key << " , " << temp->data << " )" << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SingleLinkedList S;
    int key1, data1, k1;
    int option;
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
            cout << "Append function called\nEnter the value of the key and data you want to append respectively" << endl;
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            S.appendNode(n1);
            break;
        case 2:
            cout << "Prepend function called\nEnter the value of the key and the data you want to prepend respectively" << endl;
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            S.PrependNode(n1);
            break;
        case 3:
            cout << "Insert node function called\nEnter the value of the key of the node after which you want to insert a new node" << endl;
            cin >> k1;
            cout << "Enter the value of the key and data you want to insert respectively" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            S.InsertNode(k1, n1);
            break;
        case 4:
            cout << "Delete node function called\nEnter the value of the key you want to delete" << endl;
            cin >> key1;

            S.DeletNodeWithKey(key1);
            break;
        case 5:
            cout << "Update function called\nEnter the value of the key you want to update" << endl;
            cin >> key1;
            cout << "Enter the data: " << endl;
            cin >> data1;

            S.UpdateNode(key1, data1);
            break;
        case 6:
            cout << "Print function called" << endl;
            S.PrintNode();
            break;
        case 7:
            system("cls");
            break;

        default:
            cout << "Print a valid option number))))" << endl;
        }
    } while (option != 0);
    return 0;
}