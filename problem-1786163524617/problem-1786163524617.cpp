// Last updated: 8/8/2026, 10:02:04 AM
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        string ans = "";
5        for (int i = 0; i < min(word1.size(), word2.size()); i++) {
6            ans += word1[i];
7            ans += word2[i];
8        }
9        if(word1.size() >word2.size()){
10
11            for(int i=word2.size();i<word1.size();i++){
12                ans += word1[i];
13            }
14        }
15        if(word1.size() < word2.size()){
16                        for(int i=word1.size();i<word2.size();i++){
17                ans += word2[i];
18            }
19        }
20        return ans;
21    }
22};