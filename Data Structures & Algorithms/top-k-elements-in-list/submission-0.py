from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        result = []
        new_dict = dict(Counter(nums))
        sorted_data_desc = dict(sorted(new_dict.items(), key=lambda item: item[1], reverse=True))
        for i in range(k): 
            result.append(list(sorted_data_desc.keys())[i])
        
        return result