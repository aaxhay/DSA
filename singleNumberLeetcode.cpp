#include<bits/stdc++.h>
using namespace std;

int func(vector<int> arr){
   int ans = 0;
   for(int num : arr){
    ans ^=num;
   }
   return ans;
}

int main(void){
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);

    cout<<func(v)<<endl;

    return 0;
}