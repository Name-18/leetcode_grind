// Last updated: 9/6/2026, 7:59:41 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    int mx = 0;
16
17    int func(TreeNode* root) {
18
19        if (root == nullptr)
20            return -1;
21
22        int left = func(root->left);
23        int right = func(root->right);
24
25        if (left == -1 and right == -1)
26            return root->val;
27
28        if (left == -1) {
29            mx = max(mx, abs(root->val - right));
30            return min(root->val, right);
31        }
32
33        if (right == -1) {
34            mx = max(mx, abs(root->val - left));
35            return min(root->val, left);
36        }
37        mx = max(mx, abs(root->val - right));
38        mx = max(mx, abs(root->val - left));
39        return min({root->val, left, right});
40    }
41    int func1(TreeNode* root) {
42
43        if (root == nullptr)
44            return -1;
45
46        int left = func1(root->left);
47        int right = func1(root->right);
48
49        if (left == -1 and right == -1)
50            return root->val;
51
52        if (left == -1) {
53            mx = max(mx, abs(root->val - right));
54            return max(root->val, right);
55        }
56
57        if (right == -1) {
58            mx = max(mx, abs(root->val - left));
59            return max(root->val, left);
60        }
61        mx = max(mx, abs(root->val - right));
62        mx = max(mx, abs(root->val - left));
63        return max({root->val, left, right});
64    }
65    int maxAncestorDiff(TreeNode* root) {
66        func(root);
67        func1(root);
68        return mx;
69    }
70};