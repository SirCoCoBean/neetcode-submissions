class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0 

        clean_string = ""
        for ch in s:
            if ch.isalnum():
                clean_string += ch.lower()
        right = len(clean_string) - 1
        while left < right:
            if clean_string[left] == clean_string[right]:
                left+=1 
                right-=1
            else:
                return False
        
        return True

    



        