// Last updated: 8/21/2026, 5:21:37 PM
1class Solution {
2public:
3    int subarrayBitwiseORs(vector<int>& arr) {
4        
5        unordered_map<int,int> mpp;
6       int n =  arr.size();
7        mpp[arr[n-1]]=1;
8        set<int> st;
9        st.insert(arr[n-1]);
10        for(int  i = n-2;i>=0;i--){
11
12           unordered_map<int,int> n_map;
13           for(auto it : mpp){
14            
15            int val = it.first;
16            int xr = val | arr[i];
17          //  cout<<val<< " or "<<arr[i] << " == " <<xr<<endl;
18            n_map[xr]+=1;
19            st.insert(xr);
20
21           }
22           n_map[arr[i]]=1;
23           st.insert(arr[i]);
24          mpp = move(n_map); 
25
26
27
28           
29        }
30        return st.size();
31    }
32};