// Last updated: 6/16/2026, 10:27:12 PM
1class Trie {
2public:
3  struct tre{
4  tre* children[26];
5  bool eow;
6  tre(){
7    for(int i=0;i<26;i++){
8        children[i]=nullptr;
9    }
10    eow=false;
11  }
12  };
13  tre* root = nullptr;
14    Trie() {
15       root = new tre();
16
17    }
18    
19    void insert(string word) {
20        tre* curr = root;
21        for(int i=0;i<word.size();i++){
22            if(curr->children[word[i]-'a']==nullptr){
23                  curr->children[word[i]-'a'] = new tre();
24            }
25             curr = curr->children[word[i]-'a'];
26            
27        }
28        curr->eow= true;
29    }
30    
31    bool search(string word) {
32        tre* curr = root;
33        for(int i=0;i<word.size();i++){
34           
35            if(curr->children[word[i]-'a']==nullptr){
36               return false;
37            }
38               curr = curr->children[word[i]-'a'];
39            
40         
41        }
42        return curr->eow;
43    }
44    
45    bool startsWith(string word) {
46          tre* curr = root;
47        for(int i=0;i<word.size();i++){
48           
49            if(curr->children[word[i]-'a']==nullptr){
50               return false;
51            }
52               curr = curr->children[word[i]-'a'];
53            
54         
55        }
56        return true;
57    }
58};
59
60/**
61 * Your Trie object will be instantiated and called as such:
62 * Trie* obj = new Trie();
63 * obj->insert(word);
64 * bool param_2 = obj->search(word);
65 * bool param_3 = obj->startsWith(prefix);
66 */