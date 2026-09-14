// Last updated: 9/14/2026, 1:46:11 PM
1class Solution {
2public:
3    vector<int> free;
4    vector<int> memo;
5
6    int n, B;
7
8    int id(int i, int budget, int first) {
9        return (i * (B + 1) + budget) * 2 + first;
10    }
11
12    int func(int i, vector<vector<int>>& items, int budget, int first) {
13
14        if (i == n)
15            return 0;
16
17        int idx = id(i, budget, first);
18
19        if (memo[idx] != -1)
20            return memo[idx];
21
22        // Don't buy this item
23        int skip = func(i + 1, items, budget, 1);
24
25        int buy = 0;
26
27        if (budget >= items[i][1]) {
28
29            // First copy gives free items
30            if (first == 1)
31                buy = free[i];
32
33            buy += 1 + func(
34                i,
35                items,
36                budget - items[i][1],
37                0
38            );
39        }
40
41        return memo[idx] = max(skip, buy);
42    }
43
44    int maximumSaleItems(vector<vector<int>>& items, int budget) {
45
46        n = items.size();
47        B = budget;
48
49        free.assign(n, 0);
50
51        for (int i = 0; i < n; i++) {
52            for (int j = 0; j < n; j++) {
53
54                if (i != j &&
55                    items[i][0] != 0 &&
56                    items[j][0] % items[i][0] == 0) {
57
58                    free[i]++;
59                }
60            }
61        }
62
63        memo.assign(n * (budget + 1) * 2, -1);
64
65        return func(0, items, budget, 1);
66    }
67};