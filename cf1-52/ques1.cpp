#include<bits/stdc++.h>
using namespace std;
     

int main(){
    ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int t;
     cin>>t;
     while (t--){
       int n;
       int pos;
       cin>>n>>pos;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
        cin>>arr[i];
       }
       int maxi = *max_element(arr.begin(),arr.end());
       int minn= *min_element(arr.begin(),arr.end());
       if(maxi> pos && pos> minn){
        int min_path = min(maxi-pos,pos-minn);
        int max_path = max(maxi-pos,pos-minn);
        cout<< 2*min_path +max_path;
       }else if(maxi<=pos){
           cout<< pos-minn;
       }else if(pos<=minn){
        cout<< maxi-pos;
       }
       
     cout<<endl;
     }
     
} 
