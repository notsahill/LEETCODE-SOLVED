class Node{
    public:
    char ch;
    Node* links[26];
    bool isEnd;
    public:
    Node(char x)
    {
        ch=x;
        for(int i=0;i<26;i++)
        {
            links[i]=NULL;
        }
        isEnd=false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root= new Node('$');
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            
            if(curr->links[c-'a']==NULL)
            {
                Node* temp=new Node(c);
                curr->links[c-'a']=temp;
            }
            curr=curr->links[c-'a'];
            if(i==word.size()-1)
            {
                curr->isEnd=true;
            }
        }
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            if(curr->links[c-'a']==NULL) return false;
            curr=curr->links[c-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++)
        {
            char c=prefix[i];
            if(curr->links[c-'a']==NULL) return false;
            curr=curr->links[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */