// Last updated: 8/18/2026, 12:57:41 PM
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4
5        int alt = 0;
6        int mx = 0;
7        for(auto &it : gain){
8             alt += it ;
9
10            mx = max(mx , alt);
11        }
12        return mx;
13    }
14};