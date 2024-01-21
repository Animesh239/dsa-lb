// there is a linked list with each node having a random pointer and a next pointer. Clone the linked list.

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};

void printList(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// approach 1 : creating maps of the original linked list and the cloned linked list and then assigning the random pointers of the cloned linked list using the map of the original linked list

Node *clone(Node *head)
{
    // step 1: create a clone list with only the next pointers
    Node *cloneHead = nullptr;
    Node *cloneTail = nullptr;

    Node *temp = head;
    while (temp != nullptr)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2: create a map of the original list
    unordered_map<Node *, Node *> originalMap;

    Node *originalNode = head;
    Node *cloneNode = cloneHead;
    while (originalNode != nullptr)
    {
        originalMap[originalNode] = cloneNode; // originalNode is the key and cloneNode is the value
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode != nullptr)
    {
        cloneNode->random = originalMap[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

// approach 2: inserting the cloned nodes in between the original nodes and then separating the original and the cloned linked lists, changing the links

Node *clone2(Node *head)
{
    // step 1 : make a clone list
    Node *cloneHead = nullptr;
    Node *cloneTail = nullptr;

    Node *temp = head;
    while (temp != nullptr)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 : insert the cloned nodes in between the original nodes
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != nullptr)
    {
        Node *forward = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = forward;

        forward = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = forward;
    }

    // step 3 : copy the random pointers of the original nodes to the cloned nodes
    temp = head;
    while (temp != nullptr)
    {
        if (temp->next != nullptr)
        {
            temp->next->random =temp->random ? temp->random->next : temp->random;
            temp = temp->next->next;
        }
    }

    // step 4 : separate the original and the cloned linked lists (reverting step 2)
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != nullptr){
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != nullptr){
            cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
    }

    // step 5 : return the cloned linked list
    return cloneHead;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next->next;
    head->next->next->next->next->random = head->next;

    printList(head);

    Node *cloneHead = clone2(head);
    printList(cloneHead);

    return 0;
}