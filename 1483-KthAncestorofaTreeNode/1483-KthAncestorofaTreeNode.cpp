// Last updated: 7/6/2026, 11:48:22 PM
1class TreeAncestor {
2public:
3   int n;
4   vector<int> parent;
5   vector<vector<int>> dp;
6   int l;
7    TreeAncestor(int n, vector<int>& parent) {
8        this->n  = n;
9        this->parent  = parent;
10        this->l = log2(n)+1;
11        dp.assign(n,vector<int> (l,-1));
12         
13        for(int i=0;i<n;i++){
14            dp[i][0] = parent[i];
15        }
16        for(int j=1;j<l;j++){
17            for(int i=0;i<n;i++){
18
19                if(dp[i][j-1]!=-1){
20                    dp[i][j] = dp[dp[i][j-1]][j-1];
21                }
22            }
23        }
24
25    }
26    
27    int getKthAncestor(int node, int k) {
28          
29          for (int i = 0; i < l; i++) {
30            if (k & (1 << i)) {
31               
32                node = dp[node][i];
33                if (node == -1) return -1;
34            }
35        }
36        return node;
37    }
38};
39
40/**
41 * Your TreeAncestor object will be instantiated and called as such:
42 * TreeAncestor* obj = new TreeAncestor(n, parent);
43 * int param_1 = obj->getKthAncestor(node,k);
44 */