// Last updated: 7/29/2026, 8:35:21 PM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        
5        int n = s.size();
6             string k = s;
7             map<char,int> mpp;
8             char od ;
9             for(auto &it : s){
10                mpp[it]+=1;
11            
12             }
13             for(auto &it : mpp){
14                 if(it.second % 2){
15                    od = it.first;
16                 }
17             }
18           
19
20        if(n%2==1){
21                int mid = n/2;
22                k[mid] = od;
23                mpp[od]--;
24                  int i =0;
25                int j=n-1;
26        for(auto &it:mpp){
27                int x = it.second;
28              
29                while(x>0){
30                                 k[i] = it.first;
31                                 k[j] = it.first;
32                                 i++;
33                                 j--;
34                                 x-=2;
35                }
36              }
37            
38        }else{
39              int i =0;
40                int j=n-1;
41        for(auto &it:mpp){
42                int x = it.second;
43              
44                while(x>0){
45                                 k[i] = it.first;
46                                 k[j] = it.first;
47                                 i++;
48                                 j--;
49                                 x-=2;
50                }
51              }
52        }
53        return k;
54    }
55
56
57};