// Last updated: 8/19/2026, 12:31:26 PM
1class Solution {
2public:
3    vector<int> divisibilityArray(string word, int m) {
4
5        long long num = 0;
6        long long rem = 0;
7        vector<int> div;
8        for(int i = 0 ;i<word.size() ;i++){
9
10            num*=10;
11            num += word[i] - '0';
12            
13            int rem = num % m;
14
15            if(rem == 0){
16                num = 0;
17                div.push_back(1);
18            }else{
19                num = rem;
20                 div.push_back(0);
21            }
22            
23        }
24
25
26        return div;
27
28        
29    }
30};