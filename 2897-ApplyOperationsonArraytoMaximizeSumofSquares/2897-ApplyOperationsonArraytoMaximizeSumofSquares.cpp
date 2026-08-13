// Last updated: 8/13/2026, 4:35:56 PM
1class Solution {
2public:
3int mod = 1e9+7;
4    int maxSum(vector<int>& nums, int k) {
5           
6           map<int,int> mpp;
7
8           for(int i=0;i<nums.size();i++){
9
10            for(int j =0;j<32;j++){
11
12                if(nums[i] & (1<<j)){
13                    mpp[(1<<j)]+=1;
14                }
15            }
16           }
17
18        vector<int> tmp;
19          while(k--){
20           int num = 0;
21           for (auto it = mpp.rbegin(); it != mpp.rend(); ++it) {
22              
23              if(it->second>0){
24                it->second--;
25                num+= it->first;
26              }
27}
28                   
29           tmp.push_back(num);
30
31           }
32
33          
34
35       long long ans = 0;
36
37       for(auto &it : tmp){
38         ans = (ans + 1LL*it*it)% mod;
39       }
40
41ans = ans % mod;
42          return ans;
43    }
44};