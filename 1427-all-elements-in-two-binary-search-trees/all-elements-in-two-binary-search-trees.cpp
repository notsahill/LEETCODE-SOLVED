/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void traverse(TreeNode* root)
    {
        if(!root) return;
        ans.push_back(root->val);
        if(root->left) traverse(root->left);
        if(root->right) traverse(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1) traverse(root1);
        if(root2) traverse(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};