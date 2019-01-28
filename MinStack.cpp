#include <iostream>
#include <stack>
using namespace std;

/**
 * 带有获取最小值的栈
 */
class MinStack
{
private:
    stack<int>* stackData;
    stack<int>* stackMin;

public:
    MinStack() {
        stackData = new stack<int>;
        stackMin = new stack<int>;
    }

    ~MinStack() {
        delete stackData;
        delete stackMin;
    }

    void push(int newNum) {
        stackData->push(newNum);
        if (stackMin->empty() || newNum <= stackMin->top())
        {
            stackMin->push(newNum);
        }
    }

    void pop() {
        int popNum = stackData->top();
        stackData->pop();
        if (popNum <= stackMin->top())
        {
            stackMin->pop();
        }
    }

    int getMin() {
        return stackMin->top();
    }
};

int main(void)
{
    MinStack s;
    s.push(20);
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(13);
    s.push(5);
    cout << "min: " << s.getMin();
    cout << endl;

    cout << "after pop:" << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << "min: " << s.getMin();
    cout << endl;
    s.pop();
    s.pop();
    cout << "min: " << s.getMin();
    cout << endl;

    system("pause");
}