// Last updated: 9/6/2026, 12:05:49 PM
1class Solution {
2public:
3    int countGoodRotations(vector<int>& nums) {
4
5        int n =  nums.size();
6        long long tot = accumulate(nums.begin(),nums.end(),0LL);
7        for(int i=0;i<n/2-1;i++){
8            nums.push_back(nums[i]);
9        }
10
11        int l = 0;
12        int cnt = 0;
13      
14        long long sm = 0;
15        for(int r = 0;r<nums.size();r++){
16
17            sm += nums[r];
18
19            if( r - l +1 > n/2){
20                sm -=nums[l++];
21            }
22
23            if(r - l + 1== n/2){
24             
25                if(sm > tot - sm) cnt+=1;
26            }
27           
28        }
29        return cnt;
30    }
31};