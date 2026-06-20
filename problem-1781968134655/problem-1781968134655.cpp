// Last updated: 6/20/2026, 8:38:54 PM
1class Solution {
2public:
3    int minLights(vector<int>& lights) {
4
5int n = lights.size();
6        vector<int> vec(n,0);
7
8        for(int i=0;i<lights.size();i++){
9int v =lights[i];
10            if(lights[i]>0){
11
12                int l = max(0,i-v);
13                int r = min((int)lights.size()-1 , i+v);
14
15                vec[l]+=1;
16                if(r+1<n){
17                    vec[r+1]-=1;
18                }
19                
20            }
21        }
22      for(int i=1;i<n;i++){
23          vec[i] += vec[i-1];
24      }
25int ans =0;
26        int cnt =0;
27   for(int i=0;i<n;i++){
28
29       if(vec[i]==0){
30           cnt ++;
31       }else{
32           ans += (cnt+2)/3;
33           cnt =0;
34       }
35           
36       
37   }
38         ans += (cnt+2)/3;
39        return ans;
40    }
41};