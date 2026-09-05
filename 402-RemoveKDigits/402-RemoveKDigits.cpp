// Last updated: 9/5/2026, 11:10:31 PM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        if (num.size() <= k) return "0";
5
6        vector<int> st;
7
8        for (char c : num) {
9            int n = c - '0';
10
11            while (!st.empty() && k > 0 && st.back() > n) {
12                st.pop_back();
13                k--;
14            }
15
16            st.push_back(n);
17        }
18
19
20        while (k > 0) {
21            st.pop_back();
22            k--;
23        }
24
25     
26        int i = 0;
27        while (i < st.size() && st[i] == 0)
28            i++;
29
30        if (i == st.size())
31            return "0";
32
33        string ans;
34        while (i < st.size()) {
35            ans += char(st[i] + '0');
36            i++;
37        }
38
39        return ans;
40    }
41};