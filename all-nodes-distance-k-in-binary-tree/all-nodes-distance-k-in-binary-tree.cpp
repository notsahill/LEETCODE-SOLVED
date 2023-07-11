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
    void inorder(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &par)
    {
        if(!root) return;
        if(root->left) par[root->left]=root;
        inorder(root->left,par);
        if(root->right) par[root->right]=root;
        inorder(root->right,par);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*> par;
        inorder(root,par);
        vector<int> ans;
        set<TreeNode*> s;
        queue<TreeNode*> q;
        q.push(target);
        s.insert(target);
        int lvl=0;
        while(q.size() and k>0)
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left and !s.count(node->left))
                {
                    q.push(node->left);
                    s.insert(node->left);
                }
                if(node->right and !s.count(node->right))
                {
                    q.push(node->right);
                    s.insert(node->right);
                }
                if(par[node]!=NULL and !s.count(par[node]))
                {
                    q.push(par[node]);
                    s.insert(par[node]);
                }
                // ans.push_back(node->val);
            }
            k--;
        }
        while(q.size())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};