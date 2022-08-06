from typing import List


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words.sort(key=lambda word:len(word), reverse=True)  # words.sort(key=len, reverse=True)
        ans, parents = [], set()
        for word in words:
            isSub = False
            for parent in parents:
                if word in parent:
                    isSub = True
                    break
            if isSub:
                ans.append(word)
            else:
                parents.add(word)
        return ans


solution = Solution()
print(solution.stringMatching(["mass", "as", "hero", "superhero"]))
print(solution.stringMatching(["leetcode", "et", "code"]))
print(solution.stringMatching(["blue", "green", "bu"]))
