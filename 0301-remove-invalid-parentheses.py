from typing import List


class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        n, ans, str_list = len(s), set(), []

        def dfs(step: int, left_count: int, ch_count: int, left_deleted: bool, right_deleted) -> None:
            if step == n:
                if left_count == 0:
                    ans.add("".join(str_list))
                return
            if s[step] == ')':
                if left_count > 0:
                    str_list.append(')')
                    dfs(step + 1, left_count - 1, ch_count + 1, left_deleted, right_deleted if left_count > 1 else False)
                    del str_list[-1]
                if not left_deleted:
                    if left_count > 0:
                        dfs(step + 1, left_count, ch_count, left_deleted, True)
                    else:
                        dfs(step + 1, left_count, ch_count, left_deleted, right_deleted)
            elif s[step] == '(':
                str_list.append('(')
                dfs(step + 1, left_count + 1, ch_count + 1, left_deleted, right_deleted)
                del str_list[-1]
                if not right_deleted:
                    dfs(step + 1, left_count, ch_count, True, right_deleted)
            else:
                str_list.append(s[step])
                dfs(step + 1, left_count, ch_count + 1, left_deleted, right_deleted)
                del str_list[-1]

        dfs(0, 0, 0, False, False)
        return list(ans)


solution = Solution()
print(solution.removeInvalidParentheses("()())()"))
print(solution.removeInvalidParentheses("(a)())()"))
print(solution.removeInvalidParentheses(")("))
print(solution.removeInvalidParentheses(")(()c))("))  # ["((c))","(()c)"]
print(solution.removeInvalidParentheses("())v)(()(((((())"))  # ["(v)()(())","(v)(()())","()v()(())","()v(()())"]
