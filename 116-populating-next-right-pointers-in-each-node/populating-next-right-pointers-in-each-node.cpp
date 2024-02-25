/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelOrder(Node* root)
    {
        if(root==NULL) return;
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            vector<Node*> level;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                level.push_back(temp);
            }
            for(int i=0;i<level.size()-1;i++)
            {
                level[i]->next=level[i+1];
            }
        }
    }
    Node* connect(Node* root) {
        levelOrder(root);
        return root;
    }
};