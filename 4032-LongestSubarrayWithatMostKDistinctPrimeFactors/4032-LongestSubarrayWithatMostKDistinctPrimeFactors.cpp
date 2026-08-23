// Last updated: 8/23/2026, 1:34:04 PM
1class Solution {
2public:
3    vector<int> nums;
4    vector<int> pref(int num) {
5        vector<int> v;
6        if(num%2==0){
7               while (num % 2 == 0) {
8                    num /= 2;
9                }
10                 v.push_back(2);
11        }
12        for (int i = 3; i * i <= num; i += 2) {
13
14            if (num % i == 0) {
15                while (num % i == 0) {
16                    num /= i;
17                }
18                v.push_back(i);
19            }
20        }
21        if (num > 2) {
22            v.push_back(num);
23        }
24        return v;
25    }
26    int longestSubarray(vector<int>& nums, int k) {
27
28        vector<vector<int>> adj(nums.size());
29
30        for (int i = 0; i < nums.size(); i++) {
31            adj[i] = std::move(pref(nums[i]));
32        }
33        map<int,int> mpp;
34        int l = 0;
35        int cnt= 0;
36        int res = 0;
37        for (int r = 0; r < nums.size(); r++) {
38
39          for(auto it :  adj[r]){
40                mpp[it] +=1;
41                }
42
43            if(mpp.size()<=k){
44                res = max(res , r-l+1);
45            }else{
46
47                while(mpp.size()>k){
48                        
49                        for(auto &it : adj[l]){
50                            mpp[it]--;
51                            if(mpp[it]==0){
52                                mpp.erase(it);
53                            }
54                        }
55                        l++;
56
57                }
58            }
59            res = max(res , r-l+1);
60        }
61        return res;
62    }
63};