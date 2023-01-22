#include <bits/stdc++.h>
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

        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << " the memory freed is of node having value : " << value << endl;
    }
};

// INSERTION
//  Insert The Node at the start
void insertAtHead(Node *&head, int data)
{
    Node *nodeToAdd = new Node(data);
    nodeToAdd->next = head;
    head = nodeToAdd;
}
// Insert The Node at the end
void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    Node *nodeToAdd = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeToAdd;
}

// Insert The Node in the middle
void insertNode(Node *&head, int data, int pos) // By default to add in last
{
    Node *nodeToAdd = new Node(data);

    if (head == NULL || pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, data);
        return;
    }

    nodeToAdd->next = temp->next;
    temp->next = nodeToAdd;
}

// DELETION IN SINGLY LL
void deleteNode(Node *&head, int pos)
{

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        // temp->next = NULL;  or writing this condition inside the destructor
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// PRINT THE LINKED LISt
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insertNode(head, 10, 1);
    insertNode(head, 20, 2);
    insertNode(head, 30, 1);
    insertNode(head, 40, 3);
    insertNode(head, 50, 4);
    insertAtHead(head, 0);
    insertAtTail(head, 100);

    printLinkedList(head);

    deleteNode(head, 1);
    printLinkedList(head);

    deleteNode(head, 6);
    printLinkedList(head);

    return 0;
}
