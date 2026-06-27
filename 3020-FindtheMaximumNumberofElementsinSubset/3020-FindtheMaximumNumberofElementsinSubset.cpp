// Last updated: 6/28/2026, 1:11:14 AM
1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<int, int> freq;
5        for (auto& n : nums)
6            freq[n]++;
7
8        int res = (freq[1] - 1) | 1;
9        freq.erase(1);
10
11        for (auto& f : freq) {
12            int n = 0, x = f.first;
13
14            int sq = sqrt(x);
15            if (sq * sq == x && freq.count(sq) && freq[sq] > 1)
16                continue;
17
18            while (x < 31623 && freq.count(x) && freq[x] > 1) {
19                n += 2;
20                x *= x;
21            }
22
23            res = fmax(res, n + ((freq.count(x) << 1) - 1));
24        }
25
26        return res;
27    }
28};
29