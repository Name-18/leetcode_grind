// Last updated: 6/20/2026, 8:17:42 PM
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4
5        vector<string> ch;
6        string s ="";
7        for(int i=0;i<n;i++){
8            s+='#';
9        }
10        for(int i=0;i<m;i++){
11            ch.push_back(s);
12        }
13    
14        bool flg = true;
15        int x =0;
16        int y =0;
17        ch[0][0]='.';
18
19        while(x!=m-1 and y!= n-1){
20
21            if(x<m-1){
22                x+=1;
23                ch[x][y]='.';
24            }
25            if(y<n-1){
26                  y+=1;
27                ch[x][y]='.';
28            }
29        }
30        while(x!=m-1){
31               x+=1;
32                ch[x][y]='.';
33            }
34        
35    while(y!= n-1){
36          y+=1;
37                ch[x][y]='.';
38    }
39        return ch;
40    }
41};