class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1revisions = version1.split(".")
        v2revisions = version2.split(".")
        v1len, v2len = len(v1revisions), len(v2revisions)
        for i in range(0, max(v1len, v2len)):
            rev1 = int(v1revisions[i]) if i < v1len else 0
            rev2 = int(v2revisions[i]) if i < v2len else 0
            if rev1 < rev2:
                return -1
            if rev1 > rev2:
                return 1
        return 0


solution = Solution()
print(solution.compareVersion("1.01", "1.001"))
print(solution.compareVersion("1.0", "1.0.0"))
print(solution.compareVersion("0.1", "1.1"))
print(solution.compareVersion("1.0.1", "1"))
print(solution.compareVersion("7.5.2.4", "7.5.3"))
