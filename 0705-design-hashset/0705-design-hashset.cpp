class MyHashSet {
public:
    vector<list<int>>m;
    int size;
    MyHashSet() {
        size=100;
        m.resize(100);
    }
    list<int>::iterator search(int key){
        int i=hash(key);
        return find(m[i].begin(),m[i].end(),key);
    }
    int hash(int key){
        return key%size;
    }
    bool contains(int key){
        int i=hash(key);
        return search(key)!=m[i].end();
    }
    void add(int key) {
        if(contains(key))return;
        int i=hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))return ;
        int i=hash(key);
        m[i].erase(search(key));
    }
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */