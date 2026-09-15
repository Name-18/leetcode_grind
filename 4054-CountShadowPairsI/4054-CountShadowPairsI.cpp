// Last updated: 9/15/2026, 12:33:12 PM
1class Solution {
2public:
3    vector<int> nums;
4    bool check(int t, int val, int x, int y) {
5        int cnt = 0;
6
7        for (int i = x; i <= y; i++) {
8            if (nums[i] > val)
9                cnt++;
10        }
11        return cnt >= t;
12    }
13    int bs(int x, int y, int val) {
14
15        int lo = 0;
16        int hi = y - x + 1;
17
18        while (lo <= hi) {
19            int mid = (lo + hi) / 2;
20            
21            if (check(mid, val, x, y)) {
22                lo = mid + 1;
23            } else {
24                hi = mid - 1;
25            }
26        }
27        return hi;
28    }
29    long long shadowPairs(vector<int>& nums) {
30        vector<int> st;
31        this->nums = nums;
32        int n = nums.size();
33        vector<int> nxt(n);
34        for (int i = n - 1; i >= 0; i--) {
35
36            while (!st.empty() and nums[st.back()] >= nums[i]) {
37                st.pop_back();
38            }
39
40            if (st.empty()) {
41                nxt[i] = n;
42
43            } else {
44                nxt[i] = st.back();
45            }
46            st.push_back(i);
47        }
48         map<int,vector<int>> mpp;
49
50         for(int i=0;i<n;i++){
51            mpp[nums[i]].push_back(i);
52         }
53        long long ans = 0;
54
55        for(int i=0;i<n;i++){
56
57          int x = i + 1;
58          int y = nxt[i]-1;
59         
60          int frst = lower_bound(mpp[nums[i]].begin() , mpp[nums[i]].end(),x) - mpp[nums[i]].begin();
61          
62          int lst = upper_bound(mpp[nums[i]].begin() , mpp[nums[i]].end(),y) - mpp[nums[i]].begin();
63          lst--;
64         
65         int tot = y - x + 1;
66
67         int in  = 0;
68         if(lst >= frst){
69            in = lst - frst +1;
70         }
71 ans+= (tot - in);
72        }
73        return ans;
74    }
75};