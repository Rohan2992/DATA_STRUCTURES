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
        int val = this->data;
        cout << "The pointer freed is of mem location " << this->data << endl;
    }
};

void make_LL(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayLL(Node *head)
{
    if (head == NULL)
    {
        cout << "Error : Cannot display empty list.." << endl;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *reverseInK(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    int cnt = 0, k = 2;

    Node *prev = NULL;
    Node *curr = head;
    Node *Next = NULL;

    while (curr != NULL && cnt < k)
    {
        Next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = Next;
        cnt++;
    }
    if (Next != NULL)
        head->next = reverseInK(Next);
    return prev;
}

void makeLLCircular(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}

bool isCircular(Node *head)
{
    if (head == NULL)
        return true;
    Node *temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;
    if (temp == head)
        return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif

    Node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        int data;
        cin >> data;
        make_LL(head, data);
    }

    displayLL(head);
    cout << endl;

    // Node *temp = reverseInK(head);
    // displayLL(temp);

    makeLLCircular(head);

    if (isCircular(head))
    {
        cout << "The linked list is circular..." << endl;
    }
    else
    {
        cout << "The linked list is not circular..." << endl;
    }

    return 0;
}