// Last updated: 9/10/2026, 1:23:11 PM
1class Solution {
2public:
3int mod = 1e9+7;
4    int peopleAwareOfSecret(int n, int d, int f) {
5         
6         vector<long long> vec(n+1,0);
7         vec[1]=1;
8        for(int i=1;i<=n;i++){
9
10            for(int j= i+d ; j<=n;j++){
11                      if(j == i+f) break;
12
13                      vec[j]+=vec[i];
14                      vec[j] %= mod;
15
16            }
17            cout<<vec[i] << " ";
18        }
19        
20        long long sum = 0;
21
22        int k = n;
23        while(f--){
24            sum += vec[k--];
25            sum %= mod;
26        }
27        
28        return sum;
29    }
30};