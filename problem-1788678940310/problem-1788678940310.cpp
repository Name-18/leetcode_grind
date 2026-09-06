// Last updated: 9/6/2026, 12:45:40 PM
1class Solution {
2public:
3    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
4
5        vector<int> n_speed;
6        vector<int> n_pos;
7        int n = position.size();
8        n_speed.push_back(speed[0]);
9        n_pos.push_back(position[n-1]);
10        for (int i = 1; i < position.size(); i++) {
11
12            if (abs(position[i] - position[i - 1]) <= distance) {
13
14                if (n_speed.empty()) {
15                    n_speed.push_back(speed[i]);
16                    n_pos.push_back(position[i]);
17                } else {
18                    n_speed.pop_back();
19                    n_pos.pop_back();
20                    n_speed.push_back(speed[i]);
21                    n_pos.push_back(position[i]);
22                }
23            } else {
24
25                n_speed.push_back(speed[i]);
26                n_pos.push_back(position[i]);
27            }
28        }
29
30        for(int i= n-2;i>=0;i--){
31            if (abs(position[i] - position[i + 1]) <= distance) {
32
33                if (n_pos.empty()) {
34                   
35                    n_pos.push_back(position[i+1]);
36                } else {
37                 
38                    n_pos.pop_back();
39                    
40                    n_pos.push_back(position[i+1]);
41                }
42            } else {
43
44             
45                n_pos.push_back(position[i]);
46            }
47            
48        }
49
50      
51
52        int en = n_speed.size();
53        int grp = n_speed.size();
54     int init = n_speed[en-1];
55        for (int i = en-2 ; i >=0; i--) {
56
57            if (n_speed[i] > init) {
58                
59                grp--;
60            } else {
61                init = n_speed[i];
62            }
63        }
64
65        return grp;
66    }
67};