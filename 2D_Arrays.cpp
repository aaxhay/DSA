#include <bits/stdc++.h>
using namespace std;

void sumRow(int arr[][3], int n, int m)
{
    for (int row = 0; row < 2; row++)
    {
        int sum = 0;
        for (int cols = 0; cols < 3; cols++)
        {
            sum += arr[row][cols];
        }
        cout << sum << " ";
    }
}

int LargestRowSum(int arr[][4], int n, int m)
{
    int maxi = INT_MIN;
    int rowNumber = 0;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int cols = 0; cols < 4; cols++)
        {
            sum += arr[row][cols];
        }
        if (sum>maxi)
        {
            maxi = sum;
            rowNumber = row;
        }
    }
    cout << "largest row sum is " << maxi << endl;
    return rowNumber;
}

bool Searching(int arr[][4],int target,int n , int m){
    for(int row = 0; row<n ; row++){
        for(int cols = 0; cols<m ; cols++){
            if(arr[row][cols]==target){
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int arr[3][4];
    cout << "Enter the elements: ";
    for (int row = 0; row < 3; row++)
    {
        for (int cols = 0; cols < 4; cols++)
        {
            cin >> arr[row][cols];
        }
    }
    
    // according to rows
    cout << "elements are: " << endl;
    //  for(int row = 0 ; row<2 ; row++){
    //     for(int cols = 0 ; cols<3 ; cols++){
    //         cout<<arr[row][cols]<<" ";
    //     }cout<<endl;
    // }

    // according to columns
    for (int row = 0; row < 3; row++)
    {
        for (int cols = 0; cols < 4; cols++)
        {
            cout << arr[row][cols] << " ";
        }
        cout << endl;
    }
    
    int target;
    cin>>target;

    //searching in 2D array
    cout<<Searching(arr,target,3,4);

    // sum of particular row
    // sumRow(arr, 2, 3);
    // cout<<LargestRowSum(arr, 3, 4);
    return 0;
}