#include <iostream>
#include <array>
#include <vector>

using namespace std;

// Selection Sort :

int findMin(vector<int> &arr, int a)
{
    int m = a;
    for (int i = a + 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[m])
        {
            m = i;
        }
    }
    return m;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &arr)
{
    if (!arr.empty())
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            int min = findMin(arr, i);
            swap(arr[i], arr[min]); // Assume a correct swap function
        }
    }
}

// Once min is found, repeatedly swap with current index, find new min and repeat

void print(vector<int> &arr)
{
    if (!arr.empty())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << "";
            cout << endl;
        }
    }
}

int main()
{
    vector<int> sort;
    sort.push_back(2);
    sort.push_back(1);
    sort.push_back(7);
    sort.push_back(4);
    sort.push_back(5);
    sort.push_back(3);
    print(sort);
    cout << "this was unsorted array";
    cout << endl;

    selectionSort(sort);
    print(sort);
}