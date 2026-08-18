// Last updated: 8/18/2026, 1:21:40 PM
1class Solution {
2public:
3
4    bool find(vector<int> &frst , vector<int>&snd){
5
6        sort(frst.begin() ,  frst.end());
7        sort(snd.begin() ,  snd.end());
8
9        for(auto it : frst){
10
11            auto t = upper_bound(snd.begin() , snd.end() , it) ;
12
13           if (t != snd.begin()) {
14    t--;
15    if (*t == it) {
16      
17        return true;
18    }
19}
20
21            
22        }
23        return false;
24    }
25    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
26
27        set<int> node;
28        int plp = languages.size();
29        for(auto it :  friendships ){
30
31            int x = it[0]-1;
32            int y = it[1]-1;
33
34          if(!find(languages[x] , languages[y])){
35               node.insert(x);
36               node.insert(y);
37              
38          }
39        }
40
41        map<int,int> mpp;
42       
43        for(auto it : node){
44
45            for(auto t : languages[it]){
46                mpp[t]+=1;
47            }
48        }
49
50        int to_teach = node.size();
51         int mp = to_teach;
52        for(auto it : mpp){
53            
54             mp = min(mp , to_teach - it.second);
55        }
56          return mp;
57    }
58};