import java.util.Stack;

class MyQueue {
    Stack<Integer> inStack;
    Stack<Integer> outStack;

    /** Initialize your data structure here. */
    public MyQueue() {
        inStack = new Stack<>();
        outStack = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (outStack.isEmpty()) {
            transfor();
        }
        return outStack.pop();
    }

    private void transfor() {
        while (!inStack.empty()) {
            outStack.push(inStack.pop());
        }
    }

    /** Get the front element. */
    public int peek() {
        if (outStack.isEmpty()) {
            transfor();
        }
        return outStack.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return inStack.isEmpty() && outStack.empty();
    }

//    @Override
//    public String toString() {
//        return "MyQueue{" +
//                "inStack=" + inStack +
//                ", outStack=" + outStack +
//                '}';
//    }

    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue obj = new MyQueue();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.peek();
     * boolean param_4 = obj.empty();
     */

//    public static void main(String[] args) {
//        MyQueue myQueue = new MyQueue();
//        myQueue.push(1); // queue is: [1]
//        System.out.println("myQueue = " + myQueue);
//        myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//        System.out.println("myQueue = " + myQueue);
//        System.out.println(myQueue.peek());// return 1
//        System.out.println(myQueue.pop()); // return 1
//        System.out.println("myQueue = " + myQueue); //queue is [2]
//        System.out.println(myQueue.empty()); // return false
//    }
}
