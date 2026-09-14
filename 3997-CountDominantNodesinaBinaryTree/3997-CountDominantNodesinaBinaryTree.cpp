// Last updated: 9/14/2026, 12:34:12 PM
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
14int cnt = 0;
15  int func(TreeNode* root){
16
17
18  if(!root){
19    return -1;
20  }
21
22  int left =  func(root->left);
23  int right = func(root->right);
24  if(root->val >= max(left , right)){
25    cnt +=1;
26  }
27
28  return max({root->val,left , right});
29    }
30
31    int countDominantNodes(TreeNode* root) {
32        func(root);
33        return cnt;
34    }
35};