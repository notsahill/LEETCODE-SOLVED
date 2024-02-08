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
    long long ans=0;
    void h(TreeNode* root,long long t){
        if(!root) return;
        if(root->val==t) ans++;
        h(root->left,t-root->val);
        h(root->right,t-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        h(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return (int)ans;
    }
};