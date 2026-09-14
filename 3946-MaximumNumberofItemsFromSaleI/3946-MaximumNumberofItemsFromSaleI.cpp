// Last updated: 9/14/2026, 1:42:33 PM
1class Solution {
2public:
3   vector<vector<int>> vec;
4   int mini;
5    int fnc(int i , int bud  , vector<int> & copis,vector<vector<int>>& items){
6       
7        if(i<0)return bud/mini;
8        if(vec[i][bud]!=-1) return vec[i][bud];
9        int ans = fnc(i-1,bud,copis,items);
10        int prices=items[i][1];
11        if(bud>=prices){
12            int take = copis[i] + fnc(i-1,bud-prices,copis,items);
13            ans = max(ans,take); 
14        }
15        return vec[i][bud]=  ans;
16    }
17    int maximumSaleItems(vector<vector<int>>& items, int budget) {
18        vector<int> copis(items.size(),0);
19        int n = items.size();
20        mini=items[0][1];
21        vec.resize(n,vector<int> (budget+1,-1));
22            for(int i=0; i<n; i++) {
23            mini=min(mini, items[i][1]);
24            for(int j=0; j<n; j++) {
25                if(items[j][0]%items[i][0] == 0) copis[i]++;
26            }
27        }
28
29
30       return fnc(items.size()-1,budget,copis,items);
31    }
32};