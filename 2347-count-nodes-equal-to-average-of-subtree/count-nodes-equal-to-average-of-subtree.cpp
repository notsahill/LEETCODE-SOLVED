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
    void traverse(TreeNode* root,unordered_map<TreeNode*,pair<int,int>> &mp)
    {
        if(!root) return;
        mp[root].first+=root->val;
        mp[root].second++;
        if(root->left)
        {
            traverse(root->left,mp);
            mp[root].first+=mp[root->left].first;
            mp[root].second+=mp[root->left].second;
        }
        if(root->right)
        {
            traverse(root->right,mp);
            mp[root].first+=mp[root->right].first;
            mp[root].second+=mp[root->right].second;
        }
    }

    int averageOfSubtree(TreeNode* root) {
        
        unordered_map<TreeNode*,pair<int,int>> mp; //{node,{sum,cnt}}
        traverse(root,mp);//store sum of subtree of each node and its size
        int cnt=0;
        for(auto a:mp)
        {
            if(a.second.first/a.second.second==a.first->val) cnt++;
        }
        return cnt;
    }
};