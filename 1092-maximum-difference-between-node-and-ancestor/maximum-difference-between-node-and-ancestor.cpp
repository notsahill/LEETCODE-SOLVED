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
    long ans=0;
    void dfs(TreeNode* r,int mn,int mx)
    {
        if(r==NULL) return;

        mn=min(mn,r->val);
        mx=max(mx,r->val);
        
        long d1= abs(mn- r->val);
        long d2=abs(mx-r->val);
        long diff= max(d1,d2);
       
        ans=max(ans,diff);
        dfs(r->left,mn,mx);
        dfs(r->right,mn,mx);
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        dfs(root,INT_MAX,INT_MIN);
        return (int)ans;
    }
};