// Last updated: 7/14/2026, 12:51:15 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n =  nums.size()-1;
5
6        int low = 0 ;
7        int high = n;
8        
9
10        while(low<=high){
11            int mid = (low +high)/2;
12
13            if(nums[mid]>=nums[0]){
14                low = mid+1;
15            }else{
16                high =  mid -1;
17            }
18        }
19        high =  (high + 1)%(n+1);
20        return nums[high];
21    }
22};