// Last updated: 6/18/2026, 3:11:09 PM
1class Solution {
2public:
3    bool func(map<char, int>& s_mpp, map<char, int>& t_mpp) {
4        for (auto it : t_mpp) {
5            if (s_mpp.find(it.first) == s_mpp.end()) {
6                return false;
7            } else if (s_mpp[it.first] < it.second) {
8                return false;
9            }
10        }
11        return true;
12    }
13    string minWindow(string s, string t) {
14        map<char, int> t_mpp;
15        map<char, int> s_mpp;
16
17        for (auto it : t) {
18            t_mpp[it] += 1;
19        }
20
21        int l = 0;
22        int str = -1;
23        int ans = s.size();
24        bool flg = false;
25        for (int r = 0; r < s.size(); r++) {
26            s_mpp[s[r]] += 1;
27
28            if (func(s_mpp, t_mpp)) {
29                if (ans >= r - l + 1) {
30                    ans = r - l + 1;
31                    str = l;
32                }
33                flg = true;
34                while (l < s.size() and func(s_mpp, t_mpp)) {
35                    if (ans >= r - l + 1) {
36                        ans = r - l + 1;
37                        str = l;
38                    }
39                    s_mpp[s[l]]--;
40                    if (s_mpp[s[l]] == 0) {
41                        s_mpp.erase(s[l]);
42                    }
43                    l++;
44                }
45            }
46        }
47       if(!flg) return "";
48
49        return s.substr(str, ans);
50    }
51};