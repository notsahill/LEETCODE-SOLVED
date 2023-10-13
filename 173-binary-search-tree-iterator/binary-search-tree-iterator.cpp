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
class BSTIterator {
public:
    void inorder(TreeNode* root,vector<pair<TreeNode*,int>> &temp)
    {
        if(!root) return ;
        if(root->left) inorder(root->left,temp);
        temp.push_back({root,root->val});
        if(root->right) inorder(root->right,temp);
    }
    int c=0;
    static bool cmp(pair<TreeNode*,int> &a,pair<TreeNode*,int> &b)
    {
        return a.second<b.second;
    }
    vector<pair<TreeNode*,int>> temp;
    BSTIterator(TreeNode* root) {
        inorder(root,temp);
        sort(temp.begin(),temp.end(),cmp);
    }
    
    int next() {
        int val=temp[c].second;
        c++;
        return val;
    }
    
    bool hasNext() {
        return c<temp.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */