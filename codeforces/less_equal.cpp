#include<bits/stdc++.h>
using namespace std;
int answer(vector <int> ans , int k,int n){
    
sort(ans.begin(),ans.end());
if(k==0){
    return ans[0]-1>=1? ans[0]-1:-1; 
}
set<int> st;
int op = ans[k-1];
int i=k;
for(;i<n;i++){
   if(op==ans[i]){
    return -1;
   }
}

return op;
}
int main(){
int n,k;
cin>>n;
cin>>k;
vector<int> ans;
for(int i=0;i<n;i++){
int tmp;
cin>>tmp;
ans.push_back(tmp);
}
sort(ans.begin(),ans.end(),[](int a,int b){

});
cout<< answer(ans,k,n);
}