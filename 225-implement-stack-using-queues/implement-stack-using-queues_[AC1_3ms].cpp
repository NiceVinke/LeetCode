// Implement the following operations of a stack using queues.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// empty() -- Return whether the stack is empty.
//
//
// Notes:
//
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
//
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and all test cases.


class MyStack {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack()
    {

    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);
        int n = q.size();
        while (--n) {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ans = q.front();
        q.pop();
        return ans;
    }

    /** Get the top element. */
    int top() const
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() const
    {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
