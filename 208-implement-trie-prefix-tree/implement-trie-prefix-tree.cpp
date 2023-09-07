class Node
{
    public:
    char ch;
    Node* links[26];
    bool isEnd;
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
    Trie() 
    {
        root=new Node('#');
    }
    
    void insert(string word) 
    {
        Node* curr=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(curr->links[ch-'a']==NULL) curr->links[ch-'a']=new Node(ch);
            if(i==word.size()-1) curr->links[ch-'a']->isEnd=true;
            curr=curr->links[ch-'a'];
        }
    }
    
    bool search(string word) 
    {
        Node* curr=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(curr->links[ch-'a']==NULL) return false;
            curr=curr->links[ch-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) 
    {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++)
        {
            char ch=prefix[i];
            if(curr->links[ch-'a']==NULL) return false;
            curr=curr->links[ch-'a'];
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