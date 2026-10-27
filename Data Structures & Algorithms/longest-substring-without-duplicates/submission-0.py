class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0 
        max_len = 0
        state_tracker = {}

        for right in range(len(s)): ### valid
            incoming = s[right]
            state_tracker[incoming] = state_tracker.get(incoming, 0) + 1
            ### invalid
            while (state_tracker[incoming] > 1):
                outgoing = s[left]
                state_tracker[outgoing] -= 1
                left += 1
            current_len = right - left + 1
            max_len = max(max_len, current_len)

        return max_len
