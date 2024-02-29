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
    bool checkOddAndIncreasing(vector<int> &lvl){
        if(lvl[0]%2==0) return false;
        for(int i=1;i<lvl.size();i++){
            if(lvl[i]%2==0 or(lvl[i]<=lvl[i-1])) return false;
        }
        return true;
    }
    bool checkEvenAndDecreasing(vector<int> &lvl){
        if(lvl[0]%2==1) return false;
        for(int i=1;i<lvl.size();i++){
            if(lvl[i]%2==1 or(lvl[i]>=lvl[i-1])) return false;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            vector<int> lvl;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2==0){
                if(checkOddAndIncreasing(lvl)==0) return false;
            }
            else if(level%2==1){
                if(checkEvenAndDecreasing(lvl)==0) return false;
            }
            level++;
        }
        return true;
    }
};