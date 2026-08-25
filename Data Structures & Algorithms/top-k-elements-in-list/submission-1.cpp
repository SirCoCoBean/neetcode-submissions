class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> dict;
        vector<int> result;

        // Count frequency
        for (const auto& num : nums) {
            dict[num]++;
        }

        // Convert map into vector of pairs
        vector<pair<int, int>> vec(dict.begin(), dict.end());

        // Sort based on frequency
        sort(vec.begin(), vec.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

        // Grab first k numbers
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }

        return result;
    }
};