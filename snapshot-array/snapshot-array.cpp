class SnapshotArray {
private:
    int snap_id=0;
    vector<map<int,int>> m;
public:
    SnapshotArray(int length) 
    {
        m.resize(length);
        for(int i=0;i<length;i++)
        {
            m[i][0]=0;
        }
    }
    
    void set(int index, int val) 
    {
        m[index][snap_id]=val;
    }
    
    int snap() 
    {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) 
    {
        if(m[index].find(snap_id) == m[index].end())
        {
            auto it = --m[index].lower_bound(snap_id);
            return it->second;
        }
        return m[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */