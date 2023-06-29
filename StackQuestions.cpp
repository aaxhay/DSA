#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num = s.top();

    s.pop();

    reverseStack(s);

    s.push(num);
}

int main(){
    stack<int> s;
    s.push(-7);
    s.push(10);
    s.push(2);
    s.push(5);
    s.push(11);
    s.push(6);
    
    // while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }
    
    // reverseStack(s);
    //  while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }

}