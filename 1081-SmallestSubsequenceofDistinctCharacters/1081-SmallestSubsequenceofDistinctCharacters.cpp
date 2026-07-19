// Last updated: 7/20/2026, 12:23:12 AM
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int>hash(26,0),used(26,0);
5        for(auto ch : s) hash[ch-'a']++;
6
7        string ans="";
8        for(auto ch : s)
9        {
10            hash[ch-'a']--;
11            if(used[ch-'a']>0)continue;
12            while(!ans.empty() && ans.back()>ch && hash[ans.back()-'a']>0)
13            {
14                used[ans.back()-'a']=0;
15                ans.pop_back();
16            }
17            ans+=ch;
18            used[ch-'a']=1;
19        }
20    return ans;
21    }
22};