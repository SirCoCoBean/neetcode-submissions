from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        new_s = dict(Counter(s))
        new_t = dict(Counter(t))
        if new_s == new_t:
            return True
        else:
            return False