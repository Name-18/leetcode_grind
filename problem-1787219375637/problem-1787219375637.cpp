// Last updated: 8/20/2026, 3:19:35 PM
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
24          int only1 = st1.size() - cnt;
25        int only2 = st2.size() - cnt;
26
27        
28        int take1 = min(only1, n);
29        int take2 = min(only2, n);
30
31        int remaining = (n - take1) + (n - take2);
32
33        int takeCommon = min(cnt, remaining);
34
35        return take1 + take2 + takeCommon;
36    }
37};