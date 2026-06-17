// Last updated: 6/17/2026, 2:37:18 PM
1class Solution {
2public:
3    int findSpecialInteger(vector<int>& arr) {
4        map<int,int> mpp;
5        for(auto ut:arr){
6            mpp[ut]+=1;
7        }
8        int sz =arr.size();
9        for(auto it:mpp){
10            if(it.second > sz/4){
11                return it.first;
12            }
13        }
14        return -1;
15    }
16};