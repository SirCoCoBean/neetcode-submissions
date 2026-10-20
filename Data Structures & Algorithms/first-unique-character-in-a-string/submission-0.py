from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        count_char = Counter(s)

        if 1 in count_char.values():
            min_key = min(count_char, key=count_char.get)
            return s.index(min_key)
    
        else:
            return -1


        

        