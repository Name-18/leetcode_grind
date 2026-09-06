// Last updated: 9/6/2026, 8:00:12 PM
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
14int res;
15  void  solve(TreeNode* root,int maxi,int mini){
16    if(!root) return;
17     res = max(res,abs(root->val-maxi));
18     res = max(res,abs(root->val-mini));
19        maxi = max(maxi,root->val);
20        mini = min(mini,root->val);
21
22        solve(root->left,maxi,mini);
23        solve(root->right,maxi,mini);
24           
25
26    }
27    int maxAncestorDiff(TreeNode* root) {
28        res = INT_MIN;
29        solve(root,root->val,root->val);
30
31        return res;
32    }
33};