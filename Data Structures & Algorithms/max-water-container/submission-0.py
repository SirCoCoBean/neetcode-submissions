class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0 
        right = len(heights) -1
        best_water = 0

        while left < right:

            height = min(heights[left], heights[right])
            width = right - left
            water = width * height
            
            best_water = max(best_water, water)

            if (heights[left] < heights[right]):
                left +=1
            
            else:
                right -=1

            

            
        
        return best_water