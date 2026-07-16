// Last updated: 7/16/2026, 2:50:02 PM
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4
5        vector<int > pref(nums.size(),0);
6
7        pref[0] = __gcd(nums[0],nums[0]);
8        int maxi = nums[0];
9        for(int i=1;i<nums.size();i++){
10     maxi= max(maxi,nums[i]);
11
12            long long t = __gcd(maxi,nums[i]);
13
14            pref[i]=  t;
15           
16        }
17
18        sort(pref.begin(),pref.end());
19
20        int i=0;
21        int j=nums.size()-1;
22long long summ=0;
23        while(i<j){
24            int t = __gcd(pref[i],pref[j]);
25            i++;
26            j--;
27            summ+=t;
28        }
29        return summ;
30    }
31};