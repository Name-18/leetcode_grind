// Last updated: 8/8/2026, 12:29:55 PM
1class Solution {
2public:
3
4    int n;
5    unordered_map<long long,int> mpp;
6    int func(int i, int j, string &s, int bl) {
7
8        if (i >= j) {
9
10            if (bl) {
11                if (i == j)
12                    return 1;
13
14                return 0;
15            }
16
17            return -1e9;
18        }
19        long long key = (1LL*i*(s.size()) + j)*2 + bl;
20
21        if ( mpp.find(key)!=mpp.end())
22            return mpp[key];
23
24        if (s[i] == s[j]) {
25
26            int newBl = bl;
27
28            if (i < n && j >= n)
29                newBl = 1;
30
31            return  mpp[key] = 2 + func(i + 1, j - 1, s, newBl);
32        }
33
34        return  mpp[key] = max(
35            func(i + 1, j, s, bl),
36            func(i, j - 1, s, bl)
37        );
38    }
39
40    int longestPalindrome(string word1, string word2) {
41
42        string s = word1 + word2;
43
44        n = word1.size();
45
46        int N = s.size();
47
48        return max(0, func(0, N - 1, s, 0));
49    }
50};