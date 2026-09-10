// Last updated: 9/10/2026, 12:24:11 PM
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
15    pair<int,int> func(TreeNode * root){
16
17        if(!root){
18            return {0,0};
19        }
20        pair<int,int> left = func(root->left);
21        pair<int,int> rght  =  func(root->right);
22        int num = left.first + rght.first + 1;
23        int sum = left.second +rght.second + root->val;
24         if((sum / num) == root->val ) cnt += 1;
25        return {num , sum}; 
26    }
27    int averageOfSubtree(TreeNode* root) {
28        
29        auto x = func(root);
30
31        cout<< x.first<< " " <<x.second;
32        cout<<endl;
33        return cnt;
34    }
35};