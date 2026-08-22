// Last updated: 8/22/2026, 6:51:59 PM
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        
5        vector<int> r;
6        vector<int> c;
7        for(int i=0;i<matrix.size();i++){
8            for(int j=0;j<matrix[0].size();j++){
9                if(matrix[i][j]==0){
10                    r.push_back(i);
11                    c.push_back(j);
12                }
13            }
14        }
15
16        for(auto &it : r){
17
18            for(int i=0;i<matrix[0].size();i++){
19
20                matrix[it][i]=0;
21            }
22        }
23        for(auto &it : c){
24
25            for(int i=0;i<matrix.size();i++){
26
27                matrix[i][it]=0;
28            }
29        }
30
31            
32    }
33};