class MyHashSet {
private:
    static const int PRIME_SIZE = 10007;
    vector<list<int>> buckets;

    int hash(int key) const {
        return key % PRIME_SIZE;
    }

public:
    MyHashSet() : buckets(PRIME_SIZE) {}
    
    void add(int key) {
        int idx = hash(key);
        for (int k : buckets[idx]) {
            if (k == key) return;
        }
        buckets[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        buckets[idx].remove(key);
    }
    
    bool contains(int key) const {
        int idx = hash(key);
        for (int k : buckets[idx]) {
            if (k == key) return true;
        }
        return false;
    }
};