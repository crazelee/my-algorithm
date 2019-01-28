#include <iostream>
#include <stack>

using namespace std;

/**
 * 两个栈构造成一个队列
 */
class QueueStack
{
private:
    stack<int>* stackIn;
    stack<int>* stackOut;

public:
    QueueStack(){
        stackIn = new stack<int>;
        stackOut = new stack<int>;
    };
    ~QueueStack(){
        delete stackIn;
        delete stackOut;
    };
    void push(int newNum){
        stackIn->push(newNum);
        return ;
    }
    int pop(){
        while(!stackIn->empty()){
            int top = stackIn->top();
            stackIn->pop();
            stackOut->push(top);
        }
        int out = stackOut->top();
        stackOut->pop();
        while(!stackOut->empty()){
            int top = stackOut->top();
            stackOut->pop();
            stackIn->push(top);
        }
        return out;
    }
};

int main(int argc, char const *argv[])
{
    QueueStack s;
    s.push(20);
    cout << s.pop() << endl;
    s.push(7);
    s.push(6);
    cout << s.pop() << endl;
    s.push(5);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(2);
    cout << s.pop() << endl;
    s.push(13);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    system("pause");
    return 0;
}