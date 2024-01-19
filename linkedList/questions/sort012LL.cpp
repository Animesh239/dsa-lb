// sort 0 , 1 , 2 in a linked list using the two pointer approach

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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

void sort012(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    Node *start = head;
    Node *mid = head;
    Node *right = head;
    Node *prev = nullptr;
    while (right->next != nullptr)
    {
        prev = right ;
        right = right->next;
    }
    // cout << "prev: " << prev->data << " right: " << right->data << endl;
    // now right is pointing to the last node

    while (mid != right->next)
    {
        if (mid->data == 0)
        {
            swap(start->data, mid->data);
            start = start->next;
            mid = mid->next;
            // cout << "start: " << start << " mid: " << mid << endl;
        }
        else if (mid->data == 1)
        {
            mid = mid->next;
            cout << "mid: " << mid << " right: " << right << endl;
        }
        else
        {
            swap(mid->data, right->data);
            right = prev;
            // update the prev to its previous node
            prev = head;
            while (prev->next != right)
            {
                prev = prev->next;
            }
            // cout << "right: " << right->data << endl;
        }
    }
}

int main()
{

    Node *head = new Node(0);
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(0);
    Node *fourth = new Node(1);
    Node *fifth = new Node(2);
    Node *sixth = new Node(0);
    Node *seventh = new Node(1);
    Node *eighth = new Node(2);
    Node *ninth = new Node(1);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;

    printList(head);
    sort012(head);
    printList(head);

    return 0;
}