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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node=root;
        if(!root) return ans;
        stack<TreeNode*> s;
        while(1){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }else{
                if(!s.size()) break;
                TreeNode* curr=s.top();
                s.pop();
                ans.push_back(curr->val);
                node=curr->right;
            }
        }
        return ans;
    }
};