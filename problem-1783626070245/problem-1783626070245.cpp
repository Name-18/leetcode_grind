// Last updated: 7/10/2026, 1:11:10 AM
1class Solution {
2public:
3    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
4
5        vector<int> mpp(26,0);
6        for(char ch = 'a' ;ch<='z' ;ch++){
7            mpp[ch-'a'] = (ch - 'a') +1 ;
8        }
9
10        for(int i = 0; i< chars.size() ;i++){
11             mpp[chars[i]-'a'] = vals[i];
12        }
13        int maxi = 0;
14        int curr = 0;
15        
16        for( int i =0;i<s.size() ; i++){
17
18            int idx = s[i] - 'a';
19
20            curr += mpp[idx] ;
21
22            maxi = max(maxi,curr);
23            if(curr<0){
24                curr = 0;
25            }
26            
27        }
28        maxi = max(maxi,curr);
29
30        return maxi;
31    }
32};