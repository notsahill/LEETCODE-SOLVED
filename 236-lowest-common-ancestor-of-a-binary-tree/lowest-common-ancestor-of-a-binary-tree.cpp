/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNodePath(TreeNode* root,TreeNode* p,vector<TreeNode*> &p1){
        if(!root) return false;
        p1.push_back(root);
        if(root==p) return true;
        if(rootToNodePath(root->left,p,p1) || rootToNodePath(root->right,p,p1)) return true;
        p1.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1,p2;
        rootToNodePath(root,p,p1);
        rootToNodePath(root,q,p2);
        set<TreeNode*> st;
        for(int i=p1.size()-1;i>=0;i--){
            st.insert(p1[i]);
        }
        for(int i=p2.size()-1;i>=0;i--){
            if(st.count(p2[i])) return p2[i];
        }
        return NULL;
    }
};