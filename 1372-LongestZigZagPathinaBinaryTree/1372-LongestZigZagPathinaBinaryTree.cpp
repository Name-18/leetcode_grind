// Last updated: 7/6/2026, 6:11:11 PM
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
14  int ans;
15    pair<int,int> func(TreeNode* root){
16         if(root==nullptr) return {-1,-1};
17          
18        
19        pair<int,int> lft = func(root->left);
20        pair<int,int>  rght = func(root->right);
21             ans = max({ans,1+ lft.second, 1+ rght.first });
22              return  make_pair(1 + lft.second, 1+ rght.first );
23           
24         
25        }
26
27    
28    int longestZigZag(TreeNode* root) {
29        this->ans =0;
30        func(root);
31        return ans;
32    }
33};