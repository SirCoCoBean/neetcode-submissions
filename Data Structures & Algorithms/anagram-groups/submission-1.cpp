class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> answer;

        unordered_map<string, vector<string>> dict;

        for (const auto& word : strs) {

            string sorted_word = word;

            sort(sorted_word.begin(), sorted_word.end());

            if (dict.find(sorted_word) != dict.end()) {
                dict[sorted_word].push_back(word);
            }
            else {
                dict[sorted_word].push_back(word);
            }
        }

        for (const auto& pair : dict) {
            answer.push_back(pair.second);
        }

        return answer;
    }
};