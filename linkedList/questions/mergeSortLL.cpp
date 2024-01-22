// merge sort on linked list

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

Node *merge(Node *head1, Node *head2)
{
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }

    // if there is only one node in the first list then head1->next will be nullptr, so it wont enter the while loop and return head1
    if (head1->next == nullptr)
    {
        head1->next = head2;
        return head1;
    }

    Node *prev = head1;
    Node *curr = head1->next ;
    Node *temp = head2;

    while (curr != nullptr && temp != nullptr)
    {
        if (curr->data <= temp->data)
        {
            prev = curr;
            curr = curr->next;

            if (curr == nullptr)
            {
                prev->next = temp;
                break; // break out of the curr->data <= temp->data loop but not the while loop
            }
        }
        else
        {
            prev->next = temp; // prev points to the temp node
            temp = temp->next; // temp changes to its next node in the other list
            prev = prev->next; // prev changes to the temp node
            prev->next = curr; // prev->next points to the curr node
        }
    }
    return head1;
}

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // find the middle of the linked list using slow and fast pointer
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next; // head of the second linked list
    slow->next = nullptr; // break the link between the two linked lists


    // merge sort on both the linked lists using recursive calls
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    return merge(head1, head2);
}

