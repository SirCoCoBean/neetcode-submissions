class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> first;
        unordered_map<char, int> second;

        for (char c: s) {
            first[c]++; 
        }

        for (char d: t) {
            second[d]++;
        }

        if (first == second) {
            return true;
        }

        else {
            return false;
        }
    }
};
