from typing import List


class TreeNode:
    def __init__(self, name):
        self.name = name
        self.isDeath = False
        self.children = []


class ThroneInheritance:
    def __init__(self, kingName: str):
        self.king = TreeNode(kingName)
        self.mapping = {kingName: self.king}

    def birth(self, parentName: str, childName: str) -> None:
        self.mapping[childName] = TreeNode(childName)
        self.mapping[parentName].children.append(self.mapping[childName])

    def death(self, name: str) -> None:
        self.mapping[name].isDeath = True

    def getInheritanceOrder(self) -> List[str]:
        def preorder(root: TreeNode) -> None:
            if not root.isDeath:
                ans.append(root.name)
            for child in root.children:
                preorder(child)

        ans = []
        preorder(self.king)
        return ans


# Your ThroneInheritance object will be instantiated and called as such:
t = ThroneInheritance("king")  # 继承顺序：king
t.birth("king", "andy")  # 继承顺序：king > andy
t.birth("king", "bob")  # 继承顺序：king > andy > bob
t.birth("king", "catherine")  # 继承顺序：king > andy > bob > catherine
t.birth("andy", "matthew")  # 继承顺序：king > andy > matthew > bob > catherine
t.birth("bob", "alex")  # 继承顺序：king > andy > matthew > bob > alex > catherine
t.birth("bob", "asha")  # 继承顺序：king > andy > matthew > bob > alex > asha > catherine
print(t.getInheritanceOrder())  # 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob")  # 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
print(t.getInheritanceOrder())  # 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
