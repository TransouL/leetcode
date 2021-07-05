from typing import List
from collections import defaultdict


class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        foodItems = []
        tableOrders = defaultdict(lambda: defaultdict(int))
        for order in orders:
            tableOrders[order[1]][order[2]] += 1
            if order[2] not in foodItems:
                foodItems.append(order[2])
        foodItems.sort()
        ans = [["Table"] + foodItems]
        for tableNumberi, tableOrderDict in sorted(tableOrders.items(), key=lambda x: int(x[0])):
            tableOrderList = [tableNumberi]
            for foodItem in foodItems:
                tableOrderList.append(str(tableOrderDict[foodItem]))
            ans.append(tableOrderList)
        return ans


solution = Solution()
print(solution.displayTable(
    [["David", "3", "Ceviche"], ["Corina", "10", "Beef Burrito"], ["David", "3", "Fried Chicken"],
     ["Carla", "5", "Water"], ["Carla", "5", "Ceviche"], ["Rous", "3", "Ceviche"]]))
print(solution.displayTable(
    [["James", "12", "Fried Chicken"], ["Ratesh", "12", "Fried Chicken"], ["Amadeus", "12", "Fried Chicken"],
     ["Adam", "1", "Canadian Waffles"], ["Brianna", "1", "Canadian Waffles"]]))
print(solution.displayTable([["Laura", "2", "Bean Burrito"], ["Jhon", "2", "Beef Burrito"], ["Melissa", "2", "Soda"]]))
