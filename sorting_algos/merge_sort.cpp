// IDEA --> Divide list in half until list is only 1 element
//  by default a one element list is sorted
//  Merge sorted lists together
// RUNTIME: O(nlog(n))

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, int lo, int mid, int hi)
{
    vector<int> temp;
    int a = lo, b = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        if (a <= mid && (b > hi || A[a] < A[b]))
        {
            temp.push_back(A[a++]);
        }
        else
            temp.push_back(A[b++]);
    }
    for (int k = lo; k <= hi; k++)
        A[k] = temp[k - lo];
}

void mSort(vector<int> &A, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = (lo + hi) / 2;
    mSort(A, lo, mid);
    mSort(A, mid + 1, hi);
    merge(A, lo, mid, hi);
}

void mergeSort(vector<int> &A)
{
    mSort(A, 0, A.size() - 1);
}

int main()
{
    vector<int> items;
    items.push_back(1);
    items.push_back(8);
    items.push_back(9);
    items.push_back(11);
    items.push_back(3);
    items.push_back(2);
    items.push_back(5);
}
