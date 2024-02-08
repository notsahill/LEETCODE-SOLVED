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
    vector<vector<int>> ans;
    void h(TreeNode* root,vector<int> &temp,int t){
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            int sum=0;
            for(auto a:temp) sum+=a;
            if(sum==t) ans.push_back(temp);
        }
        h(root->left,temp,t),h(root->right,temp,t);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        h(root,temp,targetSum);
        return ans;
    }
};