#include <bits/stdc++.h>
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

    ~Node()
    {
        int val = this->data;

        if (this->next != NULL && this->prev != NULL)
        {
            this->next = NULL;
            this->prev = NULL;
            delete this->next;
            delete this->prev;
        }
        cout << " The memory freed of element : " << val << endl;
    }
};

// Get the length of the linked list
int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

// PRINT NODES
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// INSERTION
// Insert at head
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

// Insert at tail
void insertAtTail(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);

    if (head == NULL)
    {
        head = nodeToInsert;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Insert in between
void insertInBetween(Node *&head, int data, int pos)
{
    if (pos == 1 || head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    if (pos == (getLength(head) + 1))
    {
        insertAtTail(head, data);
        return;
    }

    Node *nodeToAdd = new Node(data);
    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    nodeToAdd->next = temp->next;
    temp->next->prev = nodeToAdd;
    temp->next = nodeToAdd;
    nodeToAdd->prev = temp;
}

// Delete Node
void deleteNode(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
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
        if (curr->next != NULL)
        {
            curr->next->prev = prev;
        }
        delete curr;
    }
}

int main()
{
    Node *head = NULL;

    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printLL(head);
    cout << getLength(head) << endl;

    insertAtTail(head, 50);
    insertAtTail(head, 60);
    printLL(head);
    cout << getLength(head) << endl;

    insertInBetween(head, 500, 5);
    printLL(head);

    deleteNode(head, 4);
    cout << getLength(head) << endl;
    printLL(head);

    return 0;
}
