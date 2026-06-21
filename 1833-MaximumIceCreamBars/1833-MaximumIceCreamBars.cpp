// Last updated: 6/21/2026, 9:49:47 PM
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        
5         sort(costs.begin(),costs.end());
6
7        //  for(int i=1;i<costs.size();i++){
8        //     costs[i] += costs[i-1];
9        //  }
10      int ans =0;
11      int i=0;
12        for(int i=0;i<costs.size();i++){
13            if(coins-costs[i]>=0){
14                coins -=costs[i];
15                ans+=1;
16            }else{
17                break;
18            }
19        }
20        return ans;
21    }
22};