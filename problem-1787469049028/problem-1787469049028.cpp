// Last updated: 8/23/2026, 12:40:49 PM
1class Solution {
2public:
3    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
4        sort(nums.begin() , nums.end());
5         vector<vector<int>> res;
6        for(auto &it : nums){
7
8            if(it > lower and it<upper ){
9res.push_back({lower , it-1});
10lower = it+1;
11            }else if(it == lower){
12                lower++;
13            }
14            else if(it == upper){
15                upper--;
16            }
17        }
18        if(lower<= upper){
19            res.push_back({lower ,  upper});
20        }
21        return res;
22    }
23};