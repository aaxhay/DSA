#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtbegin(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAnyPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtbegin(head, tail, data);
        return;
    }
    Node *nodeToinsert = new Node(data);
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            curr->prev = NULL;
            prev->next = curr->next;
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void reverseDoubly(Node* &head){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        return;
    }

    Node* curr = head;
    Node* previous = NULL;
    Node* forward = NULL;
        while(curr!=NULL){
        forward = curr->next;
        curr->prev = curr->next;
        curr->next = previous;
        previous = curr;
        curr = forward;
        }
        head = previous;
}

// Node* reverseDoublyLinkedList(Node* head) {
//     if(head == NULL || head -> next == NULL) {
//         return head;
//     }

//     Node* newHead = reverseDoublyLinkedList(head -> next);
//     head -> prev = head -> next;
//     head -> next -> next = head;
//     head -> next = NULL;

//     return newHead;
// }

Node* reverse_LL(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = reverse_LL(head->next);
    head->next->prev=head->next->next;
    head->next->next=head;
    head->prev=head->next;
    head->next=NULL;
    return temp;
}

int main(void)
{
    Node *node1 = new Node(8);
    Node *head = node1;
    Node *tail = node1;
    // insertAtbegin(head, 12);
    // print(head);

    insertAtTail(head, tail, 12);
    print(head);

    insertAtTail(head, tail, 13);
    print(head);

    insertAtTail(head, tail, 14);
    print(head);

    insertAtTail(head, tail, 15);
    print(head);

    insertAtAnyPosition(head, tail, 5, 16);
    print(head);

    //deleteNode(head, tail, 5);
    //print(head);

    //deleteNode(head, tail, 1);
    //print(head);

    // cout << head->data << endl;
    // cout << tail->data << endl;
     
    //reverse of doubly linkedlist
    reverseDoubly(head);
    print(head);
    return 0;
}
