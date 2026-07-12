// Last updated: 7/12/2026, 1:10:25 PM
1class Solution {
2public:
3     int func(vector<int> &arr , int x ){
4
5           int low = 0 ;
6           int high =  arr.size()-1;
7
8           while(low <= high){
9
10            int mid = (low+high)/2 ; 
11
12            if(arr[mid] < x ){
13                high = mid-1;
14            }else{
15                low = mid+1;
16
17            }
18           }
19          return high ;
20     }
21    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
22        int ans = 0;
23         for(int i=0;i<nums1.size();i++){
24            int j = func(nums2,nums1[i]);
25
26            if(j>=i){
27                ans = max(ans, j-i);
28            }
29         }
30         return ans;
31    }
32};