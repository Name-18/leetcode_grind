// Last updated: 8/17/2026, 5:10:48 PM
1class Solution {
2public:
3    int distinctPoints(string s, int k) {
4
5        int x= 0;
6        int y= 0;
7
8        for(int i=0;i<k;i++){
9
10            if(s[i] == 'U'){
11                 y++;
12            }else if(s[i] == 'D'){
13                y--;
14            }else if(s[i] == 'L'){
15                x--;
16            }else{
17                x++;
18            }
19        }
20         set<pair<int,int>> st;
21        st.insert({x,y});
22
23        int r = k;
24        for(int l =  0; l+k<s.size();l++ , r++){
25
26             if(s[l] == 'U'){
27                 y--;
28            }else if(s[l] == 'D'){
29                y++;
30            }else if(s[l] == 'L'){
31                x++;
32            }else{
33                x--;
34            }
35
36             if(s[r] == 'U'){
37                 y++;
38            }else if(s[r] == 'D'){
39                y--;
40            }else if(s[r] == 'L'){
41                x--;
42            }else{
43                x++;
44            }
45            
46            st.insert({x,y});
47        }
48        return st.size();
49    }
50};