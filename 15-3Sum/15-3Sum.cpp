// Last updated: 10/13/2026, 11:50:14 PM
1class Solution {
2public:
3    vector<vector<int>> threeSum(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5vector<vector<int>> vec;
6        for(int i=0;i<nums.size()-2;i++){
7
8            if(nums[i]>0)  break;
9
10            if( i > 0 and nums[i] == nums[i-1]) continue;
11
12            int left = i+1;
13            int right= nums.size()-1;
14
15            while(left < right){
16
17                int sm = nums[i] + nums[left] + nums[right];
18
19                if(sm == 0){
20vec.push_back({nums[i],nums[left],nums[right]});
21
22  while(left < right and nums[left] == nums[left+1]) left+=1;
23  while(left < right and nums[right] == nums[right-1]) right-=1;
24   
25   left+=1;
26   right-=1;
27
28                }else if(sm>0) right-=1;
29                else{
30                    left+=1;
31                }
32            }
33        }
34        return vec;
35    }
36};