class MyHashSet {
private:
    static const int SIZE = 1009;
    vector<list<int>> buckets;
    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int index = hash(key);
        for (int x : buckets[index]) {
            if (x == key)
                return;
        }
        buckets[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);

        buckets[index].remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        for (int x : buckets[index]) {
            if (x == key)
                return true;
        }
        return false;
    }
};
