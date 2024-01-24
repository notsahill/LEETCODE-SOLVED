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
    int cnt=0;
    bool check(vector<int> &cnt){
        int c=0;
        for(int i=0;i<=9;i++){
            if(cnt[i]%2==1) c++;
        }
        return c<=1;
    }
    void h(TreeNode* root,vector<int> &temp){
        if(root==NULL) return; 
        temp[root->val]++;
        if(root->left==NULL && root->right==NULL){
            if(check(temp)) cnt++;
        }
        if(root->left) h(root->left,temp);
        if(root->right) h(root->right,temp);
        temp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10,0);
        h(root,temp);
        return cnt;
    }
};