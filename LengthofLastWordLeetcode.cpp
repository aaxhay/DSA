#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    cout<<"Enter a string here: ";
   string s;
   getline(cin,s);

   auto count = 0;
   for(int i = s.length()-1 ; i >=0 ; i--){
     if(s.at(i) ==' '){
        break;
     }
     count++;
   }

   if(count<0){
    return 0;
   }
   else{
    cout<<count<<endl;
   } 
}