from typing import List


# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        employee_map = {employee.id: employee for employee in employees}
        answer = 0

        def dfs(employee_id: int) -> None:
            nonlocal answer
            employee = employee_map[employee_id]
            answer += employee.importance
            for subordinate_id in employee_map[employee_id].subordinates:
                dfs(subordinate_id)

        dfs(id)
        return answer


solution = Solution()
employee1 = Employee(1, 5, [2, 3])
employee2 = Employee(2, 3, [])
employee3 = Employee(3, 3, [])
print(solution.getImportance([employee1, employee2, employee3], 1))
