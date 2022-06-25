#include <iostream>
#include <vector>

using namespace std;

class QueueArr
{
public:
    QueueArr();
    int dequeue();
    void enqueue(const int &e)
    {
        items.push_back(e);
    }

private:
    bool full;
    vector<int> items;
    void resize();
    int size, front, back;
};