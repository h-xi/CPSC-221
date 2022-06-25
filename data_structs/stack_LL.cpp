// RUN TIME: O(1) - POP, O(1) - PUSH
// IF CAPACITY FILLS - O(N) pushes is THETA(N) --> AMORTIZED: O(1)
#include <iostream>

using namespace std;

class StackLL
{
public:
    StackLL() {}
    bool empty() const
    {
        return top == NULL;
    }
    void push(const int &e)
    {
        Node *newN = new Node();
        newN->data = e;
        newN->next = top;
        top = newN;
    };
    int pop()
    {
        assert(!empty());
        int ret = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return ret;
    };

private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *top;
};

int main()
{
    StackLL stack;
    stack.push(1);
    stack.push(3);
    cout << stack.pop() << endl;
}