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
    void removeLeafs(TreeNode* &root, int target)
    {
        if(!root) return;
        removeLeafs(root->left,target);
        removeLeafs(root->right,target);
        if(!root->left and !root->right and root->val==target) root=NULL;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        removeLeafs(root,target);
        return root;
    }
};