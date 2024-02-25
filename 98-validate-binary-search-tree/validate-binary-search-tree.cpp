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
    bool isValid(TreeNode* root,long long l,long long u)
    {
        if(!root) return true;
        if(root->val>=u) return false;
        if(root->val<=l) return false;
        bool x=isValid(root->left,l,root->val);
        bool y=isValid(root->right,root->val,u);
        return x&&y;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};