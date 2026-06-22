// Last updated: 6/22/2026, 4:38:33 PM
1class Solution {
2public:
3    int check(string s,int n){
4
5        int k =0;
6
7        for(auto it : s){
8
9            k = k * 10;
10            k += (it - '0');
11            
12        }
13        if(k==0) return 0;
14
15        return (n%k)==0;
16    }
17    int divisorSubstrings(int num, int k) {
18
19        string s = to_string(num);
20 int ans = 0;
21        for(int i=0;i<=s.size()-k;i++){
22            string n="";
23            for(int j=0;j<k;j++){
24                n += s[i+j];
25            }
26            ans += check(n,num);
27        }
28        return ans;
29    }
30};