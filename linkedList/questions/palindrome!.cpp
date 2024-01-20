// check if the linked list is palindrome or not

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

bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    Node* curr = head;
    Node* tail = head;
    
    // Find the last node of the linked list
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    while (curr != tail && curr->next != tail) {
        if (curr->data == tail->data) {
            curr = curr->next;
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            tail = temp;
        } else {
            return false;
        }
    }
    
    // Check the last pair of nodes outside the loop
    return (curr->data == tail->data);
}


// reverse the linked list
Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = head->next;
    while (curr != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next != nullptr)
        {
            next = next->next;
        }
    }
    return prev;
}

// by middle reverse
bool isPalindrome2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;
    Node *curr = mid->next;
    mid->next = reverse(curr);

    Node* head1 = head;
    Node* head2 = mid->next;

    while(head1 != nullptr && head2 != nullptr){
        if(head1->data == head2->data){
            head1 = head1->next;
            head2 = head2->next;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    printList(head);

    cout << isPalindrome(head) << endl;

    cout << isPalindrome2(head) << endl;

    return 0 ;
}