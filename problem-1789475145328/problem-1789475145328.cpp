// Last updated: 9/15/2026, 5:55:45 PM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4
5        map<int,int> mpp;
6        mpp[0]=1;
7        int sm= 0;
8        int mx = -1e9;
9        int mn = 1e9;
10        int ans= 0;
11        unordered_set<int> st;
12        st.insert(0);
13        for(int i=0;i<nums.size();i++){
14            sm += nums[i];
15
16           int mod = sm % k;
17
18            mod+=k;
19                mod %= k;
20            if(mpp.find(mod)!= mpp.end()){
21                ans += mpp[mod];
22            }
23                 
24            mpp[mod]+=1;
25            st.insert(sm);
26            
27        }
28        return ans;
29    }
30};