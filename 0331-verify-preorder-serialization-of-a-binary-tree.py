class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        if preorder == '#':
            return True
        nums_count, empty_count = 0, 0
        nodes = preorder.split(',')
        if len(nodes) < 3:
            return False
        for index in range(len(nodes) - 2):
            if nodes[index] == '#':
                empty_count += 1
            else:
                nums_count += 1
            if nums_count < empty_count:
                return False
        return nums_count == empty_count + 1 and nodes[-2] == '#' and nodes[-1] == '#'
