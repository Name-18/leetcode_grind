// Last updated: 8/17/2026, 8:09:51 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13    
14public:
15
16    set<int> st;
17
18    void traval(TreeNode* root){
19        if(root == nullptr){
20            return;
21        }
22
23        st.insert(root->val);
24        traval(root->left);
25        traval(root->right);
26    }
27    bool isUnivalTree(TreeNode* root) {
28        traval(root);
29        cout<<st.size();
30        return st.size()==1;
31    }
32};