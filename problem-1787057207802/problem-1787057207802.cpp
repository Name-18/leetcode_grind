// Last updated: 8/18/2026, 6:16:47 PM
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4
5        string s1 =  s;
6
7        map<char,int> mpp;
8        for(auto it : s){
9            mpp[it]+=1;
10        }
11
12        for(auto &it : mpp){
13            if(it.second %2){
14                s1[(int)(s.size()/2)] = it.first;
15                it.second-=1;
16            }
17        }
18        int i =0;
19        int  j = s.size()-1;
20        
21             for(auto &it : mpp){
22
23                 while(it.second){
24                s1[i] = it.first;
25                 s1[j] =it.first;
26                     it.second-=2;
27                     i++;
28                     j--;
29                 }
30        }
31        return s1;
32    }
33};