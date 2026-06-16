// Last updated: 6/16/2026, 11:32:04 PM
// the solution uses trie to keep dictionary elements
1class Solution {
2public:
3    struct tre{ tre* children[26];
4  bool eow;
5  tre(){
6    for(int i=0;i<26;i++){
7        children[i]=nullptr;
8    }
9    eow=false;
10  }
11  };
12  tre *root = nullptr;
13        void insert(string word) {
14        tre* curr = root;
15        for(int i=0;i<word.size();i++){
16            if(curr->children[word[i]-'a']==nullptr){
17                  curr->children[word[i]-'a'] = new tre();
18            }
19             curr = curr->children[word[i]-'a'];
20            
21        }
22        curr->eow= true;
23    }
24    
25    bool search(string word) {
26        tre* curr = root;
27        for(int i=0;i<word.size();i++){
28           
29            if(curr->children[word[i]-'a']==nullptr){
30               return false;
31            }
32               curr = curr->children[word[i]-'a'];
33            
34         
35        }
36        return curr->eow;
37    } 
38    vector<vector<string>> ans;
39    void func(int st ,string s,vector<string> &str){
40        if(st>=s.size()){
41            
42            ans.push_back(str);
43            return ;
44        }
45           string w ="";
46        for(int j=st;j<s.size();j++){
47             w+=s[j];
48             if(search(w)){
49                    str.push_back(w);
50                    func(j+1 ,s , str);
51                    str.pop_back();
52             }
53        }
54    }
55    vector<string> wordBreak(string s, vector<string>& wordDict) {
56         
57         root = new tre;
58
59         for(auto it:wordDict){
60            insert(it);
61         }
62vector<string> v;
63         func(0,s,v);
64           vector<string>f;
65           for(auto ut:ans){
66            string w="";
67            for(auto it:ut){
68               w+=it;
69               w+=" ";
70            }
71            w.pop_back();
72            f.push_back(w);
73           }
74         return f;
75
76    }
77};