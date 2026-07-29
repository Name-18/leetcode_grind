// Last updated: 7/29/2026, 11:18:35 PM
1class Solution {
2public:
3    long long ncr(int n, int r, int k) {
4        long long ans = 1;
5        r = min(r , n-r);
6        for (int i = 1; i <= r; i++) {
7            ans = ans * (n - i + 1) / i;
8            if (ans >= k)
9                return k;
10        }
11        return ans;
12    }
13    string smallestPalindrome(string s, int t) {
14         int lim = t;
15        char mid = '_';
16        if (s.size() % 2) {
17            mid = s[s.size() / 2];
18        }
19
20        int n = s.size();
21        string st = "";
22        vector<int> count(26,0);
23        if (n % 2) {
24            for (int i = 0; i < n / 2; i++) {
25                st += s[i];
26                count[s[i]-'a']++;
27            }
28        } else {
29            for (int i = 0; i < n / 2; i++) {
30                st += s[i];
31                count[s[i]-'a']++;
32            }
33          
34        }
35
36      string ans="";
37
38      for(int i=0;i<n/2  ;i++){
39              bool flg =  false;
40        for(int j=0;j<26;j++){
41
42            if(count[j]>0){
43
44                count[j]--;
45
46                int letters = 0;
47                long long ways = 1 ;
48
49                for(int k=0;k<26;k++){
50                    letters+=count[k];
51                }
52
53                for(int k=0;k<26;k++){
54                    ways *= ncr(letters , count[k] , lim);
55                   
56                    letters -= count[k];
57                     if(ways >= lim) break;
58                }
59                 
60                 if(ways < t){
61                     t-= ways;
62                     count[j]+=1;
63                     
64                 }else{
65                       flg = true;
66                    ans.push_back(('a' + j));
67                     break;
68                 }
69                
70            }
71        }
72        if(!flg) return "";
73      }
74      
75      string rev = ans;
76      reverse(rev.begin(),rev.end());
77
78      if(mid!='_'){
79        ans += mid;
80
81      }
82      ans += rev;
83
84      return ans;
85    }
86};