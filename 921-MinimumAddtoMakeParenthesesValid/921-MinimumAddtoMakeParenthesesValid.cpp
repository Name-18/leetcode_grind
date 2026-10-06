// Last updated: 10/6/2026, 11:27:25 PM
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        
5        vector<char> ch;
6        int rm = 0;
7        for(auto &it : s){
8          
9            if(it == '('){
10                ch.push_back(it);
11            }
12            else {
13
14                if(ch.size()>0){
15                    ch.pop_back();
16                }else{
17                    rm+=1;
18                }
19            }
20           
21        }
22
23       
24
25        return rm + ch.size();
26    }
27
28};