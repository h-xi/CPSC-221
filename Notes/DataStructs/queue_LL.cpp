#include <iostream>

using namespace std;

template <class LIT>
class Queue
{
public:
    Queue();
    void peek() const;
    void enqueue(const LIT &e)
    {
        Node *newN = new Node(e);
        if (back == NULL)
        {
            front = back = newN;
        }
        else
        {
            back->next = newN;
            back = newN;
        }
    }
    LIT
    dequeue();

private:
    struct Node
    {
        LIT data;
        Node *next;
    };
    Node *front, *back;
};

int main()
{
}