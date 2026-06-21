// Last updated: 6/21/2026, 8:44:09 AM
1class Solution {
2public:
3    int countValidSubarrays(vector<int>& nums, int x) {
4  int ans =0;
5        for(int i=0;i<nums.size();i++){
6            long long sum =0;
7            for(int j=i;j<nums.size();j++){
8                 sum+=nums[j];
9
10                int last = sum%10;
11
12                if(last==x){
13                    long long tmp = sum;
14
15                    while(tmp>=10){
16                        tmp/=10;
17                    }
18                    if(tmp==x) ans +=1;
19                }
20            }
21        }
22        return ans;
23    }
24};