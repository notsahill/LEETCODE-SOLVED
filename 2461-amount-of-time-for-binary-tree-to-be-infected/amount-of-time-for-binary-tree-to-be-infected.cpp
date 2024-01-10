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
    TreeNode* target;
    void populatePar(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par,int start)
    {
        if(!root) return;
        if(root->val==start) target=root;
        if(root->left) par[root->left]=root;
        if(root->right) par[root->right]=root;
        populatePar(root->left,par,start);
        populatePar(root->right,par,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> par;
        populatePar(root,par,start);
        par[root]=NULL;
        queue<pair<TreeNode*,int>> q;
        set<TreeNode*> vis;
        q.push({target,0});
        vis.insert(target);
        int ans=0;
        while(q.size())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr=q.front().first;
                int t=q.front().second;
                q.pop();
                if(curr->left and !vis.count(curr->left))
                {
                    vis.insert(curr->left);
                    q.push({curr->left,t+1});
                    ans=max(ans,t+1);
                }
                if(curr->right and !vis.count(curr->right))
                {
                    vis.insert(curr->right);
                    q.push({curr->right,t+1});
                    ans=max(ans,t+1);
                }
                if(par[curr]!=NULL and !vis.count(par[curr]))
                {
                    vis.insert(par[curr]);
                    q.push({par[curr],t+1});
                    ans=max(ans,t+1);
                }
                
            }
        }
        return ans;
    }
};