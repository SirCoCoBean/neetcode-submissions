from collections import Counter

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        # Check 3x3 boxes
        for r in range(0, 9, 3):
            for c in range(0, 9, 3):

                flat = []

                for row in board[r:r+3]:
                    for value in row[c:c+3]:
                        if value != ".":
                            flat.append(value)

                counts = Counter(flat)

                if counts and counts.most_common(1)[0][1] > 1:
                    return False

        # Check rows
        for row in board:

            nums = []

            for value in row:
                if value != ".":
                    nums.append(value)

            counts = Counter(nums)

            if counts and counts.most_common(1)[0][1] > 1:
                return False

        # Check columns
        for c in range(9):

            nums = []

            for r in range(9):
                value = board[r][c]

                if value != ".":
                    nums.append(value)

            counts = Counter(nums)

            if counts and counts.most_common(1)[0][1] > 1:
                return False

        return True