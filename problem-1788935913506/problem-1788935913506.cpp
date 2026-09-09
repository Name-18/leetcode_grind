// Last updated: 9/9/2026, 12:08:33 PM
1class Solution {
2public:
3    int minIncrementForUnique(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5
6        int prev=nums[0];
7        int cnt = 0;
8        for(int i=1;i<nums.size();i++){
9int num = nums[i];
10            if(prev>=num){
11
12             cnt +=    prev - num + 1;
13                num = prev +1;
14            }else{
15              
16            }
17            prev = num;
18            
19        }
20        return cnt ;
21    }
22};