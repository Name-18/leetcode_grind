// Last updated: 7/26/2026, 1:38:27 AM
1class Solution {
2public:
3     
4     vector<vector<int>> grd;
5
6     bool check(int x){
7         
8         vector<vector<int>> tmp = grd;
9
10         tmp[0][0] += x;
11         if(tmp[0][0] <= 0) return false;
12         bool flg = false;
13         for(int i=1;i<tmp[0].size();i++){
14            if(flg){
15                tmp[0][i] = -1e9;
16                continue;
17            }
18            tmp[0][i] += tmp[0][i-1] ;
19            if(tmp[0][i]<=0){
20                tmp[0][i] = -1e9;
21            flg = true;
22            }
23
24         }
25         flg = false;
26         for(int i=1;i<tmp.size();i++){
27            if(flg){
28                tmp[i][0] = -1e9;
29                continue;
30            }
31            tmp[i][0] += tmp[i-1][0] ;
32             if(tmp[i][0]<=0){tmp[i][0] = -1e9;
33            flg = true;
34            }
35         }
36         for(int i=1;i<tmp.size();i++){
37            for(int j=1 ;j<tmp[0].size();j++){
38                
39                int tp = tmp[i-1][j];
40                int right = tmp[i][j-1];
41                
42                if(tp == -1e9 and right == -1e9){
43                    tmp[i][j] = -1e9;
44                }
45                else if(tp == -1e9 ){
46                    tmp[i][j] += right;
47                      if(tmp[i][j]<=0) tmp[i][j] = -1e9;
48                }else if(right == -1e9){
49                    tmp[i][j] += tp;
50                      if(tmp[i][j]<=0) tmp[i][j] = -1e9;
51                }else{
52                    long t = max(tp , right);
53                    
54                    tmp[i][j] += t;
55
56                       if(tmp[i][j]<=0) tmp[i][j] = -1e9;
57                }
58            }
59         }
60         int n = tmp.size();
61         int m = tmp[0].size();
62         return tmp[n-1][m-1] > 0;
63     }
64    int calculateMinimumHP(vector<vector<int>>& dungeon) {
65        
66          this->grd = dungeon;
67        int lo = 1;
68        int hi = 1000000;
69
70        while(lo <=hi){
71            int mid = (lo+hi)/2;
72
73            if(check(mid)){
74                hi = mid-1;
75            }else {
76                lo =  mid+1;
77            }
78        }
79        return lo;
80    }
81};