#include <iostream>
#include <map>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int flag;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBegin(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    newNode->flag = 0;
    head = newNode;
}

void print(Node *head)
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
    Node *temp = new Node(data);
    tail->next = temp;
    temp->flag = 0;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtBegin(tail, head, data);
        return;
    }
    Node *temp = head;
    temp->flag = 0;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (tail->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToinsert = new Node(data);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
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
            prev->next = NULL;
            tail = prev;
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

Node *kReverse(Node *head, int k)
{
    // call for base case
    if (head == NULL)
    {
        return NULL;
    }

    // resolving first two nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    // recursion call
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }
    return prev;
}

// time complexity O(n) and space complexity O(n) ---> not that optimised
bool isLoopPresent(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// using floyd's cycle detection algorithm
Node *floydsDetection(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

Node *startingNodeCycle(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *meet = floydsDetection(head);
    Node *slow = head;
    while (slow != meet)
    {
        slow = slow->next;
        meet = meet->next;
    }
    return slow;
}

// remove loop logic
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startofLoop = startingNodeCycle(head);
    Node *temp = startofLoop;
    while (temp->next != startofLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

bool detectLoopApp1(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->flag == 1)
        {
            return true;
        }

        temp->flag = 1;
        temp = temp->next;
    }
    return false;
}

Node *removeDuplicateUnsorted(Node *&head)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        Node *temp = curr;
        while (temp->next != NULL)
        {
            if (curr->data == temp->next->data)
            {
                Node *next_next = temp->next;
                temp->next = temp->next->next;
                delete (next_next);
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

Node *removeDuplicateMap(Node *&head)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    Node *prev = NULL;
    Node *forward = NULL;
    map<int, bool> visited;

    while (temp != NULL)
    {
        if (visited[temp->data] == true)
        {
            forward = temp->next;
            prev->next = forward;
            delete temp;
            temp = forward;
        }
        else
        {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// optimised --> time complexity O(n) and space complexity O(1)
Node *sort0_1_2(Node *head)
{
    if (head == NULL)
        return NULL;

    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;

        else if (temp->data == 1)
            one++;

        else if (temp->data == 2)
            two++;

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zero != 0)
        {
            temp->data = 0;
            zero--;
        }
        else if (one != 0)
        {
            temp->data = 1;
            one--;
        }
        else if (two != 0)
        {
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }

    return head;
}

void insertTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortLL0_1_2(Node *head)
{
    Node *zeroNode = new Node(-1);
    Node *zeroTail = zeroNode;
    Node *oneNode = new Node(-1);
    Node *oneTail = oneNode;
    Node *twoNode = new Node(-1);
    Node *twoTail = twoNode;

    Node *curr = head;

    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
            insertTail(zeroTail, curr);

        else if (value == 1)
            insertTail(oneTail, curr);

        else if (value == 2)
            insertTail(twoTail, curr);

        curr = curr->next;
    }

    // merging 3 sublist

    if (oneNode->next != NULL)
        zeroTail->next = oneNode->next;

    else
        zeroTail->next = twoNode->next;

    oneTail->next = twoNode->next;
    twoTail->next = NULL;

    // setting head;
    head = zeroNode->next;

    // deleting dummy nodes
    delete oneNode;
    delete twoNode;
    delete zeroNode;

    return head;
}


//kept here just for reference purpose for future
void merge2SortedLinkedlist(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return;

    if (head2 == NULL)
        return;

    Node *curr1 = head1;
    Node *forward1 = curr1->next;
    Node *curr2 = head2;
    Node *forward2 = NULL;

    while (forward1 != NULL)
    {
        if (curr1->data <= curr2->data && curr1->next->data >= curr2->data)
        {
            curr1->next = curr2;
            forward2 = curr2->next;
            curr2->next = forward1;
            curr1 = curr2;
            curr2 = forward2;
        }
        else
        {
            curr1 = forward1;
            forward1 = forward1->next;
            if (forward1 == NULL)
            {
                curr1->next = curr2;
                return;
            }
        }
    }
    return;
}


//O(n),O(n) -> not so optimized
bool isPalindrome(Node * head){
    if(head == NULL)
    return false;
     
    vector<int> store;

    Node * temp = head;
    while(temp!=NULL){
        store.push_back(temp->data);
        temp = temp->next;
    }

    //implementing two pointer approach
    int start = 0;
    int end = store.size()-1;

    while(start<=end){
        if(store[start]!=store[end]){
           return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
} 

/*
// check palindrome
  Node * getMid(Node * head){
        if(head == NULL)
        return NULL;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node* reverse(Node * head){
        Node* curr = head;
        Node *prev = NULL;
        Node * forward = NULL;
        
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
 //O(N),(1) -> more optimised
 bool isPalindrome(Node *head){
        if(head->next == NULL)
        return true;
        
        //reached at the middle of the linkedlist
        Node* mid = getMid(head);
        
        Node* temp = mid->next;
        //function called for reversing the list (half)
        mid->next = reverse(temp);
        
        
        Node* head1 = head;
        Node* head2 = mid->next;
        
        while(head2!=NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
 }
*/

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    insertAtTail(head, tail, 2);
    // print(head);

    insertAtTail(head, tail, 2);
    // print(head);

    insertAtTail(head, tail, 1);
    // print(head);

    // insertAtPosition(tail, head, 4, 3);
    // print(head);

    // insertAtPosition(tail, head, 1, 6);
    print(head);

    // cout << head->data << endl;
    // cout << tail->data << endl;

    // tail->next = head->next;
    // print(head);
    // deleteNode(head, tail, 3);
    // print(hea  d);

    // deleteNode(head, tail, 5);
    // print(head);

    //  if (isCircular(tail))
    // {
    //     cout << "Linked list is circular in nature" << endl;
    // }
    // else
    // {
    //     cout << "Linked list is not circular in nature" << endl;
    // }

    // cout << head->data << endl;
    // cout << tail->data << endl;

    // kReverse(head, 2);
    // print(head);

    // if (isLoopPresent(head))
    // {
    //     cout << "Loop is there" << endl;
    // }
    // else
    // {
    //     cout << "loop is absent" << endl;
    // }

    // if (floydsDetection(head) != NULL)
    // {
    //     cout << "cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "cycle is absent" << endl;
    // }

    // Node *temp = floydsDetection(head);
    // cout << temp->data << endl;

    // // returns the starting node of loop
    // Node *tempValue = startingNodeCycle(head);
    // cout << "Starting node of cycle is " << tempValue->data << endl;

    // removeLoop(head);
    // cout << "loop removed from the linkedlist" << endl;
    // print(head);

    // if (detectLoopApp1(head))
    // {
    //     cout << "loop exists" << endl;
    // }
    // else
    // {
    //     cout << "Loop doesnt exists" << endl;
    // }

    // removeDuplicateUnsorted(head);
    // print(head);

    // removeDuplicateMap(head);
    // print(head);

    // Node *newHead = sort0_1_2(head);
    // print(newHead);

    // Node *head1 = sortLL0_1_2(head);
    // print(head1);

    if(isPalindrome(head)){
        cout<<"LL is palindrome"<<endl;
    }
    else{
        cout<<"LL is not palindrome"<<endl;
    }

    return 0;
}
