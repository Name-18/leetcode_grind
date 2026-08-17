// Last updated: 8/17/2026, 12:18:28 PM
1class Solution {
2public:
3vector<int> arr;
4vector<int> pref;
5int tot ;
6vector<vector<int>> dp;
7    int func(int l ,int r){
8               if(l == r) return 0;
9               if(1 > r) return  -1e9;
10                       
11                       if(dp[l][r]!=-1) return dp[l][r];
12                    int res = 0;
13                    int tot = pref[r];
14
15                    if(l>0){
16                           tot-= pref[l-1]; 
17                    }
18                    int left = 0;
19                    int right =0;
20               for(int m = l ;m<r ;m++){
21                        
22                        left += arr[m];
23                        right = tot-left;
24                           
25
26                           if(left > right){
27                                       res =  max(res, right + func(m+1 ,r));              
28                           }else if(right > left){
29                                            res = max( res , left + func(l,m));
30                           }else{
31                        res =    max({ res ,left +  func(l,m) ,right + func(m+1 ,r) });
32                           }
33
34               }
35               return  dp[l][r] = res;
36        
37    }
38    int stoneGameV(vector<int>& stoneValue) {
39        
40        this->arr= stoneValue;
41        int n =  stoneValue.size();
42       this->pref.assign(stoneValue.size(),0);
43        this->pref[0] = this->arr[0];
44        this->tot = arr[0];
45        for(int i=1;i<stoneValue.size();i++){
46             this->tot += arr[i];
47            this->pref[i] =  this->pref[i-1] + stoneValue[i];
48        }
49dp.assign(n,vector<int> (n,-1));
50        return func(0,stoneValue.size()-1);
51    }
52};