// Last updated: 6/22/2026, 3:51:17 PM
1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        
5        unordered_map<char,int> mpp;
6         mpp['l']=0;;
7        mpp['o']=0;
8         mpp['b']=0;
9        mpp['a']=0;
10        mpp['n']=0;
11        for(auto &it : text){
12
13            if(it=='b' or it == 'a' or it=='l' or it == 'o' or it =='n'){
14                mpp[it] += 1;
15
16            }
17        }
18        mpp['l']/=2;
19        mpp['o']/=2;
20        int ans = (int)text.size()/7;
21        for(auto it: mpp){
22        ans = min(it.second,ans);
23        }
24        return ans;
25    }
26};