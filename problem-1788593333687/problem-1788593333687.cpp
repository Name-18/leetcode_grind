// Last updated: 9/5/2026, 12:58:53 PM
1class Solution {
2public:
3  string check(int num,int n, int k){
4       int cnt = 0;
5       int sim = 0;
6      string s = "";
7      for(int i=n-1;i>=0;i--){
8          int x = 1<<i;
9         
10          if((num&x)!=0){
11              
12              if(cnt ==1) return "null";
13              cnt = 1;
14              sim += i;
15              s +='1';
16          }else{
17              cnt=0;
18              s +='0';
19          }
20          
21          
22      }
23      if(sim > k ) return "null";
24      reverse(s.begin(),s.end());
25      return s;
26  }
27    vector<string> generateValidStrings( int n, int k) {
28
29        int mask =  1<<n;
30        mask -=1;
31
32vector<string > ans;
33        for(int i=0;i<=mask;i++){
34
35           if(check(i,n,k) != "null"){
36              ans.push_back(check(i,n,k));
37           }
38        }
39
40   return ans; }
41};