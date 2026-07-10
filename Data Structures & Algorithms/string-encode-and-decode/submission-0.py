from typing import List
class Solution:

    def encode(self, strs: List[str]) -> str:
        holder = []

        for word in strs:
            piece = str(len(word)) + "|" + word
            holder.append(piece)

        encoded = "".join(holder)

        return encoded

    def decode(self, s: str) -> List[str]:

        decoded = []
        i = 0

        while i < len(s):
            separator = s.find("|", i)

            length = int(s[i:separator])

            word_start = separator + 1
            word_end = word_start + length

            word = s[word_start:word_end]
            decoded.append(word)

            i = word_end

        return decoded

