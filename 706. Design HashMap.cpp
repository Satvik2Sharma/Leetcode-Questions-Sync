class MyHashMap {
private:
    static const int SIZE = 1009;
    vector<vector<pair<int, int>>> buckets;
    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        buckets.resize(SIZE);
    }

    void put(int key, int value) {
        int index = hash(key);
        for (auto &p : buckets[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[index].push_back({key, value});
    }
    int get(int key) {
        int index = hash(key);
        for (auto &p : buckets[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        for (int i = 0; i < buckets[index].size(); i++) {
            if (buckets[index][i].first == key) {
                buckets[index].erase(buckets[index].begin() + i);
                return;
            }
        }
    }
};
