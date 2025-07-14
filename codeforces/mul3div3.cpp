#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<long long int> nums;

vector <int > ans;
unordered_map<long long int,int> mpp;
for(int i =0;i<n;i++){
  long long  int t;
    cin>>t;
nums.push_back(t);

mpp[t]++;

}

long long t = -1;
unordered_set<long long> s(nums.begin(), nums.end());
for (long long num : nums) {
    if (s.count(num * 2)) continue;
    if (num % 3 == 0 && s.count(num / 3)) continue;
    t = num;
    break;
}

vector<long long int> tmp;
 tmp.push_back(t);
while(true){
  long long  int op1=3*t;
   long long int op2= t%2==0? t/2:-1;
    
   
    if(mpp.find(op1)!=mpp.end()){
      tmp.push_back(op1);
      t=op1;
    } else if(mpp.find(op2)!=mpp.end() && op2!=-1){
      tmp.push_back(op2);
      t=op2;
    }else{
        break;
    }
    
}
reverse(tmp.begin(),tmp.end());
for(int i=0;i<tmp.size();i++){
    cout<<tmp[i]<<" " ;
}
}