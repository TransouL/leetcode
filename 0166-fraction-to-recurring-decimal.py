class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator % denominator == 0:
            return str(numerator // denominator)
        quotient = str(numerator / denominator)
        integer_part = ""
        if 'e' in quotient:
            if quotient.startswith("-"):
                integer_part = '-0.'
            else:
                integer_part = '0.'
        else:
            integer_part = quotient[:quotient.index('.') + 1]
        # 负数在integer部分处理
        numerator, denominator = abs(numerator), abs(denominator)

        numerator = numerator % denominator
        remainder_map, multiple, = {numerator: 0}, 0
        while True:
            numerator *= 10
            multiple += 1
            curr_remainder = numerator % denominator
            # 有限小数
            if curr_remainder == 0:
                exact_division = str(numerator // denominator)
                return integer_part + "0" * (multiple - len(exact_division)) + exact_division
            if curr_remainder in remainder_map:
                fractional = str(numerator // denominator)
                tmp_len = len(fractional)
                recurring_start = remainder_map.get(curr_remainder)
                recurring_len = multiple - recurring_start
                before_recurring_str, recurring_str = "", ""
                if recurring_len <= tmp_len:
                    # before_recurring_str可能存在前导0
                    before_recurring_str = '0' * (multiple - tmp_len) + fractional[:tmp_len - recurring_len]
                    recurring_str = fractional[tmp_len - recurring_len:]
                else:
                    # recurring_str存在前导0的情况下，before_recurring_str也可能存在前导0
                    before_recurring_str = '0' * (multiple - recurring_len)
                    recurring_str = '0' * (recurring_len - tmp_len) + fractional
                return integer_part + before_recurring_str + '(' + recurring_str + ')'
            else:
                remainder_map[curr_remainder] = multiple


solution = Solution()
print(solution.fractionToDecimal(-1, -2147483648))  # "0.0000000004656612873077392578125"
print(solution.fractionToDecimal(1, 214748364))  # "0.00(000000465661289042462740251655654056577585848337359161441621040707904997124914069194026549138227660723878669455195477065427143370461252966751355553982241280310754777158628319049732085502639731402098131932683780538602845887105337854867197032523144157689601770377165713821223802198558308923834223016478952081795603341592860749337303449725)"
print(solution.fractionToDecimal(7, -12))  # "-0.58(3)"
print(solution.fractionToDecimal(22, 7))  # "3.(142857)"
print(solution.fractionToDecimal(1, 6))  # "0.1(6)"
print(solution.fractionToDecimal(1, 7))  # "0.(142857)"
print(solution.fractionToDecimal(1, 333))  # "0.(003)"
print(solution.fractionToDecimal(1, 90))  # "0.0(1)"
print(solution.fractionToDecimal(50, 8))  # "6.25"
print(solution.fractionToDecimal(1, 2))
print(solution.fractionToDecimal(2, 1))
print(solution.fractionToDecimal(2, 3))
print(solution.fractionToDecimal(4, 333))
print(solution.fractionToDecimal(1, 5))
