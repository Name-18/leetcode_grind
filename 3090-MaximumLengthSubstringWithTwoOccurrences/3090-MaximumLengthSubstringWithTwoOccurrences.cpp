// Last updated: 6/19/2026, 3:14:52 AM
1class Solution
2{
3public:
4    int maximumLengthSubstring(string s)
5    {
6        int n = s.size();
7        int ans = 0;
8        for (int i = 0; i < n; i++)
9        {
10            unordered_map<char, int> mp;
11            for (int j = i; j < n; j++)
12            {
13                mp[s[j]]++;
14                if (mp[s[j]] > 2)
15                    break;
16                ans = max(ans, j - i + 1);
17            }
18        }
19        return ans;
20    }
21};