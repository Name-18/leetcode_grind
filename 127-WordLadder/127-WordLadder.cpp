// Last updated: 7/18/2026, 3:58:52 PM
1class Solution {
2public:
3   
4    int bfs(string& s, set<string>& st, string& endWord) {
5       queue<pair<string,int>> q;
6
7
8q.push({s,1});
9
10
11while(!q.empty()){
12    auto [word,len]=q.front();
13    q.pop();
14
15    if(word==endWord) return len;
16
17    for(int i=0;i<word.size();i++){
18        char original=word[i];
19
20        for(char ch='a';ch<='z';ch++){
21            word[i]=ch;
22
23            if(st.count(word)){
24                q.push({word,len+1});
25                st.erase(word);
26            }
27        }
28
29        word[i]=original;
30    }
31}
32
33return 0;
34    }
35    int ladderLength(string beginWord, string endWord,
36                     vector<string>& wordList) {
37      set<string> st(wordList.begin(), wordList.end());
38
39        int ans = bfs(beginWord, st, endWord);
40        if(ans == 1e9){
41            return 0;
42        }
43        return ans;
44    }
45};