// Last updated: 9/2/2026, 11:56:22 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int n= matrix.size();
5        for(int i=0;i<n;i++){
6           
7           int lo = 0;
8           int hi = matrix[0].size()-1;
9
10
11            while(lo <= hi){
12         int mid=  lo + (hi - lo )/2;
13           
14           if(target > matrix[i][mid]){
15               lo =mid+1;
16           }else if(target < matrix[i][mid]){
17          hi = mid-1;
18           }else{
19            return true;
20           }
21
22        }
23        }
24        return false;
25        }
26};