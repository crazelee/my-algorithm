#include <iostream>
#include <stack>

using namespace std;

class ReverseStack
{
public:
    static int getAndRemoveLastElem(stack<int>* s){
        int result = s->top();
        s->pop();
        if (s->empty())
        {
            return result;
        } else {
            int last = ReverseStack::getAndRemoveLastElem(s);
            s->push(result);
            return last;
        }
    }

    static void reverse(stack<int>* s){
        if (s->empty())
        {
            return ;
        }

        int i = getAndRemoveLastElem(s);
        ReverseStack::reverse(s);
        s->push(i);
    }
};

int main(int argc, char const *argv[])
{
    stack<int>* s = new stack<int>;
    s->push(1);
    s->push(2);
    s->push(3);
    ReverseStack::reverse(s);
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->pop();
    return 0;
}