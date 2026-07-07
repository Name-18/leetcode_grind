// Last updated: 7/7/2026, 3:51:27 PM
1class Solution {
2public:
3    string s, p;
4    vector<vector<int>> dp;
5
6    bool func(int i, int j) {
7
8        if (j == p.size())
9            return i == s.size();
10
11        if (dp[i][j] != -1)
12            return dp[i][j];
13
14        bool firstMatch =
15            (i < s.size()) &&
16            (s[i] == p[j] || p[j] == '.');
17
18        bool ans;
19
20        if (j + 1 < p.size() && p[j + 1] == '*') {
21            ans = func(i, j + 2) ||
22                  (firstMatch && func(i + 1, j));
23        } else {
24            ans = firstMatch && func(i + 1, j + 1);
25        }
26
27        return dp[i][j] = ans;
28    }
29
30    bool isMatch(string str, string pat) {
31        s = str;
32        p = pat;
33
34        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
35
36        return func(0, 0);
37    }
38};