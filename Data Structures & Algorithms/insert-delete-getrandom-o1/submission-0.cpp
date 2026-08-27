class RandomizedSet {
    unordered_map<int, int> hash;
    vector<int> dist;
    mt19937 gen;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.find(val) == hash.end()) {
            hash[val] = dist.size();
            dist.push_back(val);
            return true;
        }
        return false;
        
    }
    
    bool remove(int val) {
        if(hash.find(val) != hash.end()) {
            int index = hash[val];
            int last_val = dist.back();
            dist[index] = last_val;
            hash[last_val] = index;
            dist.pop_back();
            hash.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        uniform_int_distribution<int> randomIndex(0, dist.size() - 1);

        int index = randomIndex(gen);

    return dist[index];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */