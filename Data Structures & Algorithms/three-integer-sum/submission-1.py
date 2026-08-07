class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        answer = []

        for i in range(len(nums)-2):
            if (i > 0 ) and nums[i] == nums[i-1]: ## handles duplicate for our pivot
                continue
            
            left = i + 1
            right = len(nums) - 1

            while left < right:
                current = nums[i] + nums[left] + nums[right]

                if current == 0:
                    answer.append([nums[i], nums[left], nums[right]])
                    right -= 1
                    left += 1
                ### handle duplicate for left and right
                    
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
                
                elif current > 0:
                    right -= 1
                
                else:
                    left += 1
        
        return answer