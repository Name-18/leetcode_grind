// Last updated: 8/17/2026, 3:51:33 PM
1class Solution {
2    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
3
4        if (a.first != b.first)
5            return a.first < b.first;
6
7        return a.second < b.second;
8    }
9
10public:
11    int maxWidthRamp(vector<int>& nums) {
12
13        vector<pair<int,int>> pr;
14
15        for (int i = 0; i < nums.size(); i++) {
16
17            pr.push_back({nums[i], i});
18        }
19
20        sort(pr.begin(), pr.end(), cmp);
21        
22        stack<int> st;
23int res = 0;
24int mx = pr[nums.size()-1].second;
25        for(int i= nums.size()-2; i>=0;i--){
26
27          
28
29           res = max(res , (mx - pr[i].second ));
30             
31           mx = max(mx ,pr[i].second );
32        }
33
34return res;
35    }
36};