// Last updated: 11/13/2026, 10:49:38 PM
1class Solution {
2public:
3    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
4
5        int n =  s1.size();
6 vector<vector<string>> ans;
7        string a="";
8        string b="";
9        bool tr = false;
10        for(int i=0;i<n;i++){
11
12            if(s1[i] != s2[i]){
13                a+= s1[i];
14                b+=s2[i];
15                tr = true;
16            }else{
17               if(tr) {vector<string> tmp;
18                tmp.push_back(a);
19                tmp.push_back(b);
20                
21                ans.push_back(tmp);
22                a="";
23                b="";
24                       tr = false;
25                      }
26            }
27        }
28        if(a.size()!=0){
29              vector<string> tmp;
30                tmp.push_back(a);
31                tmp.push_back(b);
32            ans.push_back(tmp);
33        }
34        return ans;
35    }
36};