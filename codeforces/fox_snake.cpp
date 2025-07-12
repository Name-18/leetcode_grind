#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int m;
cin>>m;
vector<vector<char>> ans;
vector<char> tmp;
vector<char> tmp1;
vector<char> tmp2;
for(int i =0;i<m;i++){
tmp.push_back('#');
}
tmp1.push_back('#');
for(int i =1;i<m;i++){
tmp1.push_back('.');
}
for(int i =0;i<m-1;i++){
tmp2.push_back('.');
}
tmp2.push_back('#');
bool flag_2=true;
bool flag_1=false;
for(int i=0;i<n;i++){
if(i%2==0) {ans.push_back(tmp);
}
else{
if(flag_2 && !flag_1){
    ans.push_back(tmp2);
    flag_1=true;
    flag_2=false;
}
else{
    ans.push_back(tmp1);
    flag_2=true;
    flag_1=false;
}
}
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<ans[i][j];
}
cout<<endl;
}

}