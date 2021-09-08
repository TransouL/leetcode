from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        curr, n = 0, len(words)
        while True:
            lineFirst = curr
            lineWordsLength = 0
            while curr < n and lineWordsLength + len(words[curr]) + curr - lineFirst <= maxWidth:
                lineWordsLength += len(words[curr])
                curr += 1

            if curr == n:
                line = " ".join(words[lineFirst:])
                ans.append(line + " " * (maxWidth - len(line)))
                break

            numWords = curr - lineFirst
            numSpaces = maxWidth - lineWordsLength

            if numWords == 1:
                ans.append(words[lineFirst] + " " * numSpaces)
                continue

            avgSpaces = numSpaces // (numWords - 1)
            extraSpaces = numSpaces % (numWords - 1)
            s1 = (" " * (avgSpaces + 1)).join(words[lineFirst:lineFirst + extraSpaces + 1])
            s2 = (" " * avgSpaces).join(words[lineFirst + extraSpaces + 1:curr])
            ans.append(s1 + " " * avgSpaces + s2)
        return ans


solution = Solution()
print(solution.fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16))
print(solution.fullJustify(["What", "must", "be", "acknowledgment", "shall", "be"], 16))
print(solution.fullJustify(["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                            "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"], 20))
