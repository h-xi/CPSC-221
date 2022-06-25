// RUNTIME: O(1) -PUSH O(1) - POP

#include <iostream>
#include <vector>

using namespace std;

class StackArr
{
public:
    StackArr()
    {
    }
    bool empty() const
    {
        return items.size() == 0;
    };
    void push(const int &e)
    {
        items.push_back(e);
    };
    int pop()
    {
        assert(!empty());
        int ret = items[items.size() - 1];
        items.pop_back();
        return ret;
    };

private:
    vector<int> items;
};

int main()
{

    StackArr stack;
    stack.push(3);
    stack.push(2);
    cout << stack.pop() << endl;
}