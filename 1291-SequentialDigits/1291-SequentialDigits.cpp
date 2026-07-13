// Last updated: 7/13/2026, 1:11:15 PM
1class Solution {
2public:
3vector<int> vec;
4  void func(int st){
5          int num = 0;
6          
7          for(int i=st;i<=9;i++){
8            num*=10;
9            num+=i;
10            vec.push_back(num);
11          }
12  }
13    vector<int> sequentialDigits(int low, int high) {
14        
15            func(1);
16            func(2);
17            func(3);
18            func(4);
19            func(5);
20            func(6);
21            func(7);
22            func(8);
23            func(9);
24            
25
26
27      sort(vec.begin(),vec.end());
28
29    auto end =  upper_bound(vec.begin(),vec.end(),high) - vec.begin();
30    end --;
31    auto st =   lower_bound(vec.begin(),vec.end(),low) - vec.begin();
32            vector<int> res;
33
34            for(int i = st;i<=end;i++){
35                res.push_back(vec[i]);
36            }
37
38            return res;
39                }
40};