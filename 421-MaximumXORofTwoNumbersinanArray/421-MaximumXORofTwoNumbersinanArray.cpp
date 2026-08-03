// Last updated: 8/3/2026, 8:30:30 PM
1struct node {
2    node* left;
3    node* right;
4};
5node* getnode() {
6    node* x = new node();
7    x->left = nullptr;
8    x->right = nullptr;
9    return x;
10}
11
12void insert(int num, node* root) {
13
14    for (int i = 31; i >= 0; i--) {
15
16        int number = num & (1 << i);
17
18        if (number == 0) {
19
20            if (root->left == nullptr) {
21                root->left = getnode();
22            }
23            root = root->left;
24        } else {
25            if (root->right == nullptr) {
26                root->right = getnode();
27            }
28            root = root->right;
29        }
30    }
31}
32
33int maker(int num , node* root){
34    int xr = 0;
35      for (int i = 31; i >= 0; i--) {
36
37       int number = (num >> i) & 1;
38
39        if (number == 1) {
40
41            if (root->left == nullptr) {
42          
43                root = root->right;
44            }else{
45               
46            root = root->left;
47            xr+= (1<<i);
48           
49            }
50        } else {
51            if (root->right == nullptr) {
52             
53                 root = root->left;
54            }else{
55             
56            root = root->right;
57           xr+= (1<<i);
58            }
59        }
60    
61    }
62 
63return xr;
64}
65
66class Solution {
67public:
68    int findMaximumXOR(vector<int>& nums) {
69        node *root = getnode();
70          for(auto it: nums){
71            insert(it,root);
72          }
73          int ans = 0;
74
75          for(auto it : nums){
76              node *crwl = root;
77              ans  = max(ans ,  maker(it , crwl));
78          }
79          return ans;
80    }
81};