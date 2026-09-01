// Last updated: 9/1/2026, 8:55:07 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int sum) {
4
5        const int INF = 1e9;
6
7        // {operations, remaining}
8        priority_queue<
9            pair<int,int>,
10            vector<pair<int,int>>,
11            greater<pair<int,int>>
12        > pq;
13
14        pq.push({0, sum});
15
16        for (int i = 0; i < nums.size(); i++) {
17
18            vector<int> best(sum + 1, INF);
19
20            // --------------------------------
21            // Take all current states
22            // --------------------------------
23
24            while (!pq.empty()) {
25
26                auto [opr, rem] = pq.top();
27                pq.pop();
28
29                // Don't use nums[i]
30                best[rem] = min(best[rem], opr);
31
32                // --------------------------------
33                // Multiplication
34                // --------------------------------
35
36                long long val = nums[i];
37                int cost = 0;
38
39                while (val <= rem) {
40
41                    best[rem - val] = min(
42                        best[rem - val],
43                        opr + cost
44                    );
45
46                    cost++;
47
48                    if (val > rem / 2)
49                        break;
50
51                    val *= 2;
52                }
53
54                // --------------------------------
55                // Division
56                // --------------------------------
57
58                val = nums[i];
59                cost = 0;
60
61                while (val > 1) {
62
63                    val /= 2;
64                    cost++;
65
66                    if (val <= rem) {
67
68                        best[rem - val] = min(
69                            best[rem - val],
70                            opr + cost
71                        );
72                    }
73                }
74            }
75
76            // --------------------------------
77            // Rebuild PQ with ONLY best states
78            // --------------------------------
79
80            for (int rem = 0; rem <= sum; rem++) {
81
82                if (best[rem] != INF) {
83                    pq.push({best[rem], rem});
84                }
85            }
86        }
87
88        // PQ now contains complete solutions
89        while (!pq.empty()) {
90
91            auto [opr, rem] = pq.top();
92            pq.pop();
93
94            if (rem == 0)
95                return opr;
96        }
97
98        return -1;
99    }
100};