// Last updated: 9/2/2026, 11:43:30 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        
5     int lo = 0;
6     int hi = matrix.size()-1;
7     int ans =  -1;
8     while(lo <= hi){
9       int mid=  lo + (hi - lo )/2;
10
11
12        if( target < matrix[mid][0] ){
13                  hi =mid-1;
14        }else if(target > matrix[mid][matrix[0].size()-1] ){
15                 lo=mid+1;
16        }else{
17            ans = mid;
18            break;
19        }
20     }
21
22     lo = 0;
23     hi = matrix[0].size()-1;
24     if(ans == -1) return false;
25     while(lo <= hi){
26         int mid=  lo + (hi - lo )/2;
27           
28           if(target > matrix[ans][mid]){
29               lo =mid+1;
30           }else if(target < matrix[ans][mid]){
31          hi = mid-1;
32           }else{
33            return true;
34           }
35
36     }
37
38        return false;
39    }
40};