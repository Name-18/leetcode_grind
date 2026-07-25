// Last updated: 7/25/2026, 10:45:57 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        
5        priority_queue<int , vector<int> ,greater<int>> q;
6
7        while(n){
8            int t = n%10;
9            n/=10;
10         
11            q.push(t);
12            if(q.size() > 2) q.pop();
13        }
14        int a = q.top();
15        q.pop();
16        int b = q.top();
17        cout<<a << " "<<b;
18        q.pop();
19        return a*b;    }
20};