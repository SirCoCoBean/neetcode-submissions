class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        ### use the pile min to max in a binary search to find the best k
        ### we want the min number k (so if k < h we return and stop)
        left = 1 
        right = max(piles)
        result = [] 

        while left <= right:
            mid = (right + left) // 2
            tracker = 0
            for pile in piles:
                counter = math.ceil(pile / mid)
                tracker += counter

            if tracker <= h:
                result.append(mid)
                right = mid - 1
            else:
                left = mid + 1
        
        return min(result)

                 
                
        
        
                
                

                
