from typing import List


class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        def check(limit: int) -> bool:
            def backtrack(finished_jobs: int) -> bool:
                if finished_jobs >= len(jobs):
                    return True
                curr = jobs[finished_jobs]
                for j in range(k):
                    if workloads[j] + curr <= limit:
                        workloads[j] += curr
                        if backtrack(finished_jobs + 1):
                            return True
                        workloads[j] -= curr
                    if workloads[j] == 0 or workloads[j] + curr == limit:
                        break
                return False

            workloads = [0] * k
            return backtrack(0)

        jobs.sort(reverse=True)
        l, r = jobs[0], sum(jobs)
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l


solution = Solution()
print(solution.minimumTimeRequired([3, 2, 3], 3))
print(solution.minimumTimeRequired([1, 2, 4, 7, 8], 2))
print(solution.minimumTimeRequired([254, 256, 256, 254, 251, 256, 254, 253, 255, 251, 251, 255], 10))
