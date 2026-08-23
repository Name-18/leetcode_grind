// Last updated: 8/23/2026, 12:29:27 PM
1class Solution {
2public:
3    string func(int num){
4        return bitset<8>(num).to_string();
5    }
6    bool pali(string &s){
7
8        int i = 0;
9        int j =  s.size()-1;
10        while(j>=i){
11            if(s[i]!=s[j]){
12             return false;
13            }
14
15               i++;
16                j--;
17        }
18        return true;
19    }
20    bool isPalindromic(string s) {
21        //cout<<static_cast<int> (s[0]);
22        
23        string op;
24        for(int i=0;i<(int)s.size();i++){
25              op += func(static_cast<int>(s[i]));
26        }
27        
28        return pali(op);
29    }
30};