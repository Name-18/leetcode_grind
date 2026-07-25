// Last updated: 7/25/2026, 8:43:45 PM
1class Solution {
2public:
3 int mod = 1e9+7;
4  static  bool cmp(vector<int>& a , vector<int>& b){
5        if(a[0]!=b[0]) return  a[0] < b[0];
6
7        return a[1]>b[1];
8    }
9    long long fast(int a , int b){
10     if(b==0){
11         return 1;
12     }
13        long long half = fast(a , b/2);
14         half%= mod;
15        long long ans = 1LL*half *half ;
16
17        if(b%2==1){
18            ans*=a;
19        }
20        return ans;
21    }
22    int countWays(vector<vector<int>>& ranges) {
23
24        sort(ranges.begin() , ranges.end(),cmp);
25
26       
27         vector<vector<int>> tmp;
28
29        for(auto &it : ranges){
30            if(tmp.empty()){
31                tmp.push_back(it);
32            }
33            else if( tmp.back()[1] >= it[0]){
34                int a = min(tmp.back()[0] , it[0]);
35                int b = max(tmp.back()[1] , it[1]);
36                tmp.pop_back();
37                tmp.push_back({a,b});
38            }else{
39                tmp.push_back(it);
40            }
41        }
42        int n = tmp.size();
43
44
45        long long t =  fast(2,n);
46
47        t = t% mod;
48        return t;
49    }
50};