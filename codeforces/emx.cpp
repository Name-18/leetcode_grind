#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        unordered_map<int,int> mpp;
        int exc=INT32_MIN;
        set<int> st;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            a.push_back(tmp);
            mpp[tmp]++;
            exc=max(exc,tmp);
            st.insert(tmp);
        }
        exc++;
        vector<int > ans;
        sort(a.begin(),a.end());
        for(int i=0;i<=exc ;i++){
            if(mpp.find(i)==mpp.end()){
                exc=min(exc,i);
            }
        }
        for(int k =1;k<n;k++){
            set<int > uni;
        for(int i=0;i<n;i++){
        if(a[i]<=exc && n-i>=k){
            if(mpp[a[i]]<=k){
                uni.insert(a[i]);
            }
            
        }
        else if(a[i]>exc && n-i>=k){
            uni.insert(exc);
        }
        }
        ans.push_back(uni.size());
    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    }
}