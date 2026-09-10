// Last updated: 9/10/2026, 5:23:28 PM
1
2class Solution {
3public:
4    vector<int> values;
5    int idx = 0;
6
7    void getValues(TreeNode* root) {
8        if (!root) return;
9
10        getValues(root->left);
11        values.push_back(root->val);
12        getValues(root->right);
13    }
14
15    void fixTree(TreeNode* root) {
16        if (!root) return;
17
18        fixTree(root->left);
19
20        root->val = values[idx++];
21
22        fixTree(root->right);
23    }
24
25    void recoverTree(TreeNode* root) {
26        
27        getValues(root);
28
29   
30        sort(values.begin(), values.end());
31
32       
33        fixTree(root);
34    }
35};
36
37