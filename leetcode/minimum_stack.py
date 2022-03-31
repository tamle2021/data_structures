'''
Design a stack that supports push, pop, top, and retrieving minimum element in constant time.

Implement MinStack class:
MinStack() initializes the stack object
void push(int val) pushes the element val onto the stack
void pop() removes the element on the top of the stack
int top() gets the top element of the stack
int getMin() retrieves the minimum element in stack

example 1:
input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

output:
[null,null,null,null,-3,null,0,-2]

explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
// return -3
minStack.getMin();
minStack.pop();
// return 0
minStack.top();
// return -2
minStack.getMin();

constraints:
-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

**** minimum stack ****

'''
class MinimumStack():
    def __init__(self):
        self.st = []

    def push(self,x: int) -> None:
        currentMin = self.getMinimum()
        if (currentMin == None or currentMin > x):
            currentMin = x

        self.st.append((x,currentMin))

    def pop(self):
        popElem = self.st.pop()
        return popElem[0]

    def top(self) -> int:
        if (self.st):
            return self.st[-1][0]
        else:
            None

    def getMinimum(self) -> int:
        if (self.st):
            return self.st[-1][1]
        else:
            None

print("**** minimum stack ****")
m = MinimumStack()
m.push(6)
m.push(-4)
m.push(11)
m.push(2)
m.push(35)

topElem = m.top()
print("top element: ",topElem)
minElem = m.getMinimum()
print(f"min element: {minElem}")
popElem = m.pop()
print(f"pop element: {popElem}")

topElem = m.top()
print("top element: ",topElem)
minElem = m.getMinimum()
print("min element: {0}".format(minElem))

