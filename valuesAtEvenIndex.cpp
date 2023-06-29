#include <iostream>
using namespace std;

void getEvenIndex(int arr[], int n, int res[])
{
    int k = 0;
    for(int i = 0; i<n ; i+=2){
        res[k++] = arr[i];
    }
    int newArraylen = k;
    for(int i = 0 ; i<newArraylen ; i++){
        cout<<res[i]<<" ";
    }
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int result[] = {0};
    cout<<"Even index values are : "<<endl;
    getEvenIndex(arr,7,result);
    return 0;
}
