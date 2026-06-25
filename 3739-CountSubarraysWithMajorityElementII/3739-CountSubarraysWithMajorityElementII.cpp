// Last updated: 6/26/2026, 1:26:05 AM
1class Solution {
2public:
3class Fenwick {
4public:
5    vector<int> bit;
6    int n;
7
8    Fenwick(int n) {
9        this->n = n;
10        bit.assign(n + 1, 0);
11    }
12
13    void update(int idx, int val) {
14        while (idx <= n) {
15            bit[idx] += val;
16            idx += idx & -idx;
17        }
18    }
19
20    int query(int idx) {
21        int ans = 0;
22        while (idx > 0) {
23            ans += bit[idx];
24            idx -= idx & -idx;
25        }
26        return ans;
27    }
28};
29
30long long subarray(vector<int>& nums, int tar) {
31
32    int n = nums.size();
33
34    // Build prefix sums after +1/-1 transformation
35    vector<long long> pref(n + 1, 0);
36    for (int i = 0; i < n; i++) {
37        pref[i + 1] = pref[i] + (nums[i] == tar ? 1 : -1);
38    }
39
40    // Coordinate compression
41    vector<long long> vals = pref;
42    sort(vals.begin(), vals.end());
43    vals.erase(unique(vals.begin(), vals.end()), vals.end());
44
45    Fenwick bit(vals.size());
46
47    long long ans = 0;
48
49    for (int i = 0; i <= n; i++) {
50
51        int idx = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin() + 1;
52
53        // previous prefix sums >= current prefix sum
54        ans += i - bit.query(idx - 1);
55
56        bit.update(idx, 1);
57    }
58
59    return ans;
60}
61 long long countMajoritySubarrays(vector<int>& nums, int target) {
62        int cnt = 0;
63        int mx = 0;
64        long long n = nums.size();
65
66        for(auto it :nums){
67            if(it == target) cnt += 1;
68            else{
69             mx = max(mx,cnt);
70            }
71        }
72         
73      long long x =   subarray(nums , target);
74
75      return (n*(n+1)/2)*1LL -x ;
76
77    }
78};