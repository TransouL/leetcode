//import java.util.List;
//
//// This is the interface that allows for creating nested lists.
//// You should not implement it, or speculate about its implementation
//public interface NestedInteger {
//
//    // @return true if this NestedInteger holds a single integer, rather than a nested list.
//    public boolean isInteger();
//
//    // @return the single integer that this NestedInteger holds, if it holds a single integer
//    // Return null if this NestedInteger holds a nested list
//    public Integer getInteger();
//
//    // @return the nested list that this NestedInteger holds, if it holds a nested list
//    // Return null if this NestedInteger holds a single integer
//    public List<NestedInteger> getList();
//}

import java.util.*;

public class NestedIterator implements Iterator<Integer> {
	// 存储迭代器栈。每一层list遍历到哪个位置，由各自的迭代器来维护
	private Deque<Iterator<NestedInteger>> stack;

	public NestedIterator(List<NestedInteger> nestedList) {
		stack = new LinkedList<>();
		stack.push(nestedList.iterator());
	}

	@Override
	public Integer next() {
		return stack.peek().next().getInteger();
	}

	@Override
	public boolean hasNext() {
		while (!stack.isEmpty()) {
			Iterator<NestedInteger> it = stack.peek();
			if (!it.hasNext()) {
				stack.pop();
				continue;
			}
			NestedInteger next = it.next();
			// 如果下一个是数字，通过创建一个额外的列表将该数字放入，并将该列表的迭代器入栈 -> 把取出的数重新放回
			if (next.isInteger()) {
				List<NestedInteger> list = new ArrayList<>(1);
				list.add(next);
				stack.push(list.iterator());
				return true;
			}
			stack.push(next.getList().iterator());
		}
		return false;
	}
}
