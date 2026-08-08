// Last updated: 8/8/2026, 10:15:46 AM
1class Solution {
2public:
3    vector<int> minOperations(string boxes) {
4int n = boxes.size();
5        vector<int> res(n);
6        int str = 0;
7        int cnt = 0;
8        for(int i=0;i<n;i++){
9             if(boxes[i]=='1'){ str+=i;
10                              cnt +=1;}
11        }
12         res[0] = str;
13         if(boxes[0]=='1') cnt--;
14         for(int i=1 ;i<n;i++){
15
16             str -= cnt;
17             res[i] = str;
18             if(boxes[i]=='1') cnt--;
19             
20         }
21         str = 0;
22         cnt =0;
23        for(int i= n-1;i>=0 ;i--){
24             if(boxes[i]=='1'){ str+=(n-1-i);
25                              cnt +=1;}
26        }
27        res[n-1] += str;
28        if(boxes[n-1]=='1') cnt--;
29
30        for(int i= n-2;i>=0 ;i--){
31               str -= cnt;
32             res[i] += str;
33             if(boxes[i]=='1') cnt--;
34        }
35        return res;
36    }
37};