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
    bool h(TreeNode* p,TreeNode* q)
    {
        if(!p and !q) return 1;
        if(!p or !q) return 0;
        if(p->val!=q->val) return 0;
        bool x=h(p->left,q->right);
        bool y=h(p->right,q->left);
        return x&&y;
    }
    bool isSymmetric(TreeNode* root) {
        return h(root->left,root->right);
    }
};