// Last updated: 9/9/2026, 12:30:59 PM
1class Solution {
2public:
3    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
4        vector<int> st;
5int n = pushed.size();
6        int i = 0;
7        int j = 0;
8
9        while( i< n or j<n){
10
11            if(!st.empty() and st.back() == popped[j]){
12                st.pop_back();
13                j++;
14            }else if(i<n){
15                st.push_back(pushed[i++]);
16            }else{
17        return false;
18            }
19        }
20        return true;
21    }
22};