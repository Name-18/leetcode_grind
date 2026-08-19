// Last updated: 8/19/2026, 10:52:44 PM
1class Solution {
2public:
3vector<vector<int>> vec;
4    void fnc(vector<int> &nums , int i , int target , vector<int>& arr){
5           if(target==0){
6            vec.push_back(arr);
7            return;
8           }
9           if(i==nums.size()){
10            return ;
11           }
12           
13           if(target>= nums[i]){
14
15             arr.push_back(nums[i]);
16             fnc(nums , i, target-nums[i], arr );
17             arr.pop_back();
18           }
19
20           fnc(nums , i+1, target, arr );
21
22           
23            
24    }
25    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
26        sort(nums.begin(),nums.end());
27        vector<int> a;
28        fnc(nums,0,target,a);
29        return vec;
30    }
31};