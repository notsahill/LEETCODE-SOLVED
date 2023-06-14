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
    void dfs(TreeNode* r,vector<int> &lo)
    {
        if(!r) return;
        dfs(r->left,lo);
        lo.push_back(r->val);
        dfs(r->right,lo);
    }
    int minDiffInBST(TreeNode* root) 
    {
        vector<int> lo;
        dfs(root,lo);
        int mn=(lo[1]-lo[0]);
        for(int i=1;i<lo.size();i++)
        {
            mn=min(mn,(lo[i]-lo[i-1]));
        }
        return mn;
    }
};