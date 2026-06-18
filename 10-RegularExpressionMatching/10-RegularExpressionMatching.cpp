// Last updated: 6/19/2026, 3:29:30 AM
1class Solution {
2public:  
3  map<int,vector<char>> mpp;
4  vector<string> ans;
5      void func(int i , string &digits,string s){
6       if(i>=digits.size()){
7            ans.push_back(s);
8            return ;
9       }
10        
11        for(auto it:mpp[digits[i]]){
12          
13            string t = s + it;
14          
15                 func(i+1,digits,t);
16        }
17      }
18    vector<string> letterCombinations(string digits) {
19         
20         mpp['2'] ={'a','b','c'};
21         mpp['3'] ={'d','e','f'};
22         mpp['4'] ={'g','h','i'};
23         mpp['5'] ={'j','k','l'};
24         mpp['6'] ={'m','n','o'};
25         mpp['7'] ={'p','q','r','s'};
26         mpp['8'] ={'t','u','v'};
27         mpp['9'] ={'w','x','y','z'};
28
29     func(0,digits,"");
30return ans;
31    }
32};