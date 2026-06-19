// Last updated: 6/19/2026, 3:17:56 PM
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int curr = 0;
5         int mx =0;
6        for(auto it:gain){
7            curr += it;
8mx = max(mx,curr);
9        }
10        return mx;
11    }
12};