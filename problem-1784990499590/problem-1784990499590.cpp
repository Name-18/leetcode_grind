// Last updated: 7/25/2026, 8:11:39 PM
1class Solution {
2public:
3      int func(int idx , vector<int> &num ,int a , int b){
4
5          if(idx == num.size()){
6              if(a == 0 and b==0 )return 1e9;
7              
8              return a + b;
9          }
10
11          int x = func(idx+1, num , a * 10 + num[idx] , b);
12          int y = func(idx+1, num , a , b * 10 + num[idx] );
13
14          return min(x , y);
15      }
16    int splitNum(int n) {
17       vector<int> num;
18
19        while(n){
20            int t = n%10;
21            n/=10;
22            num.push_back(t);
23            cout<<t<<" ";
24        }
25        sort(num.begin(),num.end());
26        return func(0,num,0,0);
27    }
28};