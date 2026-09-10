// Last updated: 9/10/2026, 5:53:47 PM
1class Solution {
2public:
3    int take =0;
4    vector<int> par;
5    vector<int> size;
6
7    int find(int x){
8
9        if(x == par[x]) return x;
10
11        return par[x] =find(par[x]);
12
13    }
14    void merge(int x , int y){
15
16        x= find(x);
17        y = find(y);
18         
19         if(x == y){
20            take += 1;
21            return;
22         }
23        if(size[x] < size[y]){
24
25           swap(x,y);
26        }
27
28        par[y] = x;
29        size[x]+= size[y];
30    }
31    int makeConnected(int n, vector<vector<int>>& connections) {
32        par.assign(n,0);
33        size.assign(n,1);
34
35        for(int i=0;i<n;i++){
36            par[i] = i;
37        }
38       
39       for(auto &it : connections){
40        merge(it[0] , it[1]);
41       }
42       for(int i=0;i<n;i++){
43        find(i);
44       }
45set<int> st;
46       for(int i=0;i<n;i++){
47        st.insert(par[i]);
48       }
49      return (st.size()-1) <= take ? st.size()-1 : -1;
50    }
51};