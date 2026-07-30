from itertools import cycle
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer =[]
        
        for i in range(n):
            product = 1
            for j in range(1, n):
                cyclic_index = (i + j) % n
                product *= nums[cyclic_index]
            answer.append(product)
                
            
            

        return answer
            
        