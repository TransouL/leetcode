# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self) -> str:
        if not self.left and not self.right:
            return '%d ()' % self.val
        return '%d (%s, %s)' % (self.val, self.left, self.right)


class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        value_dict = {}

        def dfs(index: int, node: TreeNode) -> None:
            value_dict[index] = node.val
            if node.left is not None:
                dfs(index * 2 + 1, node.left)
            if node.right is not None:
                dfs(index * 2 + 2, node.right)

        dfs(0, root)
        return " ".join(str(key) + ':' + str(value) for key, value in value_dict.items())

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        node_list = data.split(" ")
        value_dict = {}
        for node in node_list:
            entry = node.split(':')
            value_dict[int(entry[0])] = int(entry[1])
        deserialized_root = TreeNode(value_dict[0])

        def dfs(index: int, node: TreeNode) -> None:
            if index * 2 + 1 in value_dict:
                node.left = TreeNode(value_dict[index * 2 + 1])
                dfs(index * 2 + 1, node.left)
            if index * 2 + 2 in value_dict:
                node.right = TreeNode(value_dict[index * 2 + 2])
                dfs(index * 2 + 2, node.right)

        dfs(0, deserialized_root)
        return deserialized_root


root = TreeNode(1, TreeNode(2), TreeNode(3, TreeNode(4), TreeNode(5)))
# root = TreeNode(1, None, TreeNode(2, None, TreeNode(3, None, TreeNode(4, None, TreeNode(5, None, None)))))
ser = Codec()
deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
serialized = ser.serialize(root)
print(serialized)
ans = deser.deserialize(serialized)
print(ans)
