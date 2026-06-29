// Last updated: 6/29/2026, 10:49:11 PM
1static int lps[100];
2class Solution {
3public:
4    static void preKMP(const string& pattern){
5        int len=0;
6        const int n=pattern.size();
7        lps[0]=0;
8        for(int i=1; i<n; i++){
9            while(len>0 && pattern[i]!=pattern[len])
10                len=lps[len-1];
11            lps[i]=(pattern[i]==pattern[len])?++len:len;
12        }
13    }
14
15    static int KMPfind(const string& s, const string& pattern){
16        preKMP(pattern);
17        const int sz=s.size(), pz=pattern.size();
18        for(int i=0, j=0; i<sz; i++){
19            while(j!=0 && s[i]!=pattern[j]) 
20                j=lps[j-1];
21            if (s[i]==pattern[j]) j++;
22            if (j==pz) return i-j+1;// the index found
23        }
24        return -1;// no found
25    }
26
27    static int numOfStrings(vector<string>& patterns, string& word) {
28        int cnt=0;
29        for(const auto& p: patterns){
30            cnt+=KMPfind(word, p)!=-1;
31        }
32        return cnt;
33    }
34};