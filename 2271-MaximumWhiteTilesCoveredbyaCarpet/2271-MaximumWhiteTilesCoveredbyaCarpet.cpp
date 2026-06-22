// Last updated: 6/22/2026, 7:57:33 PM
1class Solution {
2public:
3    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
4
5        sort(tiles.begin(), tiles.end());
6
7        int n = tiles.size();
8
9        vector<long long> pref(n);
10        vector<int> starts;
11
12        pref[0] = tiles[0][1] - tiles[0][0] + 1;
13        starts.push_back(tiles[0][0]);
14
15        for(int i = 1; i < n; i++) {
16            pref[i] = pref[i-1] +
17                      (tiles[i][1] - tiles[i][0] + 1);
18            starts.push_back(tiles[i][0]);
19        }
20
21        long long ans = 0;
22
23        for(int i = 0; i < n; i++) {
24
25            long long ed = 1LL * tiles[i][0] + carpetLen - 1;
26
27            int idx =
28                upper_bound(starts.begin(),starts.end(),ed)
29                - starts.begin() - 1;
30
31            long long full = 0;
32
33            if(idx > i) {
34                full = pref[idx-1]
35                     - (i ? pref[i-1] : 0);
36            }
37
38            long long par =
39                max(0LL,
40                    min(ed, (long long)tiles[idx][1])
41                    - tiles[idx][0] + 1);
42
43            ans = max(ans, full + par);
44        }
45
46        return (int)ans;
47    }
48};