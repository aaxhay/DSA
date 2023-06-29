#include <iostream>
using namespace std;

void printNum(int n)
{
    if (n == 0)
        return;

    cout << n << " ";

    // tail recursion

    printNum(n - 1);
}

void printNum1(int n)
{
    if (n == 0)
        return;

    // head recursion

    printNum1(n - 1);

    cout << n << " ";
}

// factorial of a number using recursion
int fact(int n)
{
    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    return isSorted(arr + 1, size - 1);
}

bool linearSearch(int *arr, int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    return linearSearch(arr + 1, size - 1, key);
}

int getSum(int *arr, int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];

    int ans = arr[0] + getSum(arr + 1, size - 1);
    return ans;
}

bool binarySearch(int *arr, int start, int end, int key)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);
    else
        return binarySearch(arr, start, mid - 1, key);
}

// reverse a string using recursion

void reverse(string &str, int start, int end)
{
    // to understand how its working
    // cout << "str value is : " << str << endl;

    if (start > end)
        return;

    swap(str[start], str[end]);

    return reverse(str, start + 1, end - 1);
}

bool checkPalindrome(string str, int s, int e)
{
    if (s > e)
        return true;

    if (str[s] != str[e])
        return false;

    return checkPalindrome(str, s + 1, e - 1);
}

void reverse1(string &str, int start)
{
    // to understand how its working
    // cout << "str value is : " << str << endl;

    if (start > (str.length() + 1) / 2)
        return;

    swap(str[start], str[str.length() - 1 - start]);

    return reverse1(str, start + 1);
}

bool checkPalindrome1(string str, int s)
{
    if (s > (str.length() + 1) / 2)
        return true;

    if (str[s] != str[(str.length() - s) - 1])
        return false;

    return checkPalindrome1(str, s + 1);
}

int power(int a, int b)
{
    // base case
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    int ans = power(a, b / 2); // recursive call

    if (b & 1)
    {
        return a * ans * ans;
    }
    else
    {
        return a * ans;
    }
}

void bubbleSort(int *arr, int size)
{
    if (size == 0 || size == 1)
        return;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    bubbleSort(arr, size - 1);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int *arr, int i, int size)
{
    if (size == 0 || size == 1)
        return;

    if (i == size - 1)
        return;

    int min_ele = i;

    for (int j = i + 1; j < size; j++)
    {
        if (arr[j] < arr[min_ele])
        {
            min_ele = j;
        }
    }

    swap(arr[i], arr[min_ele]);

    selectionSort(arr, i + 1, size);
}

void insertionSort(int *arr, int val, int size)
{
    //  base case
    if (size == 0 | size == 1)
        return;

    int temp = arr[val];

    int i;
    // ek case solve krlo
    for (i = val - 1; i >= 0; i--)
    {
        if (arr[i] > temp)
        {
            arr[i + 1] = arr[i];
        }
        else
        {
            break;
        }
    }

    arr[i + 1] = temp;

    insertionSort(arr, val + 1, size - 1);
}

long long merge1(int *arr, int start, int end)
{
    int inv_count = 0;
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;
    int newArrayIndex = start;

    int *first = new int[len1];
    int *second = new int[len2];

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[newArrayIndex++];
    }

    newArrayIndex = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[newArrayIndex++];
    }

    // merge 2 sorted array algo

    int i = 0;
    int j = 0;
    newArrayIndex = start;

    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[newArrayIndex++] = first[i++];
        }
        else
        {
            arr[newArrayIndex++] = second[j++];
        }
    }

    while (i < len1)
    {
        arr[newArrayIndex++] = first[i++];
    }

    while (j < len2)
    {
        arr[newArrayIndex++] = second[j++];
    }
    delete[] first;
    delete[] second;
}

// long long mergeSort(int *arr, int start, int end)
// {
//     int inversionCnt = 0;
//     if (start >= end)
//         return;

//     int mid = start + (end - start) / 2;

//     inversionCnt += mergeSort(arr, start, mid);

//     inversionCnt += mergeSort(arr, mid + 1, end);

//     inversionCnt += merge1(arr, start, end);
// }

int partition1(int arr[], int start, int end)
{
    int pivot = arr[start];
    int cnt = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int actualIndex = start + cnt;
    swap(arr[actualIndex], arr[start]);

    int i = start, j = end;

    while (i < actualIndex && j > actualIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < actualIndex && j > actualIndex)
            swap(arr[i++], arr[j++]);
    }

    return actualIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pos = partition1(arr, start, end);
    // for the left side of the array
    quickSort(arr, start, pos - 1);
    // for the right side of the array
    quickSort(arr, pos + 1, end);
}

int main(void)
{
    // int n;
    // cin >> n;

    // printNum1(n);
    // int ans = fact(n);
    // cout << ans << endl;

    // int arr[5] = {1, 2, 9, 4, 5};
    // int size = 5;
    // bool ans = isSorted(arr, size);
    // if (ans)
    //     cout << "Array is sorted" << endl;
    // else
    //     cout << "Array is not sorted" << endl;

    // int arr[5] = {2, 5, 6, 11, 15};
    // int size = 5;
    // int key = 18;
    // bool ans = linearSearch(arr, size, key);
    // if (ans)
    //     cout << "Key found" << endl;
    // else
    //     cout << "key is not there" << endl;

    // int arr[5] = {1, 2, 3, 4, 5};
    // int size = 5;
    // int ans = getSum(arr, size);
    // cout << "sum of array elements is " << ans << endl;

    // int arr[6] = {3, 7, 11, 19, 22, 31};
    // int size = 6;
    // int key = 1;
    // int ans = binarySearch(arr, 0, size - 1, key);
    // if (ans)
    // {
    //     cout << "key is there" << endl;
    // }
    // else
    // {
    //     cout << "key is not there" << endl;
    // }
    // return 0;

    // recursive function to reverse a string
    // string str;
    // cin >> str;
    // int start = 0;
    // int end = str.length() - 1;
    // reverse(str, start, end);
    // cout << "Reversed string is: " << str << endl;

    // checking is string palindrome or not using recursion
    // bool isPalindrome = checkPalindrome(str, start, str.length() - 1);
    // if (isPalindrome)
    // {
    //     cout << "its a palindrome" << endl;
    // }
    // else
    // {
    //     cout << "its not a palindrome" << endl;
    // }

    // only with one pointer approach
    // bool isPalindrome1 = checkPalindrome1(str, start);
    // if (isPalindrome1)
    // {
    //     cout << "its a palindrome" << endl;
    // }
    // else
    // {
    //     cout << "its not a palindrome" << endl;
    // }

    // reverse1(str,start);
    // cout<<"reversing the string only with one pointer is "<<str<<endl;

    // power operations using recursion
    // int a, b;
    // cin >> a >> b;
    // cout << "Answer is " << power(a, b) << endl;

    // sorting using recursion
    // int arr[5] = {9, 2, 1, 10, 4};
    // int size = 5;

    //     bubbleSort(arr, 5);
    //     printArray(arr, 5);

    //     selectionSort(arr, 0, 5);
    //     printArray(arr, 5);

    //     insertionSort(arr, 1, 5);
    //     printArray(arr, 5);

    // fastest sorting algorithm --> merge sort
    // mergeSort(arr, 0, size - 1);
    // cout<<merge1(arr,0,size-1)<<endl;
    // printArray(arr, 5);

    // heap sort using recursion
    // int arr[5] = {8, 2, 1, 5, 3};
    // int size = 5;

    // quickSort(arr, 0, size - 1);
    // printArray(arr, size);

    return 0;
}