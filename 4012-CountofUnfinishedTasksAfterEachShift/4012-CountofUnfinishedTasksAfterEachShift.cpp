// Last updated: 9/12/2026, 1:19:29 PM
1class Solution {
2public:
3    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
4
5        long long tot = accumulate(tasks.begin(), tasks.end(), 1LL * 0);
6        int n = tasks.size();
7        int m = shifts.size();
8        vector<int> grp(m, -1);
9        int t = 1;
10        long long sm = 0;
11        for (int i = 0; i < m; i++) {
12
13            grp[i] = t;
14            sm += shifts[i];
15            if (sm >= tot) {
16                sm = 0;
17                t += 1;
18            }
19        }
20
21        vector<long long> prefs(m, 0);
22        prefs[0] = shifts[0];
23
24        for (int i = 1; i < m; i++) {
25
26            if (grp[i] == grp[i - 1]) {
27                prefs[i] = prefs[i - 1] + shifts[i];
28            } else {
29                prefs[i] = shifts[i];
30            }
31        }
32        vector<long long> pref(n,0);
33        pref[0] = tasks[0];
34        for(int i=1;i<n;i++){
35            pref[i] = pref[i-1] + tasks[i];
36        }
37 
38vector<int> ans;
39        for(int i=0;i<m;i++){
40              
41              long long val = prefs[i];
42
43              auto it =  upper_bound(pref.begin(),pref.end() , val )- pref.begin();
44              it--;
45             
46              if(it>=0 and it<n){
47              ans.push_back( n - (it+1));
48              }else{
49            ans.push_back(n);
50              }
51        }
52        return ans;
53    }
54};