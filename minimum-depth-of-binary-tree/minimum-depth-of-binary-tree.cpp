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
    int minDepth(TreeNode* root) 
    {
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        int x=INT_MAX,y=INT_MAX;
        if(root->left) x=(minDepth(root->left));
        if(root->right) y=minDepth(root->right);
        return min(x,y)+1;
    }
};