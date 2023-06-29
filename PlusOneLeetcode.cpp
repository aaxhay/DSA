#include <iostream>
#include <vector>
using namespace std;

// some of test cases are sensitive
void reverse(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start++], arr[end--]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        k = 10 * k + v[i];
    }
    k = k + 1;
    int len = v.size();

    int arr[len] = {0};
    int i = 0;
    while (k != 0)
    {
        int digit = k % 10;
        arr[i] = digit;
        k = k / 10;
        i++;
    }

    reverse(arr, len);
    printArray(arr, len);

    return 0;
}