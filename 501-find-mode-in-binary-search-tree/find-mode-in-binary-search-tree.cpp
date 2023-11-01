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
    int mx=0;
    map<int,int> mp;
    void dfs(TreeNode* root)
    {
        if(!root) return;
        mp[root->val]++;
        mx=max(mx,mp[root->val]);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        for(auto a:mp)
        {
            if(a.second==mx) ans.push_back(a.first);
        }
        return ans;
    }
};