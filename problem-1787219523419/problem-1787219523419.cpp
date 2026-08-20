// Last updated: 8/20/2026, 3:22:03 PM
1class Solution {
2public:
3    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
4
5        set<int>st1;
6        set<int>st2;
7        for(auto &it : nums1){
8            st1.insert(it);
9        }
10        for(auto &it : nums2){
11            st2.insert(it);
12        }
13         int n =  nums1.size()/2;
14        int cnt = 0;
15
16        for(auto &it : st1){
17
18            if(st2.find(it) != st2.end()) cnt+=1;
19        }
20
21        int a = st1.size();
22        int b =st2.size();
23
24        if(b > a ){
25            swap(a,b);
26        }
27        
28        int a_u = a-cnt;
29        int t = min(a_u , n);
30        int res = t;
31        int rem =  n - t;
32         
33          int t2 =  min (cnt , rem);
34          res+=t2;
35          b-=t2;
36        
37         res += min(b , n);
38        
39       
40        return res;
41    }
42};