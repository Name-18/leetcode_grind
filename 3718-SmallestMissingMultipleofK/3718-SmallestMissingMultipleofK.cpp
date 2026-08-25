// Last updated: 8/25/2026, 5:10:55 PM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        set<int> st;
5        for(auto it:nums){
6            st.insert(it);
7        }
8
9        for(int i=1;i<10000;i++){
10            if(st.find(k*i)==st.end()){
11                return k*i;
12            }
13        }
14        return -1;
15    }
16};