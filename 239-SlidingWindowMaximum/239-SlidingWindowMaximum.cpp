// Last updated: 9/5/2026, 11:26:10 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        
5        deque<int> dq;
6       int n = nums.size();
7       vector<int> ans;
8        for(int i=0;i<n;i++){
9             
10             int num =  nums[i];
11
12             while(!dq.empty() && num > nums[dq.back()]){
13                dq.pop_back();
14             }
15             dq.push_back(i);
16
17           while (!dq.empty() && dq.front() <= i - k) {
18    dq.pop_front();
19}
20ans.push_back(nums[dq.front()]);
21        }
22        vector<int> res(ans.begin()+k-1,ans.end());
23        return res;
24    }
25};