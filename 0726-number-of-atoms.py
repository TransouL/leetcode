from collections import defaultdict


class Solution:
    def countOfAtoms(self, formula: str) -> str:
        cnts, multiply, muls, num, num_bits, atom = defaultdict(int), 1, [], 0, 0, ""
        for c in formula[::-1]:
            if c == ')':
                if num:
                    muls.append(num)
                    multiply *= num
                    num = num_bits = 0
                else:
                    muls.append(1)
            elif c == '(':
                multiply //= muls.pop()
            elif str.isdigit(c):
                num += int(c) * (10 ** num_bits)
                num_bits += 1
            elif str.islower(c):
                atom = c + atom
            else:
                atom = c + atom
                if num:
                    cnts[atom] += num * multiply
                else:
                    cnts[atom] += multiply
                atom = ""
                num = num_bits = 0

        return "".join(key if cnts[key] == 1 else key + str(cnts[key]) for key in sorted(cnts.keys()))


solution = Solution()
print(solution.countOfAtoms("H2O"))
print(solution.countOfAtoms("Mg(OH)2"))
print(solution.countOfAtoms("K4(ON(SO3)2)2"))
print(solution.countOfAtoms("Be32"))
