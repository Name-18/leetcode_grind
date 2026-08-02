// Last updated: 8/3/2026, 3:52:25 AM
1class Solution {
2public:
3    bool check(vector<int>& diff, vector<vector<int>>& bounds, int x) {
4
5        int prev = x;
6        for (int i = 1; i < bounds.size(); i++) {
7
8            int nw = prev + diff[i - 1];
9            if (bounds[i][0] > nw or bounds[i][1] < nw)
10                return false;
11            prev = nw;
12        }
13        return true;
14    }
15    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
16
17        vector<int> diff;
18        for (int i = 1; i < original.size(); i++) {
19
20            int d = original[i] - original[i - 1];
21            diff.push_back(d);
22        }
23        int lo = bounds[0][0];
24        int hi = bounds[0][1];
25        int ans = bounds[0][1] -  bounds[0][0]+1 ;
26
27        for(int i=1;i<bounds.size();i++){
28
29            int n_lo = lo + diff[i-1];
30            int n_hi =  hi + diff[i-1];
31
32            lo = max(bounds[i][0],n_lo);
33            hi =  min(bounds[i][1],n_hi);
34
35            ans = min(ans , hi - lo+1);
36            if(ans <0) return 0;
37        }
38
39        return ans;
40    }
41};