// Last updated: 7/18/2026, 1:42:40 AM
1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int n = nums.size();
5        int mx = *max_element(nums.begin() ,nums.end());
6
7        vector<int> gcd(mx+1,0);
8           
9           for(int i=0;i<n;i++){
10
11            for(int k = 1;k*k<=nums[i];k++){
12
13                if(nums[i]%k==0){
14                gcd[k]++;
15                if(nums[i]/k!=k){
16                     gcd[nums[i]/k]++;
17                }
18                }
19            }
20           }
21             
22             vector<long long > act(mx+1,0);
23
24             for(int i=mx;i>=1;i--){
25
26                act[i] = (1LL*gcd[i]*(gcd[i]-1))/2;
27
28                for(int k = 2*i;k<=mx;k+=i){
29                    act[i]-=act[k];
30
31                }
32             }
33
34             vector<long long> pref(mx+1);
35             for(int i=1;i<=mx;i++){
36                pref[i] = pref[i-1] + act[i];
37             }
38
39             vector<int> result;
40            for(auto &it : queries){
41
42                int low = 1;
43                int high = mx;
44                int tmp =1;
45                while(low<=high){
46
47                    int mid = (low+high)/2;
48
49                    if( pref[mid] > it){
50                 tmp = mid;
51                 high =mid-1;
52                    }else{
53                        low = mid+1;
54                    }
55                }
56                result.push_back(tmp);
57             }
58return result;
59    }
60};