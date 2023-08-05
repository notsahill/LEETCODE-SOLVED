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
    map<pair<int,int>,vector<TreeNode*> > mp;
    vector<TreeNode*> h(int start,int end)
    {
        vector<TreeNode*> ans;
        if(start>end) return {NULL};
        if(mp.find({start,end})!=mp.end()) return mp[{start,end}];
        if(start==end)
        {
            TreeNode* root=new TreeNode(start);
            return {root};
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> LEFT=h(start,i-1);
            vector<TreeNode*> RIGHT=h(i+1,end);
            for(auto L:LEFT)
            {
                for(auto R:RIGHT)
                {
                    TreeNode* root= new TreeNode(i);
                    root->left=L;
                    root->right=R;
                    ans.push_back(root);
                }
            }
        }
        return mp[{start,end}]=ans;

    }
    vector<TreeNode*> generateTrees(int n) {
        return h(1,n);
    }
};