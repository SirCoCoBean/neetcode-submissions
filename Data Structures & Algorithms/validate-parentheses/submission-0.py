class Solution:
    def isValid(self, s: str) -> bool:
        holder = []

        matching = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

        for char in s:
            if char in matching:
                if len(holder) == 0 or holder[-1] != matching[char]:
                    return False

                holder.pop()
            else:
                holder.append(char)

        return len(holder) == 0