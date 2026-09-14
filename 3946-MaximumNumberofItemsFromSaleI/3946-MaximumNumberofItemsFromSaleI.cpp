// Last updated: 9/14/2026, 1:44:38 PM
1class Solution {
2public:
3    vector<int> free;
4    vector<vector<array<int, 2>>> memo;
5
6    int func(int i, vector<vector<int>>& items, int budget, int frst) {
7
8        if (i == items.size())
9            return 0;
10
11        if (memo[i][budget][frst] != -1)
12            return memo[i][budget][frst];
13
14        int next = func(i + 1, items, budget, 1);
15
16        int stay = 0;
17
18        if (budget >= items[i][1]) {
19
20            if (frst == 1)
21                stay = free[i];
22
23            stay += 1 + func(
24                i,
25                items,
26                budget - items[i][1],
27                0
28            );
29        }
30
31        return memo[i][budget][frst] = max(stay, next);
32    }
33
34    int maximumSaleItems(vector<vector<int>>& items, int budget) {
35
36        int n = items.size();
37
38        free.assign(n, 0);
39
40        memo.assign(
41            n,
42            vector<array<int, 2>>(budget + 1, array<int, 2>{-1, -1})
43        );
44
45        for (int i = 0; i < n; i++) {
46            for (int j = 0; j < n; j++) {
47
48                if (i != j &&
49                    items[j][0] % items[i][0] == 0) {
50
51                    free[i]++;
52                }
53            }
54        }
55
56        return func(0, items, budget, 1);
57    }
58};