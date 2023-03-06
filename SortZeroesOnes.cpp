#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// class Node
// {
// public:
//     T data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }

//     ~Node()
//     {
//         if (this->next != NULL)
//         {
//             this->next = NULL;
//         }
//         cout << "Memory Freed for " << this->data << endl;
//     }
// };

void MakeLL(Node<int> *&head, int data)
{
    Node<int> *newNode = new Node<int>(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node<int> *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayLL(Node<int> *head)
{
    if (head == NULL)
    {
        cout << " Cannot display Empty List" << endl;
        return;
    }
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

// void Sort(Node *head)
// {
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//             zeroCount++;
//         else if (temp->data == 1)
//             oneCount++;
//         else if (temp->data == 2)
//             twoCount++;
//         temp = temp->next;
//     }

//     temp = head;

//     while (temp != NULL)
//     {
//         if (zeroCount != 0)
//         {
//             temp->data = 0;
//             zeroCount--;
//         }
//         else if (oneCount != 0)
//         {
//             temp->data = 1;
//             oneCount--;
//         }
//         else if (twoCount != 0)
//         {

//             temp->data = 2;
//             twoCount--;
//         }
//         temp = temp->next;
//     }
// }

void insertAtTail(Node<int> *&tail, Node<int> *curr)
{
    // cout << " Data : " << curr->data << " "
    //      << "Tail : " << tail->data << endl;
    tail->next = curr;
    tail = curr;
}

// void Sort2(Node *head)
// {
//     Node *zeroHead = new Node(-1);
//     Node *oneHead = new Node(-1);
//     Node *twoHead = new Node(-1);

//     Node *zeroTail = zeroHead;
//     Node *oneTail = oneHead;
//     Node *twoTail = twoHead;

//     Node *temp = head;

//     while (temp != NULL)
//     {
//         int value = temp->data;
//         if (value == 0)
//         {
//             insertAtTail(zeroTail, temp);
//         }
//         else if (value == 1)
//         {
//             insertAtTail(oneTail, temp);
//         }
//         else if (value == 2)
//         {
//             insertAtTail(twoTail, temp);
//         }
//         temp = temp->next;
//     }

//     // displayLL(zeroHead);
//     // displayLL(oneHead);
//     // displayLL(twoHead);

//     if (oneHead->next != NULL)
//     {
//         zeroTail->next = oneHead->next;
//         oneTail->next = twoHead->next;
//     }
//     else
//     {
//         zeroTail->next = twoHead->next;
//     }

//     twoTail->next = NULL;

//     head = zeroHead->next;

//     delete zeroHead;
//     delete oneHead;
//     delete twoHead;
// }

Node<int> *solve(Node<int> *first, Node<int> *second)
{
    Node<int> *curr1 = first;
    Node<int> *next1 = first->next;
    Node<int> *curr2 = second;
    Node<int> *next2 = second->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = curr1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node<int> *mergeSortedLL(Node<int> *first, Node<int> *second)
{

    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

Node<int> *mergeUsingRecursion(Node<int> *first, Node<int> *second)
{
    Node<int> *result = NULL;
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
    {
        result = first;
        result->next = mergeUsingRecursion(first->next, second);
        // return result;
    }
    else if (first->data > second->data)
    {
        result = second;
        result->next = mergeUsingRecursion(first, second->next);
        // return result;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /**
     * #ifndef ONLINE_JUDGE
     *     freopen("../input.txt", "r", stdin);
     *     freopen("../output.txt", "w", stdout);
     * #endif
     */

    Node<int> *head1 = NULL;
    Node<int> *head2 = NULL;

    MakeLL(head1, 1);
    MakeLL(head1, 3);
    MakeLL(head1, 5);
    MakeLL(head1, 7);

    MakeLL(head2, 2);
    MakeLL(head2, 4);
    MakeLL(head2, 6);
    MakeLL(head2, 8);

    // displayLL(head);
    // Sort(head);
    // displayLL(head);
    // Sort2(head1);
    // Sort2(head2);

    displayLL(head1);
    displayLL(head2);

    // Node<int> *head = mergeSortedLL(head1, head2);
    Node<int> *head = mergeUsingRecursion(head1, head2);
    displayLL(head);

    return 0;
}