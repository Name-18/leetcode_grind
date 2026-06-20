// Last updated: 6/20/2026, 5:25:54 PM
1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& arr) {
4
5        map<int, int> mpp;
6        mpp[1] = 0;
7
8        for (auto it : arr) {
9
10            if (it[0] == 2) {
11                mpp[2] = min(it[1], 1);
12            } else {
13                mpp[it[0]] = it[1];
14            }
15        }
16        if (mpp.find(n) == mpp.end()) {
17
18            mpp[n] = 1e9;
19        }
20
21        vector<pair<int, int>> pr;
22
23        for (auto& it : mpp) {
24
25            pr.push_back(it);
26        }
27
28        for (int i = 1; i < pr.size(); i++) {
29            int steps = pr[i].first - pr[i - 1].first;
30            pr[i].second = min(pr[i].second, pr[i - 1].second + steps);
31        }
32        for (int i = pr.size() - 2; i >= 0; i--) {
33            int steps = pr[i + 1].first - pr[i].first;
34            pr[i].second = min(pr[i].second, pr[i + 1].second + steps);
35        }
36        int ans = 0;
37        mpp.clear();
38
39        for (int i = 1; i < pr.size(); i++) {
40            int stps = pr[i].first - pr[i - 1].first;
41            int init = pr[i - 1].second;
42            int fin = pr[i].second;
43
44            if (fin >= init + stps) {
45                ans = max(ans, init + stps);
46                pr[i].second = min(pr[i].second, init + stps);
47            } else {
48                int x = (stps + init + fin);
49
50                int y = (x / 2);
51
52                pr[i].second = min(pr[i].second, y);
53                ans = max(ans, int(y));
54            }
55        }
56        return ans;
57    }
58};