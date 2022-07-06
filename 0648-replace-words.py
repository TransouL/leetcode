from typing import List


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary.sort()
        ans = []
        for word in sentence.split(" "):
            foundRoot = False
            for root in dictionary:
                if word.startswith(root):
                    ans.append(root)
                    foundRoot = True
                    break
            if not foundRoot:
                ans.append(word)
        return " ".join(ans)



solution = Solution()
print(solution.replaceWords(dictionary=["cat", "bat", "rat"], sentence="the cattle was rattled by the battery"))
print(solution.replaceWords(dictionary=["a", "b", "c"], sentence="aadsfasf absbs bbab cadsfafs"))
