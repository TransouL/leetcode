# from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        op_to_binary_fn = {
            '+': lambda a, b: a + b,
            '-': lambda a, b: a - b,
            '*': lambda a, b: a * b,
            '/': lambda a, b: int(a / b)
        }
        n = len(tokens)
        stack = [0] * ((n + 1) //2)
        index = -1
        for token in tokens:
            try:
                num = int(token)
                index +=1
                stack[index] = num
            except ValueError:
                index -= 1
                stack[index] = op_to_binary_fn[token](stack[index], stack[index + 1])
        return stack[0]


# solution = Solution()
# print(solution.evalRPN(["2", "1", "+", "3", "*"]))
# print(solution.evalRPN(["4", "13", "5", "/", "+"]))
# print(solution.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))
