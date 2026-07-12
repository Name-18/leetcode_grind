// Last updated: 7/12/2026, 2:59:17 PM
1class Solution {
2public:
3
4 bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
5               int n = mat.size();
6       for(int i=0;i<n;i++){
7        for(int j=0;j<n;j++){
8            if(mat[i][j] != target[i][j]) return false;
9        }
10       }
11       return true;
12 }
13    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
14        int n = mat.size();
15        if(check(mat,target)) return true;
16         vector<vector<int>> nt;
17         vector<vector<int>> oat;
18         vector<vector<int>> twt;
19          for(int j=0;j<n;j++ ){
20            vector<int> tmp;
21            for(int  i=n-1;i>=0;i--){
22                  tmp.push_back(mat[i][j]);
23            }
24            nt.push_back(tmp);
25          }
26          if(check(nt,target)) return true;
27          for(int j=0;j<n;j++ ){
28            vector<int> tmp;
29            for(int  i=n-1;i>=0;i--){
30                  tmp.push_back(nt[i][j]);
31            }
32            oat.push_back(tmp);
33          }
34         
35     if(check(oat,target)) return true;
36   for(int j=0;j<n;j++ ){
37            vector<int> tmp;
38            for(int  i=n-1;i>=0;i--){
39                  tmp.push_back(oat[i][j]);
40            }
41            twt.push_back(tmp);
42          }
43   if(check(twt,target)) return true;
44     return false;
45    }
46};