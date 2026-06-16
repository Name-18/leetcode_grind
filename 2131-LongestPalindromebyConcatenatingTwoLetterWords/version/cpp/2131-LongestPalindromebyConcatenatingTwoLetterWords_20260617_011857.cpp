// Last updated: 6/17/2026, 1:18:57 AM
1class Solution {
2public:
3    int longestPalindrome(vector<string>& words) {
4        
5        map<string,int> mpp;
6        for(auto it:words){
7            mpp[it]+=1;
8          
9        }
10        int length =0;
11
12        for(auto it:words){
13          
14            string rev = "";
15
16            rev+=it[1];
17            rev+=it[0];
18            
19            if(rev == it) continue;
20
21    int pairsFound = min(mpp[it], mpp[rev]);
22            length += pairsFound * 4;
23          mpp.erase(it);
24          mpp.erase(rev);
25
26        }
27       int odd = 0;
28        for(char k = 'a'; k<='z';k++){
29            string s ="";
30            s+= k;
31            s+=k;
32         length += (mpp[s] / 2) * 4;
33          if(mpp[s]%2==1){
34            odd++;
35          
36          }
37
38
39        }
40        if(odd>=1) length+=2;
41
42     
43
44        return length;
45    }
46};