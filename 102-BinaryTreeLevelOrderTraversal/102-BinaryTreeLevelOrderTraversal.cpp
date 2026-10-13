// Last updated: 10/14/2026, 12:09:14 AM
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
13public:
14vector<vector<int>> vec;
15
16  void func(TreeNode* root){
17      if(!root) return;
18      queue<TreeNode*> q;
19      q.push(root);
20
21      while(!q.empty()){
22           vector<int> tmp;
23           int n =q.size();
24        for(int i=0;i<n;i++){
25            auto it = q.front();
26            q.pop();
27            tmp.push_back(it->val);
28            if(it->left) q.push(it->left);
29            if(it->right) q.push(it->right);
30        }
31        vec.push_back(tmp);
32      }
33  }
34    vector<vector<int>> levelOrder(TreeNode* root) {
35        func(root);
36
37        return vec;
38    }
39};