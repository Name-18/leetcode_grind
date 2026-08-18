// Last updated: 8/18/2026, 12:52:19 PM
1class Solution {
2public:
3    vector<int> findOriginalArray(vector<int>& changed) {
4        int n = changed.size();
5        sort(changed.begin(), changed.end());
6        
7        vector<int> arr(changed.size(), 0);
8        
9        map<int, int> mpp;
10        int xr = 0;
11        for (int i = 0; i < n; i++) {
12
13            int num = changed[i];
14            mpp[num] +=1;
15            if(num == 0) xr++;
16        }
17        vector<int> res;
18        for (int i = 0; i < n; i++) {
19            
20            int num = changed[i];
21            
22            if(num == 0) continue;
23            int dbl = 2 * num;
24
25            if (mpp.find(num) != mpp.end()) {
26
27                if (mpp.find(dbl) != mpp.end()) {
28
29                    res.push_back(num);
30                   
31                    mpp[dbl] -- ;
32                    if(mpp[dbl] == 0) mpp.erase(dbl);
33                }else{
34                    return {};
35                }
36                   mpp[num] -- ;
37                    if(mpp[num] == 0) mpp.erase(num);
38            }
39        }
40        
41        if(xr > 0 and xr % 2 == 0){
42                    xr/=2;
43            while(xr--){
44                res.push_back(0);
45            }
46        }else if(xr > 0) return {};
47        return res;
48    }
49};