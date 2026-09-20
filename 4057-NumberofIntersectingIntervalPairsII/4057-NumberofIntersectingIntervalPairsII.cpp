// Last updated: 9/20/2026, 3:12:21 PM
1class Solution {
2public:
3    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
4        map<int, pair<int,int>> mp;
5
6        for (auto &it : intervals) {
7            int l = it[0];
8            int r = it[1];
9
10            mp[l].first++;   // start
11            mp[r].second++;  // end
12        }
13
14        long long active = 0;
15        long long ans = 0;
16
17        for (auto &[x, event] : mp) {
18            int starts = event.first;
19            int ends = event.second;
20
21            // Starts happen before ends at the same coordinate.
22            ans += active * starts;
23
24            // Intersections among intervals starting at x.
25            ans += 1LL * starts * (starts - 1) / 2;
26
27            active += starts;
28
29            // Now remove intervals ending at x.
30            active -= ends;
31        }
32
33        return ans;
34    }
35};