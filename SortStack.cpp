#include <iostream>
#include <stack>

using namespace std;

class SortStack
{
public:
    static stack<int>* sort(stack<int>* stackData){
        stack<int>* stackHelp = new stack<int>;

        while(!stackData->empty()){
            int dTop = stackData->top();
            stackData->pop();
            while(!stackHelp->empty() && dTop < stackHelp->top()){
                int hTop = stackHelp->top();
                stackHelp->pop();
                stackData->push(hTop);
            }
            stackHelp->push(dTop);
        }
        return stackHelp;
    }
};

int main(int argc, char const *argv[])
{
    stack<int>* s = new stack<int>;
    s->push(2);
    s->push(3);
    s->push(5);
    s->push(4);
    s->push(1);
    s = SortStack::sort(s);
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->pop();
    return 0;
}