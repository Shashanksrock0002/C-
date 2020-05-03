/* SIngy linked list
Operations
1.apeendNode()
2.prependNode()
3.insertNodeAfter()
4.deleteNodebyKey()
5.updateNodebyKey()
6.print()
*/
#include <iostream>
using namespace std;
/* lets create node class and then we will create singly link list class
using this Singlylink list clas we will all the nodes
*/

class Node
{
public:
    int key;
    int data;
    Node *next;
    //this is structre of the object
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
class Singlylinkedlist
{
public:
    Node *head;
    Singlylinkedlist()
    {
        head = NULL;
    }
    Singlylinkedlist(Node *n)
    {
        head = n;
    }
    //1.checking  if node with same key.
    Node *nodeExist(int k)
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
    // 2.Appending a node

    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            /*from here as return type of node exist is a node so  if that 
        method gives null as output then only we can append a node with the key,
        that is no such node exist with this key.*/
            cout << "Node Already exist of the key :" << n->key << "Append with another key" << endl;
        }
        else
        {
            if (head == NULL)
            {
                /*Head will be null only  if it is not pointing to any of the
                node as the node consist of 2 things key,value and adress to next
                element,if that adress is null it means there is only one thing  */
                head = n;
                cout << "Node appended 1" << endl;
            }
            else
            { /* Now there is some value in head pointer so it means linked 
            list is formed and now we need to apply actual algorithm of appending
            now we have to acess the last node(after inserting second last) 
            and store the adress of newly created node into that node so that 
            linked list is formed  */
                cout << '1';
                Node *ptr = head;
                //Initialisation of pointer variable
                for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
                { /*This is code for traversal */
                    1;
                }
                ptr->next = n;

                n->next = NULL;
                /*After finding the point where the address of next node is absent
                we said that okay now adress of the next node will be n
                */
                cout << "NODE APPENDED Me2" << endl;
            }
        }
    }
    // 3.Prepending the node
    void prependNode(Node *n)
    { /*This happens in start , in this case we will append node at the start*/
        if (nodeExist(n->key) != NULL)
        {
            /*from here as return type of node exist is a node so  if that 
        method gives null as output then only we can append a node with the key,
        that is no such node exist with this key.*/
            cout << "Node Already exist of the key" << n->key << "Append with another key" << endl;
        }
        else
        {
            n->next = head;
            /*In this case we need not to traverse as we know that address of next node
        where we want to insert is head*/
            head = n;
            //now we have changed the head pointer as n
            cout << "Node Prepended" << endl;
        }
    }
    //4.Insert a node after a particular node in list
    void insertNodeAfter(int k, Node *n)
    {
        /*in this method we will pass key value after which we want to 
        insert the particular node*/
        Node *ptr = nodeExist(k);
        /*Since we need to acess the node also so we are using this new vaibale
        known as ptr as it will either return null, if that key doenot exist
        or the node itself so that we can carry on further steps*/
        if (ptr == NULL)
        {
            cout << "N0 node exist with key value" << k << endl;
        }
        else
        {
            if (nodeExist(n->key) != NULL)
            {
                /*from here as return type of node exist is a node so  if that 
        method gives null as output then only we can append a node with the key,
        that is no such node exist with this key.*/
                cout << "Node Already exist of the key" << n->key << "Append with another key" << endl;
            }
            else
            {
                n->next = ptr->next;
                // linlking the new node(0) to the next(+1) to the node where we want to insert
                ptr->next = n;
                //linking the old (-1 node ) to the new inserted noe
            }
        }
    }
    // 5.Deleting node by particular key
    void deleteNode(int k)
    {
        if (head == NULL)
        {
            cout << "Alreaddy empty" << endl;
        }
        else if (head != NULL)
        {
            // if the key is to delete the head node itself
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unliked with key value" << k << endl;
            }
            else
            { /*1.First we need to traverse till the node where its key value is k
             2.we will use 3 pointers
            Ist storing a address before the key:prepointer
            IInd storing a adress of the key:currentpointer
            IIrd for an ingerneral variable:temp
            3.
            */
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        //if we have founded the value then we set temp as its adress
                        currentptr = NULL;
                        //giives current pointer as null to comeout of this loop
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        //if ye not found the node then iterate one more step
                        currentptr = currentptr->next;
                        //here also we will iterate
                    }
                }
                //after coming out of the loop
                //temp will have the adress of node to be replaced
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    //here we have linked the previous pointer of the node which is to be delted
                    // to the next pointer of node
                    cout << "node Unlinked with the key value : " << k << endl;
                }
                else
                {
                    //in this case the key value is not found
                    //so
                    cout << "Key value not found: " << k << endl;
                }
            }
        }
    }
    // 6.Update by key
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated" << endl;
        }
        else
        {
            cout << "Node with this key does not exist : " << k << endl;
        }
    }
    // 7.printing entire linkedlist
    void printlist()
    {
        if (head == NULL)
        {
            cout << "No nodes in Singly Linked List: ";
        }
        else
        {
            cout << endl
                 << "Singly linked list value";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") --> ";
                temp = temp->next;
            }
        }
    }
};
int main()
{
    Singlylinkedlist s;
    Node first(1, 7);
    Node second(1, 7);
    Node tail(3, 5);

    s.appendNode(&first);

    s.appendNode(&tail);
    // s.appendNode(tail);
    // s.printlist();
    s.printlist();

    cout << s.nodeExist(1);
}
