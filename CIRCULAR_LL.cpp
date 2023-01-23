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

        cout << "The memory is freed for node having data : " << value << endl;
    }
};

// INSERT THE NODE AT HEAD
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *nodeToInsert = new Node(data);

    if (head == NULL)
    {
        nodeToInsert->next = nodeToInsert;
        head = nodeToInsert;
        tail = head;
        return;
    }
    /*
    // using only the head pointer without tail...
    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = nodeToInsert;
    */

    tail->next = nodeToInsert; //   temp->next = nodeToInsert;  //

    nodeToInsert->next = head;
    head = nodeToInsert;
}

// INSERT THE NODE AT TAIL
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = new Node(data);

    tail->next = temp;
    temp->next = head;
    tail = temp;
}

// INSERT THE NODE IN BETWEEN
void insertInBetween(Node *&head, Node *tail, int element, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, tail, data);
        return;
    }
    Node *nodeToInsert = new Node(data);
    Node *curr = head;

    while (curr->data != element && curr->next != head)
    {
        curr = curr->next;
    }

    if (curr->next == head)
    {
        insertAtTail(head, tail, data);
        return;
    }

    nodeToInsert->next = curr->next;
    curr->next = nodeToInsert;
}

// DELETE NODE FROM LINKED LIST

void deleteNode(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Cannot be deleted as the list is empty" << endl;
        return;
    }
    else
    {
        Node *prev = head;
        Node *curr = prev->next;

        while (curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        {
            head = NULL;
        }
        else if (head == curr)
        {
            head = curr->next;
        }

        delete curr;
    }
}

// PRINT THE LINKED LIST
void printLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "Cannot print an empty list.." << endl;
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
   
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
   
    printLL(head);

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);
   
    printLL(head);

    deleteNode(head, 10);
   
    insertInBetween(head, tail, 30, 25);
    insertInBetween(head, tail, 1, 100);
   
    printLL(head);

    return 0;
}
