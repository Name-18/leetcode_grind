// Last updated: 9/2/2026, 8:01:09 PM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        // [1,2,3,6,9,8,7,4,5]
5        int str = 0;
6        int enr = matrix.size()-1;
7        int stc = 0;
8        int enc = matrix[0].size()-1;
9        // 0 1 2 3
10        vector<int> ans;
11        
12        int dir = 0;
13        while( str <= enr && stc <= enc){
14            
15            if(dir == 0){
16            for(int k= stc ; k<=enc ;k++){
17              ans.push_back(matrix[str][k]);
18            }
19             dir +=1;
20             dir %= 4;
21             str+=1;
22       
23            }else if(dir ==1){
24            
25               for(int k= str ; k<=enr ;k++){
26              ans.push_back(matrix[k][enc]);
27            }
28             dir +=1;
29             dir %= 4;
30             enc-=1;
31        
32             
33
34            }else if(dir == 2){
35              
36            for(int k= enc ; k>=stc ;k--){
37              ans.push_back(matrix[enr][k]);
38            }
39             dir +=1;
40             dir %= 4;
41             enr-=1;
42
43
44            }else{
45              
46               for(int k= enr ; k>=str ;k--){
47              ans.push_back(matrix[k][stc]);
48            }
49             dir +=1;
50             dir %= 4;
51             stc+=1;
52
53
54            }
55
56        }
57        return ans;
58    }
59};