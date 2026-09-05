// Last updated: 9/5/2026, 6:34:37 PM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        
5        
6        int n = nums.size();
7        for(int i=0;i<n;i++){
8            nums.push_back(nums[i]);
9        }
10     vector<int> ans(n);
11        int n1 = nums.size();
12
13        vector<int> st;
14
15        for(int i = n1 -1; i>=0;i--){
16
17            int num = nums[i];
18
19            while(!st.empty() and st.back() <= num){
20                st.pop_back();
21            }
22            if(i <= n-1){
23            if(st.empty()){
24                ans[i] = -1;
25            }else{
26               ans[i] = st.back();
27                           }
28                           }
29                           st.push_back(num);
30
31
32        }
33        return ans;
34    }
35};