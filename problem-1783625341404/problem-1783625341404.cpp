// Last updated: 7/10/2026, 12:59:01 AM
1class Solution {
2public:
3    int minNumber(vector<int>& nums1, vector<int>& nums2) {
4
5        sort(nums1.begin() , nums1.end());
6        sort(nums2.begin() , nums2.end());
7
8          // for single digit 
9        for(auto & it : nums1){
10
11
12           auto flg =  binary_search(nums2.begin(),nums2.end(),it);
13             if(flg == true){
14                 return it;
15             }
16        }
17        int d1 =  nums1[0];
18        int d2 =  nums2[0];
19        if(d1 > d2){
20            swap(d1,d2);
21        }
22        return d1*10 + d2 ;
23    }
24};