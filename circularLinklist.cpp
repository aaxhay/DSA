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
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        while (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }

    return true;
}

int getLength(Node *tail)
{
    if (tail == NULL)
        return 0;

    Node *temp = tail;
    int cnt = 1;
    while (temp->next != tail)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

Node *split_LL(Node *tail)
{
    if (tail == NULL)
        return NULL;

    Node *fast = tail->next;
    Node *slow = tail;

    while (fast->next != tail)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    Node *head2 = slow->next;
    fast->next = head2;
    slow->next = tail;
    return head2;
}



int main()
{

    Node *tail = NULL;

    insertNode(tail, 4, 1);
    print(tail);

    insertNode(tail, 1, 2);
    print(tail);

    insertNode(tail, 2, 6);
    print(tail);

    insertNode(tail, 6, 8);
    print(tail);

    insertNode(tail, 2, 3);
    print(tail);

    insertNode(tail, 8, 9);
    print(tail);

    // deleteNode(tail,2);
    // print(tail);
    // if (isCircular(tail))
    // {
    //     cout << "Linked list is circular in nature" << endl;
    // }
    // else
    // {
    //     cout << "Linked list is not circular in nature" << endl;
    // }

    int len = getLength(tail);
    cout<<len<<endl;

    Node *newNode = split_LL(tail);
    print(tail);
    print(newNode);
    return 0;
}