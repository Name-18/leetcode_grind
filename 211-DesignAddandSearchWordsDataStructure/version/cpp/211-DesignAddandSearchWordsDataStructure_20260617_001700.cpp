// Last updated: 6/17/2026, 12:17:00 AM
1class WordDictionary {
2public:
3    struct tre{ 
4    unordered_map<char, tre*> children;
5  bool eow;
6  tre(){
7  
8    eow=false;
9  }
10  };
11  tre *root = nullptr;
12  bool  dfs(tre* curr, string &s , int i){
13        if(curr==nullptr) return false;
14          if(i==s.size()) return curr->eow;
15         
16          if(s[i]!='.'){
17            if(curr->children.find(s[i])==curr->children.end()){
18                return false;
19            }
20            
21               curr= curr->children[s[i]];
22              
23               return dfs(curr,s,i+1);
24
25            
26          }
27          bool res = false;
28           
29           for(auto it:curr->children){
30           res |=  (dfs(it.second,s,i+1));
31             
32           }
33return res;
34  }
35    WordDictionary() {
36        root = new tre();
37    }
38    
39    void addWord(string word) {
40        tre* curr = root;
41        for(auto it:word){
42            if(curr->children[it]==nullptr){
43                curr->children[it] = new tre();
44            }
45            curr = curr->children[it] ;
46        }
47         curr->eow = true;
48    }
49    
50    bool search(string word) {
51          tre* curr = root;
52             
53             return dfs(curr,word,0);
54    }
55};
56
57/**
58 * Your WordDictionary object will be instantiated and called as such:
59 * WordDictionary* obj = new WordDictionary();
60 * obj->addWord(word);
61 * bool param_2 = obj->search(word);
62 */