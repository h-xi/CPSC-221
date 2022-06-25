#include <iostream>

using namespace std;

struct Node
{
    Node(int d, Node *n = NULL) : data(d), next(n) {}
    int data;
    Node *next;

    void insert(Node *&Head, int data)
    {
        Head = new Node(data, Head);
    }

    void insertAtBack(Node *Head, int data)
    {
        if (Head == NULL)
        {
            Head = new Node(data, Head);
            return;
        }
        if (Head->next == NULL)
        {
            Head->next = new Node(data, NULL);
            return;
        }
        insertAtBack(Head->next, data);
    }
    void printReverseOdds(Node *curr)
    {
        if (curr == NULL)
        {
            return;
        }
        if (curr->next == NULL)
        {
            cout << curr->data << endl;
            return;
        }
        printReverseOdds(curr->next->next);
        cout << curr->data << endl;
    }

    Node *reverseList(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *temp = reverseList(head->next);
        head->next->next = head; // points head->next to head
        head->next = NULL;       // CRUCIAL: opens up space for head to become head->next->next in next recursive call
        return temp;
    }

    void print(Node *head)
    {
        cout << "[";
        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            cout << curr->data;
            if (curr->next != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main()
{

    Node *list1 = NULL;
    Node *list2 = NULL;
    Node *list3 = NULL;

    list1->insert(list1, 1);
    list1->insert(list1, 2);
    list1->insert(list1, 5);
    list1->insert(list1, 8);
    list1->insert(list1, 4);
    list1->print(list1);
    cout << "after reverse" << endl;
    list1 = list1->reverseList(list1);
    list1->print(list1);
    list1->insertAtBack(list1, 9);
    list1->print(list1);
}