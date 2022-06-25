#include <iostream>
#include <array>
#include <vector>

using namespace std;

void putInPlace(vector<int> &arr, int i)
// PRECONDITION: arr[0..i-1] is sorted, 0 <= i < arr.size()
{
    int temp = arr[i];
    int j = i;
    while (j > 0 && arr[j - 1] > temp)
    {
        arr[j] = arr[j - 1];
        j--;
    }
    arr[j] = temp;
}

// [4, 1, 6, 9, 2]
// @ iteration i = 1
// Assume sorted array = [4]
// when i = 1 :
// temp = 1
// j = 1  --> 1 > 0 && 4 > 1
// arr[j] = 4
// j -- = new j
// arr[new j] = 1
// sorted array = [1, 4]

// Assuming there is a sorted array, slide integer one at a time into appropriate slot.

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        putInPlace(arr, i);
    }
}

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

    insertionSort(sort);
    print(sort);
}