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
    private:
     vector<int> ans1;
     vector<int> ans2;
public:
    void preorder(TreeNode* r,vector<int> &a)
{
    if(r==NULL) return;
    if(r->left==NULL&&r->right==NULL) a.push_back(r->val);
    preorder(r->left,a);
    preorder(r->right,a);
}
    bool leafSimilar(TreeNode* r1, TreeNode* r2) 
    {
        vector<int> v1,v2;
        preorder(r1,v1);
        preorder(r2,v2);

        if(v1==v2) return true;
        return false;
    }
};