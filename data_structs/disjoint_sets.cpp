#include <iostream>
#include <vector>

using namespace std;

class disjointSets
{
public:
    int Find(int x)
    {
        if (parent[x] < 0)
            return x;
        else
            return Find(parent[x]);
    }

private:
    vector<int> parent;
};