// Last updated: 8/19/2026, 10:17:01 PM
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
4        sort(nums.begin(), nums.end());
5         int last = 0;
6        vector<int> pr;
7        int one = 1;
8        int two = 1;
9        int tree = 1;
10        int res = 0;
11        for (auto it : nums) {
12
13            if (last != it[0]) {
14                  
15                if (!pr.empty()) {
16
17                    for (auto it : pr) {
18
19                        if (it == 2 or it == 3) {
20                            one--;
21                        } else if (it == 4 or it == 5) {
22                            one--;
23                            two--;
24                        } else if (it == 6 or it == 7) {
25                            tree--;
26                            two--;
27                        } else if (it == 8 or it == 9) {
28                            tree--;
29                        }
30                    }
31                         
32
33                         if(one == 1 and tree ==1){
34                            res+=2;
35                         }
36                         else if(one == 1 or two==1 or tree ==1){
37                            res+=1;
38                         }
39                         one=1;
40                         two=1;
41                         tree=1;
42                         pr.clear();
43                }
44                int diff = it[0] - last;
45                if(diff>1){
46                    
47                    res += (diff-1)*2;
48
49                }
50                     last = it[0];
51
52                     pr.push_back(it[1]);
53            } else {
54
55                pr.push_back(it[1]);
56            }
57        }
58         if (!pr.empty()) {
59
60                    for (auto it : pr) {
61
62                        if (it == 2 or it == 3) {
63                            one--;
64                        } else if (it == 4 or it == 5) {
65                            one--;
66                            two--;
67                        } else if (it == 6 or it == 7) {
68                            tree--;
69                            two--;
70                        } else if (it == 8 or it == 9) {
71                            tree--;
72                        }
73                    }
74                    
75                        if(one == 1 and tree ==1){
76                            res+=2;
77                         }
78                         else if(one == 1 or two==1 or tree ==1){
79                            res+=1;
80                         }
81         }
82         int diff = n - last;
83
84         if(diff>0){
85            res+= diff*2;
86         }
87        return res;
88    
89    }
90};