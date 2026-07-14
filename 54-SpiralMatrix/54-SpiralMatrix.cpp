// Last updated: 7/14/2026, 5:15:37 PM
1class Solution {
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        int a = matrix[0].size()-1;
5        int b = matrix.size()-1;
6        int up = 0;
7        int right = a;
8        int left = 0;
9        int down = b;
10
11        vector<int> answer;
12
13        while(up <= down && left <= right){
14            for(int i = left; i <= right; i++){
15                answer.push_back(matrix[up][i]);
16            }
17            up++;
18
19            for(int i = up; i <= down; i++){
20                answer.push_back(matrix[i][right]);
21            }
22            right--;
23
24            if(up <= down){
25                for(int i = right; i >= left; i--){
26                    answer.push_back(matrix[down][i]);
27                }
28            down--;
29            }
30
31            if(left <= right){
32                for(int i = down; i >= up; i--){
33                    answer.push_back(matrix[i][left]);
34                }
35            left++;
36            }
37        }
38        return answer;
39    }
40};