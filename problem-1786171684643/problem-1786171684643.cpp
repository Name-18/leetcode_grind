// Last updated: 8/8/2026, 12:18:04 PM
1class Solution {
2public:
3
4    int n;
5    vector<vector<array<int, 2>>> dp;
6
7    int func(int i, int j, string &s, int bl) {
8
9        if (i >= j) {
10
11            if (bl) {
12                if (i == j)
13                    return 1;
14
15                return 0;
16            }
17
18            return -1e9;
19        }
20
21        int &res = dp[i][j][bl];
22
23        if (res != -1)
24            return res;
25
26        if (s[i] == s[j]) {
27
28            int newBl = bl;
29
30            if (i < n && j >= n)
31                newBl = 1;
32
33            return res = 2 + func(i + 1, j - 1, s, newBl);
34        }
35
36        return res = max(
37            func(i + 1, j, s, bl),
38            func(i, j - 1, s, bl)
39        );
40    }
41
42    int longestPalindrome(string word1, string word2) {
43
44        string s = word1 + word2;
45
46        n = word1.size();
47
48        int N = s.size();
49
50        dp.assign(N, vector<array<int, 2>>(N, {-1, -1}));
51
52        return max(0, func(0, N - 1, s, 0));
53    }
54};