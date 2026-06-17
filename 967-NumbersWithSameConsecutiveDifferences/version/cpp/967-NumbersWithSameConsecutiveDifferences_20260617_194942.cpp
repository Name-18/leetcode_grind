// Last updated: 6/17/2026, 7:49:42 PM
1class Solution {
2public:
3vector<int> d;
4vector<int> ans;
5int k;
6int n;
7    void func(int idx ,int tight,int num,int prev){
8         if(idx==n){
9
10       ans.push_back(num);
11        return ;
12         }
13         int i = (tight)? 1 :0;
14
15         for(i ;i<=9;i++){
16             
17             if(tight){
18                  
19                  func(idx+1,0,i,i);
20             }else{
21                    if(abs(prev-i)==k){
22                        int t = num*10 + i;
23                        func(idx+1,0,t,i);
24                    }
25             }
26         }
27
28    }
29    vector<int> numsSameConsecDiff(int n, int k) {
30        string s = to_string(n);
31        this->k = k;
32        this->n=n;
33        for(auto it: s){
34           this->d.push_back(it-'0');
35        }
36func(0,1,0,0);
37
38return ans;
39    }
40};