#include<bits/stdc++.h>
using namespace std;

int remove( vector<int> arr , int k ){
   int count = 0;
   for(auto num : arr){
       if(num!=k){
          arr[count++] = num;
       }
   }
   return count;
}

int main(void){
    vector<int> num;
    num.push_back(3);
    num.push_back(2);
    num.push_back(2);
    num.push_back(3);
    cout<<remove(num,3)<<endl;
    return 0;
}