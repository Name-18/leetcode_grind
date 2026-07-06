// Last updated: 7/6/2026, 2:25:16 PM
1class Solution {
2public:
3    bool isMiddleElementUnique(vector<int>& nums) {
4
5        int n = nums.size();
6        int mid = n/2;
7 
8        int x = nums[mid];
9        cout<<x;
10        for(int i=0;i<n;i++){
11            if(i ==  mid) continue;
12            else if(x == nums[i]) return false;
13            
14        }
15        return true;
16    }
17};