
class MyHashSet {
private:
    int mp[1000001];
public:
    MyHashSet() 
    {
        for(int i=0;i<=100000;i++)
        {
            mp[i]=0;
        }
    }
    
    void add(int key) 
    {
        mp[key]=1;
    }
    
    void remove(int key) {
        mp[key]=0;
    }
    
    bool contains(int key) {
        if(mp[key]==1) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */