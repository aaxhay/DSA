#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int x){
    int num = x;

    int ans = 0;
    while(x>0){
        int digit = x % 10;
        ans = ans * 10 + digit;
        x /= 10;
    }

    if(num==ans){
        return true;
    }
    return false;
}

int main()
{   
    int num ;
    cout<<"Enter any number: "<<endl;
    cin>>num;

    cout<<checkPalindrome(num);

    return 0;
}