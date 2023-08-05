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
    vector<TreeNode*> h(int s,int e)
    {
        vector<TreeNode*> ans;
        if(s>e) return {NULL};
        if(s==e)
        {
            TreeNode* root=new TreeNode(s);
            return {root};
        }
        for(int i=s;i<=e;i++)
        {
            vector<TreeNode*> LEFT=h(s,i-1);
            vector<TreeNode*> RIGHT=h(i+1,e);
            for(auto L:LEFT)
            {
                for(auto R:RIGHT)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=L;
                    root->right=R;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return h(1,n);
    }
};