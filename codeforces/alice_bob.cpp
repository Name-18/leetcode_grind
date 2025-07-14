#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    string ans[2]={"Alice","Bob"};
    string num;
    cin>>num;
    int ones=0;
    
    if(n==k){
        cout<<ans[1];
    }
    for(auto it:num){
       it == '1' ?ones+=1:ones+=0;
    }
      if(k>=ones){
        cout<< ans[0]<<" ";
      } 
      else{
       if(2*k>n ){
        cout<<ans[0]<<" ";
       }else{
        cout<<ans[1]<<" ";
       }

      }
      cout<<endl;

}
}