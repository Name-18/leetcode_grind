// Last updated: 7/7/2026, 2:25:11 PM
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        
5        string s = to_string(n);
6         long long num =0;
7         long long sum=0;
8        for(auto &it:s){
9            sum += (it-'0');
10            if(it == '0') continue;
11            else{
12           num*=10;
13           num+=(it-'0');
14           
15            }
16        }
17
18        num= num*sum;
19
20        return num;
21    }
22};