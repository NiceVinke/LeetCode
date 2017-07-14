// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
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
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.


class MinStack {
    vector<int> a;
    vector<int> min;
public:
    MinStack()
    {
        min.push_back(INT_MAX);
    }
    void push(int x)
    {
        a.push_back(x);
        min.push_back(std::min(x, min.back()));
    }

    void pop()
    {
        a.pop_back();
        min.pop_back();
    }

    int top() const
    {
        return a.back();
    }

    int getMin() const
    {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
