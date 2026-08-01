// Last updated: 8/1/2026, 12:13:38 PM
1class Solution {
2public:
3    using tp = pair<long long, int> ;
4
5    long long most(priority_queue<tp,vector<tp> , greater<tp>> &pq){
6
7        vector<tp> vec;
8        long long ans = 0;
9         while(!pq.empty()){
10
11                    auto t = pq.top();
12                    pq.pop();
13vec.push_back(t);
14                    ans = max(t.first,ans);
15                }
16 for(auto &it : vec){
17                    pq.push(it);
18                }
19        
20        return ans;
21    }
22    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
23       vector<long long> res;
24       unordered_map<int, long long> mpp;
25       priority_queue<tp,vector<tp> , greater<tp>> pq;
26        unordered_set<int> st;
27        for(int i=0;i<nums.size();i++){
28
29            int key = nums[i];
30            int val = freq[i];
31
32            mpp[key] += val;
33
34            if(st.find(key) != st.end()){
35
36                vector<tp> vec;
37                while(!pq.empty()){
38
39                    auto t = pq.top();
40                    pq.pop();
41
42                    if(t.second == key) continue;
43
44                    else{
45                        vec.push_back(t);
46                    }
47                }
48                
49                for(auto &it : vec){
50                    pq.push(it);
51                }
52            }
53            auto to =  make_pair( mpp[key] ,key);
54            st.insert(key);
55            pq.push(to);
56
57            if(pq.size() > 3){
58                auto it = pq.top();
59                pq.pop();
60                st.erase(it.second);
61            }
62
63             
64            res.push_back(most(pq));
65            
66        
67        }
68        return res;
69    }
70};