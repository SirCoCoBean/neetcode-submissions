class LRUCache {
    // have a dict for finding val to key
    // use a list to keep track of cache

    int cap; 
    list<pair<int,int>> cache;  // index -- val 
    unordered_map<int, list<pair<int,int>>::iterator> lookup; // val -- index
public:
    LRUCache(int capacity) { // init cache size
        cap = capacity;
    }
    
    int get(int key) { // return value corresponding to key, else return -1
        if (lookup.find(key) == lookup.end()) {
        return -1;
        }

        auto it = lookup[key];
        int value = it->second;

        cache.erase(it);
        cache.push_back({key, value});
        lookup[key] = prev(cache.end());

        return value;
    }
    
    void put(int key, int value) { // update val of key, if key exist, else add the key
    // -value, if added key is too full then remove least recently used key

    //  lookup[1] = prev(cache.end());

        if (lookup.find(key) != lookup.end()) {
            // Existing key: remove old position
            cache.erase(lookup[key]);
        }

        // Add/update as MRU
        cache.push_back({key, value});
        lookup[key] = prev(cache.end());

        // Too many items: remove LRU
        if (cache.size() > cap) {
            int oldKey = cache.front().first;

            lookup.erase(oldKey);
            cache.pop_front();
        }
    
    }
};
