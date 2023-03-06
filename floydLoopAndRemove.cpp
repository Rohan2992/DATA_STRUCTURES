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
        if (this->next)
        {
            this->next = NULL;
        }
        cout << "Memory Freed" << endl;
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

void makeLLCircular(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head->next->next;
}

bool hasLoop(Node *head)
{
    Node *temp = head;
    set<Node *> hashSet;
    while (temp != NULL)
    {
        if (hashSet.find(temp) != hashSet.end())
        {
            return true;
        }
        hashSet[temp]++;
        // hashSet.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool DetectCycle(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    while (head != NULL)
    {
        if (visited[head] == true)
        {
            cout << "Cycle detected at " << head->data << endl;
            return true;
        }
        if (visited[head] == false)
            visited[head] = true;
        head = head->next;
    }
    return false;
    /*
    if (head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
    */
}

Node *FloydCycle(Node *head)
{

    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}

Node *startingOfLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *resultOfFloyd = FloydCycle(head);
    if (resultOfFloyd != NULL)
    {
        Node *slow = head;
        while (slow != resultOfFloyd)
        {
            slow = slow->next;
            resultOfFloyd = resultOfFloyd->next;
        }
        return slow;
    }
}

void removeLoop(Node *&head)
{
    if (head == NULL)
        return;

    Node *startingPoint = startingOfLoop(head);
    Node *temp = startingPoint;
    while (temp->next != startingPoint)
        temp = temp->next;

    temp->next = NULL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        int data;
        cin >> data;
        make_LL(head, data);
    }

    // displayLL(head);

    makeLLCircular(head);
    if (hasLoop(head))
        cout << "Cycle detected" << endl;
    else
        cout << "Cycle not detected" << endl;

    // Node *temp = startingOfLoop(head);
    // cout << temp->data << endl;
    // removeLoop(head);
    // displayLL(head);
    return 0;
}