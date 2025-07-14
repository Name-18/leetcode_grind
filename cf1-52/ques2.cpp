#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
int n;
cin>>n;
string s;
cin>>s;
unordered_map<char,int> mpp;
for(auto it:s){
mpp[it]++;
}  
string ans[2]={"Yes","No"};
int itt=1;
for(int i =1;i<s.size()-1;i++){
    if(mpp[s[i]]>1){
        
        itt=0;
        break;
    }
}

cout<< ans[itt]<<endl;
}
}